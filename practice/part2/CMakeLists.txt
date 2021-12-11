#set(CMAKE_CXX_COMPILER /usr/local/bin/g++)

project(part2)

include_directories(.)
include_directories(../../tools)
# include_directories(../../sort)

add_executable(2_6   2_6.cpp)
target_link_libraries(2_6 tools)

add_executable(2_7   2_7.cpp)
target_link_libraries(2_7 tools)

add_executable(2_9   2_9.cpp)
target_link_libraries(2_9 tools)