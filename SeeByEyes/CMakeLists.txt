cmake_minimum_required(VERSION 3.5)
project(SeeByEyesProjects)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找Qt5包
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets )


# 添加PCL包
find_package(PCL 1.12.1 REQUIRED COMPONENTS common io visualization)

# 添加GDAL包
find_package(GDAL REQUIRED)


# 添加源码目录
add_subdirectory(src)

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

# 添加Qt5头文件
include_directories(${Qt5Widgets_INCLUDE_DIRS})


