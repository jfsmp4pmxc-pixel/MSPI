cmake_minimum_required(VERSION 3.15)
project(MSPlugIn CXX OBJCXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

find_library(UIKIT_KIT UIKit)
find_library(FOUNDATION_KIT Foundation)

# Đánh dấu MACOSX_BUNDLE để CMake tạo cấu trúc App (.app) thay vì file binary đơn thuần
add_executable(MSPlugIn MACOSX_BUNDLE
    src/EnvironmentChecker.cpp
    src/MainViewController.mm
    src/main.mm
)

target_link_libraries(MSPlugIn
    ${UIKIT_KIT}
    ${FOUNDATION_KIT}
)

# Thiết lập Bundle ID và tắt Code Sign tự động để build thủ công không cần cert
set_target_properties(MSPlugIn PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.msplugin.app"
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER "com.msplugin.app"
    XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED "NO"
    XCODE_ATTRIBUTE_CODE_SIGNING_REQUIRED "NO"
    XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ""
)