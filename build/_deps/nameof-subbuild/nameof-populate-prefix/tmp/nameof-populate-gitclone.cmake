
if(NOT "G:/gitRepositories/GAMES102Study/build/_deps/nameof-subbuild/nameof-populate-prefix/src/nameof-populate-stamp/nameof-populate-gitinfo.txt" IS_NEWER_THAN "G:/gitRepositories/GAMES102Study/build/_deps/nameof-subbuild/nameof-populate-prefix/src/nameof-populate-stamp/nameof-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: 'G:/gitRepositories/GAMES102Study/build/_deps/nameof-subbuild/nameof-populate-prefix/src/nameof-populate-stamp/nameof-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "G:/gitRepositories/GAMES102Study/build/_deps/nameof-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: 'G:/gitRepositories/GAMES102Study/build/_deps/nameof-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "D:/Git/cmd/git.exe"  clone --no-checkout --config "advice.detachedHead=false" "https://github.com/Neargye/nameof.git" "nameof-src"
    WORKING_DIRECTORY "G:/gitRepositories/GAMES102Study/build/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/Neargye/nameof.git'")
endif()

execute_process(
  COMMAND "D:/Git/cmd/git.exe"  checkout 0e8bec0 --
  WORKING_DIRECTORY "G:/gitRepositories/GAMES102Study/build/_deps/nameof-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '0e8bec0'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "D:/Git/cmd/git.exe"  submodule update --recursive --init 
    WORKING_DIRECTORY "G:/gitRepositories/GAMES102Study/build/_deps/nameof-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: 'G:/gitRepositories/GAMES102Study/build/_deps/nameof-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "G:/gitRepositories/GAMES102Study/build/_deps/nameof-subbuild/nameof-populate-prefix/src/nameof-populate-stamp/nameof-populate-gitinfo.txt"
    "G:/gitRepositories/GAMES102Study/build/_deps/nameof-subbuild/nameof-populate-prefix/src/nameof-populate-stamp/nameof-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: 'G:/gitRepositories/GAMES102Study/build/_deps/nameof-subbuild/nameof-populate-prefix/src/nameof-populate-stamp/nameof-populate-gitclone-lastrun.txt'")
endif()

