# Install script for directory: G:/gitRepositories/GAMES102Study/build/_deps/utemplate-src

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
  include("G:/gitRepositories/GAMES102Study/build/_deps/nameof-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/src/EMPTY/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/src/core/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/src/test/01_Num/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/src/test/02_List/01_TypeList/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/src/test/02_List/02_TemplateList/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/src/test/02_List/03_Sort/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/src/test/03_SI/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/src/test/06_TypeID/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/src/test/07_Func/00_FuncTraits/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/src/test/07_Func/01_FuncExpand/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/src/test/08_Basic/00_PConstructor/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/src/test/08_Basic/01_list_init/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/src/test/09_Concept/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UTemplate_0_4_9/cmake/UTemplateTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UTemplate_0_4_9/cmake/UTemplateTargets.cmake"
         "G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/CMakeFiles/Export/UTemplate_0_4_9/cmake/UTemplateTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UTemplate_0_4_9/cmake/UTemplateTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UTemplate_0_4_9/cmake/UTemplateTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UTemplate_0_4_9/cmake" TYPE FILE FILES "G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/CMakeFiles/Export/UTemplate_0_4_9/cmake/UTemplateTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UTemplate_0_4_9/cmake" TYPE FILE FILES
    "G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/UTemplateConfig.cmake"
    "G:/gitRepositories/GAMES102Study/build/_deps/utemplate-build/UTemplateConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UTemplate_0_4_9" TYPE DIRECTORY FILES "G:/gitRepositories/GAMES102Study/build/_deps/utemplate-src/include")
endif()

