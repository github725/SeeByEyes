# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "libs/DB/CMakeFiles/SBE_DB_LIB_autogen.dir/AutogenUsed.txt"
  "libs/DB/CMakeFiles/SBE_DB_LIB_autogen.dir/ParseCache.txt"
  "libs/DB/SBE_DB_LIB_autogen"
  "src/CMakeFiles/SeeByEyes_autogen.dir/AutogenUsed.txt"
  "src/CMakeFiles/SeeByEyes_autogen.dir/ParseCache.txt"
  "src/SeeByEyes_autogen"
  )
endif()
