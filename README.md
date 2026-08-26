# MSPI

MSPI là một kho mẫu nhỏ chứa cấu trúc cho một plugin/ứng dụng kết hợp C++ và Objective-C++.

Mục tiêu:
- Cấu trúc dự án có sẵn cho phần core kiểm tra môi trường (EnvironmentChecker) viết bằng C++.
- Chứa các file Objective-C++ placeholder cho phần giao diện/native iOS.
- Workflow GitHub Actions để build các thành phần C++ bằng CMake (macOS runner).

Lưu ý:
- Các kiểm tra jailbreak / TrollStore trong mã này chỉ là placeholder — không thực hiện kiểm tra thực tế.
- Nếu bạn định triển khai tính năng phát hiện môi trường thật, hãy đảm bảo tuân thủ các chính sách App Store và pháp luật liên quan.

Cách build (local):

1. Cài đặt CMake >= 3.15
2. Tạo thư mục build và chạy:
   cmake -S . -B build
   cmake --build build --config Release

Để xây dựng cả App (Objective-C++) (tùy nền tảng), bật option BUILD_APP trong CMake:
   cmake -S . -B build -DBUILD_APP=ON

