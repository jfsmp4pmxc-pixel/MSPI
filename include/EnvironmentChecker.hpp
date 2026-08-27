#pragma once
#include <string>

namespace MSPlugIn {

enum class EnvironmentType {
    DEMO_MODE,          // iOS Thuần / Sideload Phổ thông
    TROLLSTORE_MODE,    // Hỗ trợ TrollStore / Direct Container
    JAILBREAK_MODE      // Jailbreak (ElleKit / Substrate)
};

struct SystemInfo {
    std::string osVersion;
    std::string deviceModel;
    EnvironmentType envType;
    std::string suggestedTool;
};

class EnvironmentChecker {
public:
    EnvironmentChecker();
    ~EnvironmentChecker();

    SystemInfo runDiagnostics();

private:
    bool checkJailbreak();
    bool checkTrollStoreSupport();
    std::string detectOSVersion();
    std::string detectDeviceModel();
};
// namespace MSPlugIn
