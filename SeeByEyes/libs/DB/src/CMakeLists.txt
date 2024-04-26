target_sources(
    ${PROJECT_NAME}
	PRIVATE
	    ${CMAKE_CURRENT_LIST_DIR}/geom.cpp
		${CMAKE_CURRENT_LIST_DIR}/linestring.cpp
		${CMAKE_CURRENT_LIST_DIR}/point3d.cpp
		${CMAKE_CURRENT_LIST_DIR}/polygon.cpp
		${CMAKE_CURRENT_LIST_DIR}/layer.cpp
		${CMAKE_CURRENT_LIST_DIR}/feature.cpp
		${CMAKE_CURRENT_LIST_DIR}/abstractgeom.cpp
		${CMAKE_CURRENT_LIST_DIR}/pointcloudlayer.cpp
		${CMAKE_CURRENT_LIST_DIR}/vectorlayer.cpp
		${CMAKE_CURRENT_LIST_DIR}/attributes.cpp
		${CMAKE_CURRENT_LIST_DIR}/fields.cpp
		${CMAKE_CURRENT_LIST_DIR}/box3d.cpp
		
)