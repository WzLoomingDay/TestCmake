
cmake_minimum_required(VERSION 3.10) #可写可不写,限制cmake版本

project(Test01Add VERSION 1.0)

# add the executable
add_executable(test_01_add main.cpp add.cpp)
