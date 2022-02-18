set(CMAKE_CXX_COMPILER /usr/local/bin/g++)

project(greedy_question)

include_directories(../..)
include_directories(../../tools)


add_executable(greedy_question  greedy_question.cpp)
target_link_libraries(greedy_question tools)
