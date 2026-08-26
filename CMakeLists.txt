cmake_minimum_required(VERSION 3.15)
project(MSPlugIn CXX OBJCXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

find_library(UIKIT_KIT UIKit)
find_library(FOUNDATION_KIT Foundation)

add_executable(MSPlugIn
    src/EnvironmentChecker.cpp
    src/MainViewController.mm
    src/main.mm
)

target_link_libraries(MSPlugIn
    ${UIKIT_KIT}
    ${FOUNDATION_KIT}
)

