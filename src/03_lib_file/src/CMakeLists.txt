cmake_minimum_required(VERSION 3.10) #可写可不写,限制cmake版本

project(Test03LibFile VERSION 1.0)
option(LINK_SO "Whether examples are linked dynamically" OFF) #是否使用动态库链接

message(STATUS "开始编译 测试程序: ${PROJECT_VERSION} 源文件目录 ${CMAKE_CURRENT_SOURCE_DIR}")
#set设置c++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(OUTPUT_PATH_HOME ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH_HOME}/bin)

#引入编译好的库文件和头文件方式
set(CAL_MATH_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../cal_math/)
add_executable(test_03_libfile)
target_sources(test_03_libfile PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
#如果已经存在库文件一般用 find_library 拿到文件
if(LINK_SO)
    find_library(CAL_MATH_PATH NAMES cal_math PATHS ${CAL_MATH_BASE_DIR}/lib)
    message(STATUS "link so path result : ${CAL_MATH_PATH} ")
else()
    find_library(CAL_MATH_PATH NAMES libcal_math.a PATHS ${CAL_MATH_BASE_DIR}/lib)
    message(STATUS "not link so path result : ${CAL_MATH_PATH}")
endif()
target_link_libraries(test_03_libfile ${CAL_MATH_PATH})
target_include_directories(test_03_libfile PUBLIC ${CAL_MATH_BASE_DIR}/include)


