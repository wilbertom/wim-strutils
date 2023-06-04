cmake_minimum_required(VERSION 3.26)
project(wim-strutils VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
  fuzztest
  GIT_REPOSITORY https://github.com/google/fuzztest.git
  GIT_TAG main
)
FetchContent_MakeAvailable(fuzztest)

enable_testing()

include(GoogleTest)

add_executable(
  ${PROJECT_NAME}-tests
  src/strutils.cpp
  src/strutils_test.cpp
)

target_include_directories(${PROJECT_NAME}-tests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

link_fuzztest(${PROJECT_NAME}-tests)
gtest_discover_tests(${PROJECT_NAME}-tests)

add_library(${PROJECT_NAME} STATIC
  src/strutils.cpp
)
target_include_directories(${PROJECT_NAME}
  PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
