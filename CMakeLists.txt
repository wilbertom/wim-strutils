cmake_minimum_required(VERSION 3.19)
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

add_library(${PROJECT_NAME} SHARED
  src/strutils.cpp
)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER
  include/strutils.hpp
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
configure_file(${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
