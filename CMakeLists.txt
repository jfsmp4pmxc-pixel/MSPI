cmake_minimum_required(VERSION 3.15)
project(MSPI LANGUAGES CXX)

option(BUILD_APP "Build the Objective-C++ App executable" OFF)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Library: EnvironmentChecker (C++)
add_library(EnvironmentChecker STATIC src/EnvironmentChecker.cpp)
target_include_directories(EnvironmentChecker PUBLIC ${CMAKE_SOURCE_DIR}/include)
set_target_properties(EnvironmentChecker PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)

# Optional App executable (Objective-C++). Disabled by default because building iOS UI on CI is platform-specific.
if(BUILD_APP)
  enable_language(OBJCXX)
  add_executable(MSPIApp src/main.mm src/MainViewController.mm)
  target_link_libraries(MSPIApp PRIVATE EnvironmentChecker)
  # For iOS builds you would link UIKit/Foundation frameworks; leave platform-specific details to the user.
endif()
