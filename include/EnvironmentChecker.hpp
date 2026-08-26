#pragma once

#include <string>

// EnvironmentChecker: Dynamic system check core
// - Đây là header mẫu (placeholder). Các hàm thực tế để kiểm tra jailbreak/TrollStore/tiền xử lý hệ thống
//   phải được triển khai cẩn thận và tuân thủ chính sách App Store / pháp lý khi cần.

class EnvironmentChecker {
public:
    // Kiểm tra xem thiết bị có nghi ngờ đã jailbreak hay không.
    // Trả về true nếu có dấu hiệu (placeholder).
    static bool isJailbroken();

    // Kiểm tra xem TrollStore (hoặc cửa hàng bên thứ ba tương tự) có được phát hiện hay không.
    static bool isTrollStoreInstalled();

    // Chạy tất cả các kiểm tra và trả về mô tả ngắn gọn của kết quả.
    static std::string runChecks();
};
