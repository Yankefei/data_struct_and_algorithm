set(CMAKE_CXX_COMPILER /usr/local/bin/g++)

project(recursive)

include_directories(../..)
include_directories(../../tools)


add_executable(divide_and_conquer  divide_and_conquer.cpp)
target_link_libraries(divide_and_conquer tools)

add_executable(dynamic_programming  dynamic_programming.cpp)
target_link_libraries(dynamic_programming tools)