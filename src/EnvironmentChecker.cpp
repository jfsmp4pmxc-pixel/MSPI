#include "EnvironmentChecker.hpp"
#include <sys/stat.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <vector>

namespace MSPlugIn {

EnvironmentChecker::EnvironmentChecker() {}
EnvironmentChecker::~EnvironmentChecker() {}

std::string EnvironmentChecker::detectDeviceModel() {
    struct utsname systemInfo;
    uname(&systemInfo);
    return std::string(systemInfo.machine);
}

std::string EnvironmentChecker::detectOSVersion() {
    struct utsname systemInfo;
    uname(&systemInfo);
    return std::string(systemInfo.release);
}

bool EnvironmentChecker::checkJailbreak() {
    const std::vector<std::string> jbPaths = {
        "/var/jb/usr/bin/libellekit.dylib",
        "/usr/lib/ellekit.dylib",
        "/Library/MobileSubstrate/MobileSubstrate.dylib",
        "/Applications/Sileo.app",
        "/Applications/Zebra.app"
    };

    struct stat buffer;
    for (const auto& path : jbPaths) {
        if (stat(path.c_str(), &buffer) == 0) {
            return true;
        }
    }
    
    FILE* file = fopen("/var/mobile/test_jb.txt", "w");
    if (file != nullptr) {
        fclose(file);
        remove("/var/mobile/test_jb.txt");
        return true;
    }

    return false;
}

bool EnvironmentChecker::checkTrollStoreSupport() {
    struct stat buffer;
    if (stat("/var/containers/Bundle/Application/", &buffer) == 0) {
        return true;
    }
    return false;
}

SystemInfo EnvironmentChecker::runDiagnostics() {
    SystemInfo info;
    info.deviceModel = detectDeviceModel();
    info.osVersion = detectOSVersion();

    if (checkJailbreak()) {
        info.envType = EnvironmentType::JAILBREAK_MODE;
        info.suggestedTool = "Sileo / Zebra Repo";
    } else if (checkTrollStoreSupport()) {
        info.envType = EnvironmentType::TROLLSTORE_MODE;
        info.suggestedTool = "TrollStore Direct Helper";
    } else {
        info.envType = EnvironmentType::DEMO_MODE;
        info.suggestedTool = "SideStore / AltStore / ESign";
    }

    return info;
}

} // namespace MSPlugIn
}
