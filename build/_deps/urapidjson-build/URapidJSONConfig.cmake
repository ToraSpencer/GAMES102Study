message(STATUS "config URapidJSON 0.0.3...")


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was Config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)

####################################################################################


get_filename_component(include_dir "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
include_directories("${include_dir}")


include ( "${CMAKE_CURRENT_LIST_DIR}/URapidJSONTargets.cmake" )

message(STATUS "config URapidJSON 0.0.3 done")
