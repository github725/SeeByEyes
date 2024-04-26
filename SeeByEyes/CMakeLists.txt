cmake_minimum_required(VERSION 3.5)
project(SeeByEyesProjects)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
list( APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/" )
# # 查找Qt5包
# find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets OpenGL)

include( CMakePolicies )

include( DeployQt )
set( CMAKE_DEBUG_POSTFIX "d" )

# 添加PCL包
find_package(PCL REQUIRED COMPONENTS common io visualization)

# 添加GDAL包
find_package(GDAL REQUIRED)

include( CMakeInclude )
include( Install )

include( CMakeExternalLibs )
# 添加源码目录
add_subdirectory(src)


#添加lib库目录
add_subdirectory(libs)

# 添加头文件目录
include_directories(
    include
    ${PCL_INCLUDE_DIRS}
    ${GDAL_INCLUDE_DIRS}
)

# 添加第三方库目录
link_directories(
    ${PCL_LIBRARY_DIRS}
)
message("----------------------------------------------${QT5_DIR}")
# # 添加Qt5头文件
# include_directories(${Qt5Widgets_INCLUDE_DIRS})


