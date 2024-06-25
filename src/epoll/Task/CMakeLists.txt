project(Task
    DESCRIPTION "对服务端业务处理的封装"
)

aux_source_directory(. DIR_SRC)
add_library(${PROJECT_NAME} STATIC ${DIR_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${socket_Dir} ${utility_dir})