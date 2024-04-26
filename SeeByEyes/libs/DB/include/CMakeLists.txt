target_sources(
    ${PROJECT_NAME}
	PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/db.h
	    ${CMAKE_CURRENT_LIST_DIR}/geom.h
        ${CMAKE_CURRENT_LIST_DIR}/linestring.h
		${CMAKE_CURRENT_LIST_DIR}/point3d.h
		${CMAKE_CURRENT_LIST_DIR}/polygon.h
		${CMAKE_CURRENT_LIST_DIR}/layer.h
		${CMAKE_CURRENT_LIST_DIR}/feature.h
		${CMAKE_CURRENT_LIST_DIR}/vectorlayer.h
		${CMAKE_CURRENT_LIST_DIR}/pointcloudlayer.h
		${CMAKE_CURRENT_LIST_DIR}/abstractgeom.h
		${CMAKE_CURRENT_LIST_DIR}/attributes.h
		${CMAKE_CURRENT_LIST_DIR}/fields.h
		${CMAKE_CURRENT_LIST_DIR}/box3d.h

)
target_include_directories( ${PROJECT_NAME}
	PUBLIC
	    ${CMAKE_CURRENT_LIST_DIR}
)

