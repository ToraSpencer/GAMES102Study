# Install script for directory: G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-src

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
  include("G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-build/src/core/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-build/src/test/00_Pool/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-build/src/test/01_Algorithm/00_Set/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-build/src/test/02_VarSizeAllocMngr/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-build/src/test/03_Span/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UContainer_0_0_9/cmake/UContainerTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UContainer_0_0_9/cmake/UContainerTargets.cmake"
         "G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-build/CMakeFiles/Export/UContainer_0_0_9/cmake/UContainerTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UContainer_0_0_9/cmake/UContainerTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UContainer_0_0_9/cmake/UContainerTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UContainer_0_0_9/cmake" TYPE FILE FILES "G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-build/CMakeFiles/Export/UContainer_0_0_9/cmake/UContainerTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UContainer_0_0_9/cmake" TYPE FILE FILES "G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-build/CMakeFiles/Export/UContainer_0_0_9/cmake/UContainerTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UContainer_0_0_9/cmake" TYPE FILE FILES "G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-build/CMakeFiles/Export/UContainer_0_0_9/cmake/UContainerTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UContainer_0_0_9/cmake" TYPE FILE FILES "G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-build/CMakeFiles/Export/UContainer_0_0_9/cmake/UContainerTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UContainer_0_0_9/cmake" TYPE FILE FILES "G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-build/CMakeFiles/Export/UContainer_0_0_9/cmake/UContainerTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UContainer_0_0_9/cmake" TYPE FILE FILES
    "G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-build/UContainerConfig.cmake"
    "G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-build/UContainerConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UContainer_0_0_9" TYPE DIRECTORY FILES "G:/gitRepositories/GAMES102Study/build/_deps/ucontainer-src/include")
endif()

