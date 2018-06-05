project(threadPool)

set(CMAKE_CXX_FLAGS "-g -std=c++11")

add_executable(main thread_pool.cc main.cc )
target_link_libraries(main pthread)