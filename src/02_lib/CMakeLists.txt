cmake_minimum_required(VERSION 3.10) #可写可不写,限制cmake版本

project(Test02Lib VERSION 1.0)
#set设置变量
#set设置c++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(OUTPUT_PATH_HOME ${CMAKE_BINARY_DIR}/output)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATH_HOME}/bin)

file(GLOB TEST_02_LIB_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
message(STATUS "cal_math_lib库源文件: ${TEST_02_LIB_SRC}")
add_library(cal_math_lib STATIC ${TEST_02_LIB_SRC})
target_include_directories(cal_math_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


add_executable(test_02_lib main.cpp)
target_link_libraries(test_02_lib cal_math_lib)
message(STATUS "test_02_lib源文件地址: ${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(test_02_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)


