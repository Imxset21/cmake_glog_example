cmake_minimum_required(VERSION 3.2)
include(ExternalProject)

project(Example CXX)

## gflags
add_subdirectory(gflags)

## glog
set(GLOG_LIBS
  ${CMAKE_CURRENT_BINARY_DIR}/glog-master/${CMAKE_FIND_LIBRARY_PREFIXES}glog${CMAKE_STATIC_LIBRARY_SUFFIX}
)
ExternalProject_Add(
    glog-master
    DEPENDS gflags
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/glog-master
    GIT_REPOSITORY https://github.com/google/glog
    GIT_TAG master
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glog/glog-master
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/glog-master
    CMAKE_ARGS -Dgflags_DIR=${CMAKE_CURRENT_BINARY_DIR}/gflags
    BUILD_COMMAND ${CMAKE_MAKE_PROGRAM}
    BUILD_BYPRODUCTS ${GLOG_LIBS}
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    INSTALL_COMMAND ""
)
set(GLOG_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/glog-master/)
add_library(glog UNKNOWN IMPORTED)
set_property(TARGET glog PROPERTY IMPORTED_LOCATION "${GLOG_LIBS}")

## library
add_executable(example Example.cpp)

target_link_libraries(example PRIVATE gflags)
target_include_directories(example PRIVATE ${GFLAGS_INCLUDE_DIRS})
target_link_libraries(example PRIVATE glog)
target_include_directories(example PRIVATE ${GLOG_INCLUDE_DIRS})
