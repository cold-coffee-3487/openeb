# Create a library target for internal logic
add_library(event_analyzer_lib
    EventAnalyzer.cpp
    EventAnalyzer.hpp
)

# Export include directory automatically to dependent targets
target_include_directories(event_analyzer_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(event_analyzer_lib
    PUBLIC
        MetavisionSDK::core
)