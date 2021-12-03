#set(CMAKE_CXX_COMPILER /usr/local/bin/g++)

project(part1)

include_directories(.)
include_directories(../../tools)
include_directories(../../sort)

add_executable(part1  main.cpp 1_1.cpp)
target_link_libraries(part1 sort)
