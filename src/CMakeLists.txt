set(Epoll_Dir ${CMAKE_CURRENT_SOURCE_DIR}/epoll)
set(utility_dir ${CMAKE_CURRENT_SOURCE_DIR}/utility)

add_subdirectory(${Epoll_Dir})
add_subdirectory(${utility_dir})