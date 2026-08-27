// 1. Thư viện chuẩn & thư viện ngoài (luôn để ngoài namespace)
#include <iostream>
#include <string>
#include <vector>

// 2. Header của dự án
#include "EnvironmentChecker.hpp"

namespace MSPlugIn {

EnvironmentChecker::EnvironmentChecker() {
    // Khởi tạo danh sách phụ thuộc mẫu
    m_requiredDependencies = {
        "CoreFoundation",
        "SystemConfiguration"
    };
}

EnvironmentChecker::~EnvironmentChecker() {
}

EnvironmentInfo EnvironmentChecker::getSystemInfo() const {
    EnvironmentInfo info;
    
#if defined(__APPLE__)
    info.osName = "macOS / iOS";
#elif defined(__linux__)
    info.osName = "Linux";
#elif defined(_WIN32)
    info.osName = "Windows";
#else
    info.osName = "Unknown OS";
#endif

#if defined(__x86_64__) || defined(_M_X64)
    info.cpuArchitecture = "x86_64";
#elif defined(__i386__) || defined(_M_IX86)
    info.cpuArchitecture = "i686";
#elif defined(__arm64__) || defined(__aarch64__)
    info.cpuArchitecture = "ARM64";
#elif defined(__arm__) || defined(_M_ARM)
    info.cpuArchitecture = "ARM32";
#else
    info.cpuArchitecture = "Unknown Arch";
#endif

    info.osVersion = "1.0.0";
    info.isCompatible = checkCompatibility();

    return info;
}

bool EnvironmentChecker::checkCompatibility() const {
    // Logic kiểm tra độ tương thích đơn giản
    return true;
}

std::vector<std::string> EnvironmentChecker::getMissingDependencies() const {
    std::vector<std::string> missing;
    
    // Ví dụ kiểm tra dependency
    for (const auto& dep : m_requiredDependencies) {
        // Giả lập kiểm tra, thêm vào missing nếu thiếu
        (void)dep;
    }

    return missing;
}

} // namespace MSPlugIn
