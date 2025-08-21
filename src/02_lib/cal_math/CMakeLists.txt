cmake_minimum_required(VERSION 3.10) #可写可不写,限制cmake版本

project(Test02LibCalMath VERSION 1.0)

message(STATUS "开始编译 cal_math 库: ${PROJECT_VERSION} 源文件目录 ${CMAKE_CURRENT_SOURCE_DIR}")
#set设置c++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CURR_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
#添加静态库
message(STATUS "cal_math_static 库源文件: ${SRC_FILES}")
add_library(cal_math_static STATIC ${SRC_FILES})
target_include_directories(cal_math_static PUBLIC ${CURR_INCLUDE_DIR})
#重命名
SET_TARGET_PROPERTIES(cal_math_static PROPERTIES OUTPUT_NAME cal_math CLEAN_DIRECT_OUTPUT 1)

#添加动态库
add_library(cal_math_shared SHARED ${SRC_FILES})
target_include_directories(cal_math_shared PUBLIC ${CURR_INCLUDE_DIR})
#重命名
SET_TARGET_PROPERTIES(cal_math_shared PROPERTIES OUTPUT_NAME cal_math CLEAN_DIRECT_OUTPUT 1)

# 安装规则（发布到系统目录）执行cmake --install ./ 进行发布
# install其实就是拷贝文件
#[[
install(TARGETS cal_math_static cal_math_shared
        ARCHIVE DESTINATION ${CMAKE_BINARY_DIR}/install/lib     # 静态库安装路径
        LIBRARY DESTINATION ${CMAKE_BINARY_DIR}/install/lib      # 动态库安装路径
        RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/install/bin)     # 可执行文件
 安装头文件
file(GLOB INCLUDE_FILES "${CURR_INCLUDE_DIR}/*.h")
install(FILES ${INCLUDE_FILES} DESTINATION ${CMAKE_BINARY_DIR}/install/include)
]]

