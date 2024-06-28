project(plugin
    DESCRIPTION "实现业务插件"
)

add_library(echo_plugin SHARED echo_plugin.cpp)
target_include_directories(echo_plugin PUBLIC ${engine_Dir} ${utility_Dir})

set_target_properties(echo_plugin PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
