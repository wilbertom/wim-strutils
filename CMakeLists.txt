cmake_minimum_required(VERSION 3.19)
project(wim-strutils)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(vendor/fuzztest)

include_directories(include)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include(GoogleTest)

add_executable(
  tests
  src/strutils.cpp
  src/strutils_test.cpp
)

link_fuzztest(tests)
gtest_discover_tests(tests)
