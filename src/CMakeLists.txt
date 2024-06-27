set(socketHandler_Dir ${CMAKE_CURRENT_SOURCE_DIR}/socketHandler)
set(utility_dir ${CMAKE_CURRENT_SOURCE_DIR}/utility)
set(ThreadPool_Dir ${CMAKE_CURRENT_SOURCE_DIR}/thread)
set(frame_Dir ${CMAKE_CURRENT_SOURCE_DIR}/frame)


add_subdirectory(${utility_dir})
add_subdirectory(${ThreadPool_Dir})
add_subdirectory(${socketHandler_Dir})
add_subdirectory(${frame_Dir})


add_executable(Server server.cpp)
add_executable(Client client.cpp)

target_include_directories(Server PUBLIC ${frame_Dir} ${utility_dir})
target_include_directories(Client PUBLIC ${socketHandler_Dir} ${utility_dir})

target_link_libraries(Server PUBLIC frame)
target_link_libraries(Client PUBLIC utility socketHandler)