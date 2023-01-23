#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "unofficial::lemon::lemon" for configuration "Release"
set_property(TARGET unofficial::lemon::lemon APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(unofficial::lemon::lemon PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/lemon.lib"
  )

list(APPEND _cmake_import_check_targets unofficial::lemon::lemon )
list(APPEND _cmake_import_check_files_for_unofficial::lemon::lemon "${_IMPORT_PREFIX}/lib/lemon.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
