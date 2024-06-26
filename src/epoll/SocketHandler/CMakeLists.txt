project(socketHandler
    DESCRIPTION "将封装的Task和EventPoller运用起来，进行一个封装"
)

aux_source_directory(. DIR_SRC)
add_library(${PROJECT_NAME} STATIC ${DIR_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${socket_Dir} ${event_poller_dir} ${utility_dir} ${ThreadPool_Dir})
target_link_libraries(${PROJECT_NAME} PUBLIC ThreadPool)
