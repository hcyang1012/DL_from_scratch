cmake_minimum_required(VERSION 3.15)
project(dl_scratch)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 17)
add_library(
 dl_scratch
 ${SRC_DIR}/variable.cpp  
)
target_include_directories(dl_scratch PUBLIC ${INCLUDE_DIR})



set(TEST_PROJECT_NAME "dl_scratch_test")
find_package(GTest REQUIRED)
include(GoogleTest)
enable_testing()

file(GLOB TEST_SRC tests/*.cpp)
add_executable(${TEST_PROJECT_NAME} ${TEST_SRC})
target_link_libraries(${TEST_PROJECT_NAME} dl_scratch ${GTEST_BOTH_LIBRARIES} pthread)
gtest_discover_tests(${TEST_PROJECT_NAME})