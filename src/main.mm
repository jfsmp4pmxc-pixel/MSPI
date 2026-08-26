// App entry point (Objective-C++ placeholder)
// Đây không phải là một App iOS hoàn chỉnh. Nó chỉ in thông báo khi chạy như một binary trên macOS.

#include <iostream>
#include "../include/EnvironmentChecker.hpp"

int main(int argc, char *argv[]) {
    std::cout << "MSPI placeholder app starting..." << std::endl;

    std::string checks = EnvironmentChecker::runChecks();
    std::cout << checks << std::endl;

    // Nếu cần, có thể tạo và sử dụng MainViewController ở đây (Objective-C++).
    // MainViewController *vc = [[MainViewController alloc] init];
    // [vc start];

    return 0;
}
