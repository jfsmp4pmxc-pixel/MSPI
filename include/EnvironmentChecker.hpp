#ifndef ENVIRONMENT_CHECKER_HPP
#define ENVIRONMENT_CHECKER_HPP

#include <string>
#include <vector>

struct EnvironmentInfo {
    std::string osName;
    std::string osVersion;
    std::string cpuArchitecture;
    bool isCompatible;
};

class EnvironmentChecker {
public:
    EnvironmentChecker();
    ~EnvironmentChecker();

    EnvironmentInfo getSystemInfo() const;
    bool checkCompatibility() const;
    std::vector<std::string> getMissingDependencies() const;
};

#endif // ENVIRONMENT_CHECKER_HPP