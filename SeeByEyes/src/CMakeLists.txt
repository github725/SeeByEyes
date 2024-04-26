
# 指定可执行文件的输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
# set(CMAKE_AUTOUIC ON)


file(GLOB_RECURSE UI_LIST  "ui_templates/*.cpp" "ui_templates/*.h")
file(GLOB_RECURSE QRC_FILE "resources.qrc")

qt5_add_resources( generated_qrc_list ${QRC_FILE} )
# 添加可执行文件
add_executable(SeeByEyes main.cpp mainwindow.h mainwindow.cpp SBEApp.h SBEApp.cpp ${UI_LIST} ${generated_qrc_list})



# 链接Qt5库
target_link_libraries(SeeByEyes Qt5::Core Qt5::Gui Qt5::Widgets)

# 链接PCL库
target_link_libraries(SeeByEyes ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES} ${PCL_VISUALIZATION_LIBRARIES})

# 链接GDAL库
target_link_libraries(SeeByEyes ${GDAL_LIBRARIES})

# 将qt动态库拷入生成目录 win


if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX "d")
    #if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        #set(DEBUG_SUFFIX "d")
    #endif ()
    # set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET SeeByEyes POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:SeeByEyes>/plugins/platforms/")
        add_custom_command(TARGET SeeByEyes POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:SeeByEyes>/plugins/platforms/")
    endif ()
    message("${DEBUG_SUFFIX}")
    foreach (QT_LIB Core Gui Widgets SQL Network)
        add_custom_command(TARGET SeeByEyes POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:SeeByEyes>")
                message("${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll")
    endforeach (QT_LIB)
endif ()