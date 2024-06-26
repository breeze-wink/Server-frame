project(Epoll
    DESCRIPTION "围绕Epoll，对各种功能进行封装"
)

set(socket_Dir ${CMAKE_CURRENT_SOURCE_DIR}/Socket)
set(event_poller_dir ${CMAKE_CURRENT_SOURCE_DIR}/EventPoller)
set(socketHandler_Dir ${PROJECT_SOURCE_DIR}/SocketHandler)

add_subdirectory(${socket_Dir})
add_subdirectory(${socketHandler_Dir})
add_subdirectory(${event_poller_dir})


set(library_list socketHandler event_poller socket utility)

add_executable(Client client.cpp)
add_executable(Server server.cpp)

target_include_directories(Client PUBLIC ${socket_Dir})
target_include_directories(Server PUBLIC ${socketHandler_Dir})

target_link_libraries(Client ${library_list})
target_link_libraries(Server ${library_list})
