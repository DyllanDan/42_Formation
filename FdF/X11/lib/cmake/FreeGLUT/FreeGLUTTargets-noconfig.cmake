#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "FreeGLUT::freeglut" for configuration ""
set_property(TARGET FreeGLUT::freeglut APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(FreeGLUT::freeglut PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libglut.3.12.0.dylib"
  IMPORTED_SONAME_NOCONFIG "/opt/X11/lib/libglut.3.dylib"
  )

list(APPEND _cmake_import_check_targets FreeGLUT::freeglut )
list(APPEND _cmake_import_check_files_for_FreeGLUT::freeglut "${_IMPORT_PREFIX}/lib/libglut.3.12.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
