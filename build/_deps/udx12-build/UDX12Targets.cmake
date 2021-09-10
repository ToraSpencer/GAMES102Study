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

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget Ubpa::UDX12_core)
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


# Create imported target Ubpa::UDX12_core
add_library(Ubpa::UDX12_core STATIC IMPORTED)

set_target_properties(Ubpa::UDX12_core PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "UNICODE;_UNICODE;NOMINMAX"
  INTERFACE_INCLUDE_DIRECTORIES "G:/gitRepositories/GAMES102Study/build/_deps/udx12-src/include"
  INTERFACE_LINK_LIBRARIES "Ubpa::UContainer_core;Ubpa::UTemplate_core;Ubpa::UFG_core;d3dcompiler.lib;D3D12.lib;dxgi.lib;dxguid.lib"
)

# Import target "Ubpa::UDX12_core" for configuration "Debug"
set_property(TARGET Ubpa::UDX12_core APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Ubpa::UDX12_core PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "G:/gitRepositories/GAMES102Study/build/_deps/udx12-src/lib/UDX12_cored.lib"
  )

# Import target "Ubpa::UDX12_core" for configuration "Release"
set_property(TARGET Ubpa::UDX12_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Ubpa::UDX12_core PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "G:/gitRepositories/GAMES102Study/build/_deps/udx12-src/lib/UDX12_core.lib"
  )

# Import target "Ubpa::UDX12_core" for configuration "MinSizeRel"
set_property(TARGET Ubpa::UDX12_core APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(Ubpa::UDX12_core PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "G:/gitRepositories/GAMES102Study/build/_deps/udx12-src/lib/MinSizeRel/UDX12_core.lib"
  )

# Import target "Ubpa::UDX12_core" for configuration "RelWithDebInfo"
set_property(TARGET Ubpa::UDX12_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Ubpa::UDX12_core PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "G:/gitRepositories/GAMES102Study/build/_deps/udx12-src/lib/RelWithDebInfo/UDX12_core.lib"
  )

# Make sure the targets which have been exported in some other
# export set exist.
unset(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)
foreach(_target "Ubpa::UContainer_core" "Ubpa::UTemplate_core" "Ubpa::UFG_core" )
  if(NOT TARGET "${_target}" )
    set(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets "${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets} ${_target}")
  endif()
endforeach()

if(DEFINED ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)
  if(CMAKE_FIND_PACKAGE_NAME)
    set( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
    set( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "The following imported targets are referenced, but are missing: ${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets}")
  else()
    message(FATAL_ERROR "The following imported targets are referenced, but are missing: ${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets}")
  endif()
endif()
unset(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)