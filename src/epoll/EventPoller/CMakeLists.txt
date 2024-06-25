project(event_poller
    DESCRIPTION "对Epoll的功能进行封装"
)
aux_source_directory(. DIR_SRC)

add_library(${PROJECT_NAME} STATIC ${DIR_SRC})