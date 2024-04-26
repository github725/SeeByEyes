project(SBE_DB_LIB)

add_library( ${PROJECT_NAME} SHARED )

add_subdirectory( include )
add_subdirectory( src )


target_compile_definitions( ${PROJECT_NAME} PRIVATE DB_LIBRARY_BUILD )
set_target_properties( ${PROJECT_NAME} PROPERTIES
	CXX_VISIBILITY_PRESET hidden
)
target_link_libraries(
	${PROJECT_NAME} Qt5::Core Qt5::Gui
)
InstallSharedLibrary( TARGET ${PROJECT_NAME} )
