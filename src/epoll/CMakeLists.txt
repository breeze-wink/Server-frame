project(Epoll
    DESCRIPTION "对Epoll的功能进行封装"
)

set(socket_Dir ${CMAKE_CURRENT_SOURCE_DIR}/Socket)
set(event_poller_dir ${CMAKE_CURRENT_SOURCE_DIR}/EventPoller)
set(socketHandler_Dir ${PROJECT_SOURCE_DIR}/SocketHandler)
set(task_dir ${CMAKE_CURRENT_SOURCE_DIR}/Task)

add_subdirectory(${socket_Dir})
add_subdirectory(${socketHandler_Dir})
add_subdirectory(${event_poller_dir})
add_subdirectory(${task_dir})