cmake_minimum_required(VERSION 3.15)
project(MSPlugIn CXX OBJCXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

find_library(UIKIT_KIT UIKit)
find_library(FOUNDATION_KIT Foundation)

# Khai báo tạo iOS App Bundle (.app) thay vì file thực thi đơn thuần
add_executable(MSPlugIn MACOSX_BUNDLE
    src/EnvironmentChecker.cpp
    src/MainViewController.mm
    src/main.mm
)

target_link_libraries(MSPlugIn
    ${UIKIT_KIT}
    ${FOUNDATION_KIT}
)

# Thêm các thuộc tính bắt buộc cho iOS Target (Bundle ID & Code Sign Offset)
set_target_properties(MSPlugIn PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.msplugin.app"
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER "com.msplugin.app"
    XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED "NO"
    XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ""
)
)

