set(Epoll_Dir ${CMAKE_CURRENT_SOURCE_DIR}/epoll)
set(utility_dir ${CMAKE_CURRENT_SOURCE_DIR}/utility)
set(ThreadPool_Dir ${CMAKE_CURRENT_SOURCE_DIR}/thread)

add_subdirectory(${utility_dir})
add_subdirectory(${ThreadPool_Dir})
add_subdirectory(${Epoll_Dir})



