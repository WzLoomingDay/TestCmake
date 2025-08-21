cmake_minimum_required(VERSION 3.10) #可写可不写,限制cmake版本

project(Test02LibExample VERSION 1.0)
option(LINK_SO "Whether examples are linked dynamically" OFF) #是否使用动态库链接

message(STATUS "开始编译 测试程序: ${PROJECT_VERSION} 源文件目录 ${CMAKE_CURRENT_SOURCE_DIR}")
#set设置c++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(OUTPUT_PATH_HOME ${CMAKE_BINARY_DIR}/output)
set(OUTPUT_LIB_DIRECTORY ${OUTPUT_PATH_HOME}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH_HOME}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_LIB_DIRECTORY}) # 静态库
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_LIB_DIRECTORY}) # 动态库

#两种引入其他库的方法，一种是拿到源码进行编译,另一种是拿到已经编译好的静态库文件和头文件直接引用

# 第一种 直接编译源码方式
# 直接包含子目录的头文件和源码 缺点:需要知道每一个子目录如何构建并且全部包含
#[[
file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
set(CAL_MATH_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../cal_math/)
file(GLOB MATH_SRC_FILES "${CAL_MATH_BASE_DIR}/src/*.cpp")
#或者使用aux_source_directory收集某一目录下的所有文件
add_executable(test_02_lib main.cpp ${MATH_SRC_FILES})
target_include_directories(test_02_lib PUBLIC ${CAL_MATH_BASE_DIR}/include)
]]

# 第二种 引入库文件和头文件方式
set(CAL_MATH_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../cal_math/)
#引入子目录,第一个参数是子目录目录下有CMakeLists.txt,第二个参数是产出的base目录
add_subdirectory(${CAL_MATH_BASE_DIR} ${CMAKE_BINARY_DIR}/cal_math)
add_executable(test_02_lib)
target_sources(test_02_lib PUBLIC main.cpp)

target_link_directories(test_02_lib PUBLIC  ${OUTPUT_LIB_DIRECTORY})
set(CAL_MATH_LIB_PATH ${OUTPUT_LIB_DIRECTORY}/libcal_math.a)
target_link_libraries(test_02_lib ${CAL_MATH_LIB_PATH})

#依赖lib库先产出
add_dependencies(test_02_lib cal_math_static)
add_dependencies(test_02_lib cal_math_shared)
target_include_directories(test_02_lib PUBLIC ${CAL_MATH_BASE_DIR}/include)

#[[
#find_library(MY_LIBRARY_PATH NAMES mylibrary PATHS /xxx/libs NO_DEFAULT_PATH)
#PATHS /xxx/libs 指定搜索路径 NO_DEFAULT_PATH表示不用系统默认路径
#返回值会存储变量 <VAR>_FOUND eg MY_LIBRARY_PATH_FOUND 来确认是否找到
#链接库到目标
if(LINK_SO)
    find_library(CAL_MATH_PATH NAMES libcal_math)
else()
    find_library(CAL_MATH_PATH NAMES libcal_math.a)
endif()
if(NOT CAL_MATH_LIB_FOUND)
    message(FATAL_ERROR "libcal_math not found, test error")
endif()
message(STATUS "Found calmath library: ${CAL_MATH_PATH}")
]]


