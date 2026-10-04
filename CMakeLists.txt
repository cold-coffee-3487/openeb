cmake_minimum_required(VERSION 3.5)

project(metavision_sdk_get_started)

set(CMAKE_CXX_STANDARD 17)

# Link to MetavisionSDK
find_package(MetavisionSDK COMPONENTS core stream ui REQUIRED)

add_subdirectory(src)

add_executable(metavision_sdk_get_started apps/metavision_sdk_get_started.cpp)

# Crucial: Add src/ to include path for headers
target_include_directories(metavision_sdk_get_started
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(metavision_sdk_get_started
    event_analyzer_lib
    MetavisionSDK::core 
    MetavisionSDK::stream 
    MetavisionSDK::ui
    )