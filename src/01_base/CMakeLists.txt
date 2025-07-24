
cmake_minimum_required(VERSION 3.10) #可写可不写,限制cmake版本

project(Test01Add VERSION 1.0)

#set设置变量
set(TEST_01_ADD_SRC main.cpp add.cpp)
#set设置c++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable #{var}取值变量
add_executable(test_01_add ${TEST_01_ADD_SRC})


