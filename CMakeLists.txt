cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 20)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.24.14.tar.gz"
    SHA1 "00901c19eefc02d24b16705b5f5a2b4f093a73fb"
)

project(CPP-CLI-APP-TEMPLATE)
option(BUILD_TESTS "Build tests" OFF)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

hunter_add_package(Boost COMPONENTS program_options)
find_package(Boost CONFIG REQUIRED program_options)

add_library(
    "lib${PROJECT_NAME}"
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/${PROJECT_NAME}.cpp
)

target_include_directories(
    "lib${PROJECT_NAME}"
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(
    ${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    Boost::program_options
    "lib${PROJECT_NAME}"
)

include(cmake/packaging.cmake)
if(BUILD_TESTS)
    enable_testing()
    add_executable("${PROJECT_NAME}_tests"
        tests/tests.cpp
    )
    target_link_libraries(
        "${PROJECT_NAME}_tests"
        PUBLIC
        "lib${PROJECT_NAME}" 
        GTest::gtest_main
    )
    include(GoogleTest)
    gtest_discover_tests("${PROJECT_NAME}_tests")
endif()
