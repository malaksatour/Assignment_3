# Name: Malak Satour
# ID: 900241965

cmake_minimum_required(VERSION 3.16)
project(Assignment_3_Shortest_Paths LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(graph_lib
    Code/Graph.cpp
)

target_include_directories(graph_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Code
)

add_executable(assignment_3_demo
    main.cpp
)

target_link_libraries(assignment_3_demo PRIVATE graph_lib)

enable_testing()
find_package(GTest QUIET)

if (NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

add_executable(assignment_3_tests
    Googletests/Testcases.cpp
)

target_link_libraries(assignment_3_tests PRIVATE
    graph_lib
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(assignment_3_tests)
