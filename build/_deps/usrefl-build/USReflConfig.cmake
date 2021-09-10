message(STATUS "config USRefl 0.7.1 ...")


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was Config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)

####################################################################################


get_filename_component(include_dir "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
include_directories("${include_dir}")

if(NOT FetchContent_FOUND)
  include(FetchContent)
endif()
if(NOT UCMake_FOUND)
  message(STATUS "find package: UCMake 0.6.3")
  find_package(UCMake 0.6.3 EXACT QUIET)
  if(NOT UCMake_FOUND)
    set(_Ubpa_UCMake_address "https://github.com/Ubpa/UCMake")
    message(STATUS "UCMake 0.6.3 not found")
    message(STATUS "fetch: ${_Ubpa_UCMake_address} with tag ${UCMake_VERSION}")
    FetchContent_Declare(
      UCMake
      GIT_REPOSITORY ${_Ubpa_UCMake_address}
      GIT_TAG 0.6.3
    )
    FetchContent_MakeAvailable(UCMake)
    message(STATUS "UCMake 0.6.3 build done")
  endif()
endif()
Ubpa_AddDepPro(USRefl UANTLR 0.2.0)


if(TRUE)
  include("${CMAKE_CURRENT_LIST_DIR}/UbpaUSReflAutoRefl.cmake")
endif()

if(NOT OFF)
  CPMAddPackage(
    NAME nameof
    GITHUB_REPOSITORY Neargye/nameof
    GIT_TAG 0e8bec0
  )
endif()

include("${CMAKE_CURRENT_LIST_DIR}/USReflTargets.cmake")

message(STATUS "config USRefl 0.7.1 done")
