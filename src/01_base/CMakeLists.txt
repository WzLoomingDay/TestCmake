
cmake_minimum_required(VERSION 3.10) #可写可不写,限制cmake版本

project(Test01Add VERSION 1.0)
message(STATUS "当前编译目录: ${CMAKE_BINARY_DIR}")
message(STATUS "当前源文件目录: ${CMAKE_CURRENT_SOURCE_DIR}")
#set设置变量
#set设置c++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(OUTPUT_PATH_HOME ${CMAKE_BINARY_DIR}/output)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATH_HOME}/bin)

#set(TEST_01_ADD_SRC main.cpp;add.cpp)
# 递归搜索src目录下所有.cpp文件
file(GLOB_RECURSE TEST_01_ADD_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
message(STATUS "源文件: ${TEST_01_ADD_SRC}")

# add the executable #{var}取值变量
add_executable(test_01_add ${TEST_01_ADD_SRC})

#头文件目录
target_include_directories(test_01_add PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)


