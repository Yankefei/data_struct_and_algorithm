set(CMAKE_CXX_COMPILER /usr/local/bin/g++)

project(range_question)

include_directories(../..)
include_directories(../../tools)


add_executable(range_question  range_question.cpp)
target_link_libraries(range_question tools)
