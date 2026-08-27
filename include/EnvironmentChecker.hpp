#ifndef ENVIRONMENT_CHECKER_HPP
#define ENVIRONMENT_CHECKER_HPP

#include <string>
#include <vector>

namespace MSPlugIn {

enum class EnvironmentType {
    UNKNOWN,
    JAILBREAK_MODE,
    TROLLSTORE_MODE,
    SANDBOX_MODE
};

struct SystemInfo {
    std::string osName;
    std::string osVersion;
    EnvironmentType envType;
};

class EnvironmentChecker {
public:
    EnvironmentChecker();
    ~EnvironmentChecker();

    SystemInfo runDiagnostics() const;
    bool checkCompatibility() const;
};

} // namespace MSPlugIn

#endif // ENVIRONMENT_CHECKER_HPP