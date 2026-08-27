#include <iostream>
#include "EnvironmentChecker.hpp"

int main() {
    EnvironmentChecker checker;
    EnvironmentInfo info = checker.getSystemInfo();

    std::cout << "OS Name: " << info.osName << std::endl;
    std::cout << "OS Version: " << info.osVersion << std::endl;
    std::cout << "Architecture: " << info.cpuArchitecture << std::endl;

    if (checker.checkCompatibility()) {
        std::cout << "Moi truong tuong thich!" << std::endl;
    } else {
        std::cout << "Moi truong khong tuong thich!" << std::endl;
    }

    return 0;
}
