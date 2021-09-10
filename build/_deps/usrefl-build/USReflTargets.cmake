# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.19)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget Ubpa::USRefl_AutoRefl Ubpa::USRefl_core)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target Ubpa::USRefl_AutoRefl
add_executable(Ubpa::USRefl_AutoRefl IMPORTED)

set_target_properties(Ubpa::USRefl_AutoRefl PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-src/include"
)

# Create imported target Ubpa::USRefl_core
add_library(Ubpa::USRefl_core INTERFACE IMPORTED)

set_target_properties(Ubpa::USRefl_core PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "UBPA_USREFL_NOT_USE_NAMEOF"
  INTERFACE_COMPILE_OPTIONS "/wd5030"
  INTERFACE_INCLUDE_DIRECTORIES "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-src/include"
)

# Import target "Ubpa::USRefl_AutoRefl" for configuration "Debug"
set_property(TARGET Ubpa::USRefl_AutoRefl APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Ubpa::USRefl_AutoRefl PROPERTIES
  IMPORTED_LOCATION_DEBUG "G:/gitRepositories/GAMES102Study/bin/AutoRefld.exe"
  )

# Import target "Ubpa::USRefl_AutoRefl" for configuration "Release"
set_property(TARGET Ubpa::USRefl_AutoRefl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Ubpa::USRefl_AutoRefl PROPERTIES
  IMPORTED_LOCATION_RELEASE "G:/gitRepositories/GAMES102Study/bin/AutoRefl.exe"
  )

# Import target "Ubpa::USRefl_AutoRefl" for configuration "MinSizeRel"
set_property(TARGET Ubpa::USRefl_AutoRefl APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(Ubpa::USRefl_AutoRefl PROPERTIES
  IMPORTED_LOCATION_MINSIZEREL "G:/gitRepositories/GAMES102Study/bin/MinSizeRel/AutoRefl.exe"
  )

# Import target "Ubpa::USRefl_AutoRefl" for configuration "RelWithDebInfo"
set_property(TARGET Ubpa::USRefl_AutoRefl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Ubpa::USRefl_AutoRefl PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "G:/gitRepositories/GAMES102Study/bin/RelWithDebInfo/AutoRefl.exe"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
