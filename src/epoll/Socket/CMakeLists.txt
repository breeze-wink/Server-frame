project(socket
    DESCRIPTION "对socket进行封装，同时给服务端服务端和客户端得socket也进行简单的封装"
)

aux_source_directory(. DIR_SRC)
add_library(${PROJECT_NAME} STATIC ${DIR_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${utility_dir})