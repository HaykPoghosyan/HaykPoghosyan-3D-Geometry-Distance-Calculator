cmake_minimum_required(VERSION 3.14)

# Set project name and language
project(Geometry3D)

# Add option for unit tests (ON by default)
option(BUILD_UNIT_TESTS "Build unit tests" ON)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set runtime library to match between all targets
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

# Add source files
set(SOURCES
    main.cpp
    Point3D.cpp
    Vector3D.cpp
    Segment3D.cpp
)

# Add header files
set(HEADERS
    Point3D.h
    Vector3D.h
    Segment3D.h
)

# Main library
add_library(geometry_lib
    Point3D.cpp
    Vector3D.cpp
    Segment3D.cpp
)

# Main executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} PRIVATE geometry_lib)

# Set output directory
set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Add compiler warnings
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Unit Tests
if(BUILD_UNIT_TESTS)
    # Download and build GoogleTest
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Enable testing
    enable_testing()

    # Test executable
    add_executable(geometry_tests
        tests/geometry_tests.cpp
    )
    target_link_libraries(geometry_tests PRIVATE
        geometry_lib
        GTest::gtest_main
    )
    target_include_directories(geometry_tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
    )

    # Set output directory
    set_target_properties(geometry_tests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )

    include(GoogleTest)
    gtest_discover_tests(geometry_tests)
endif() 