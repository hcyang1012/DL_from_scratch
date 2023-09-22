cmake_minimum_required(VERSION 3.15)
project(dl_scratch)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 17)
add_executable(
 dl_scratch
 "src/main.cpp"   
)

target_include_directories(dl_scratch PUBLIC ${INCLUDE_DIR})