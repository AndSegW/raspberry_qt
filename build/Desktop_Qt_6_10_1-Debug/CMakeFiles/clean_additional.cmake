# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appProva_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appProva_autogen.dir/ParseCache.txt"
  "appProva_autogen"
  )
endif()
