set(CMAKE_CXX_COMPILER /usr/local/bin/g++)

project(sort)

include_directories(.)
include_directories(../tools)

add_library(sort  STATIC bubble_sort.cpp)
target_link_libraries(sort tools)



add_executable(main  main.cpp)
target_link_libraries(main sort)
