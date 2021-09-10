# Install script for directory: G:/gitRepositories/GAMES102Study/build/_deps/usrefl-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/Ubpa")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/uantlr-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/src/AutoRefl/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/src/EMPTY/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/src/core/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/src/test/00_basic/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/src/test/01_template/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/src/test/02_static/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/src/test/03_func/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/src/test/04_enum/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/src/test/05_inheritance/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/src/test/06_99/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/src/test/07_virtual/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/src/test/08_mask/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/src/test/09_AutoRefl/00_basic/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/cmake/InitUCMake.cmake;/cmake/UbpaUSReflAutoRefl.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/cmake" TYPE FILE FILES
    "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-src/cmake/InitUCMake.cmake"
    "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-src/cmake/UbpaUSReflAutoRefl.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/USRefl_0_7_1/cmake/USReflTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/USRefl_0_7_1/cmake/USReflTargets.cmake"
         "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/CMakeFiles/Export/USRefl_0_7_1/cmake/USReflTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/USRefl_0_7_1/cmake/USReflTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/USRefl_0_7_1/cmake/USReflTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/USRefl_0_7_1/cmake" TYPE FILE FILES "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/CMakeFiles/Export/USRefl_0_7_1/cmake/USReflTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/USRefl_0_7_1/cmake" TYPE FILE FILES "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/CMakeFiles/Export/USRefl_0_7_1/cmake/USReflTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/USRefl_0_7_1/cmake" TYPE FILE FILES "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/CMakeFiles/Export/USRefl_0_7_1/cmake/USReflTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/USRefl_0_7_1/cmake" TYPE FILE FILES "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/CMakeFiles/Export/USRefl_0_7_1/cmake/USReflTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/USRefl_0_7_1/cmake" TYPE FILE FILES "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/CMakeFiles/Export/USRefl_0_7_1/cmake/USReflTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/USRefl_0_7_1/cmake" TYPE FILE FILES
    "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/USReflConfig.cmake"
    "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-build/USReflConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/USRefl_0_7_1" TYPE DIRECTORY FILES "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-src/include")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/USRefl_0_7_1" TYPE DIRECTORY FILES "G:/gitRepositories/GAMES102Study/build/_deps/usrefl-src/cmake")
endif()

