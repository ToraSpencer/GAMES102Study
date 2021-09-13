add_executable(${PROJECT_NAME}
    main.cpp
    MathUtil.cpp
    RbfNetwork.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/rbf_nn.py
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE imgui Eigen
)

target_compile_features(${PROJECT_NAME}
    PRIVATE cxx_std_17
)

if(WIN32)
    # I am using Windows and version of Python is 3.6
    # ${Python3_LIBRARIES} set by FindPython3 is libpython36.a instead of the correct one python36.lib
    # I have no idea about how to make it work correctly through some settings for FindPython3
    # so I have to write these lines below
    target_include_directories(${PROJECT_NAME}
        PRIVATE ${Python3_INCLUDE_DIRS}
    )
    target_link_libraries(${PROJECT_NAME}
        PRIVATE ${Python3_INCLUDE_DIRS}/../libs/python${Python3_VERSION_MAJOR}${Python3_VERSION_MINOR}.lib
    )

    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_definitions(${PROJECT_NAME}
            PRIVATE MINGW
        )
    endif()
else()
    target_link_libraries(${PROJECT_NAME}
        PRIVATE Python3::Python
    )
endif()

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/rbf_nn.py
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/rbf_nn.py
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/rbf_nn.py ${CMAKE_CURRENT_BINARY_DIR}/rbf_nn.py
)