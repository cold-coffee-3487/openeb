
# Link to MetavisionSDK
find_package(MetavisionSDK COMPONENTS core stream ui REQUIRED)

set (sample metavision_sdk_get_started)

add_executable(${sample} 
    ${sample}.cpp)

target_link_libraries(${sample} 
    MetavisionSDK::core 
    MetavisionSDK::stream 
    MetavisionSDK::ui
    )