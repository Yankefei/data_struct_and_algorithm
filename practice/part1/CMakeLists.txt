#set(CMAKE_CXX_COMPILER /usr/local/bin/g++)

project(part1)

include_directories(.)
include_directories(../../tools)
include_directories(../../sort)

add_executable(part1  main.cpp 1_1.cpp 1_2.cpp)
target_link_libraries(part1 sort)

add_executable(1_3  1_3.cpp)
add_executable(1_4  1_4.cpp)