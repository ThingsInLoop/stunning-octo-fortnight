cmake_minimum_required(VERSION 3.14)
project(stunning-octo-fortnight)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)
set(SOF_INSTALLATION_DIR $ENV{HOME}/.sof)

find_package(GTest)
if(NOT GTEST_FOUND)
  message(FATAL_ERROR "Install Gtest first. I wouldn't do it by myself. Not sorry")
endif()

set(sof-src
  src/main.cpp
  src/lib/tnode/test.cpp
)

add_executable(sof ${sof-src})
include_directories(src/lib)
# gtest_main is unnecessary because we use RUN_ALL_TESTS() macro in
# our own main
target_link_libraries(sof gtest)


# Documentation
add_definitions(-DSOF_DOCS_DIR="${SOF_INSTALLATION_DIR}/doc")
find_package(Doxygen)
if(DOXYGEN_FOUND)
  add_custom_target(doc 
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/doc/doxygen/Doxyfile 1>/dev/null 2>/dev/null
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doc/doxygen
    COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/doxygen
    COMMAND mv ${CMAKE_SOURCE_DIR}/doc/doxygen/html ${CMAKE_CURRENT_BINARY_DIR}/doxygen)
  add_dependencies(sof doc)
else()
    message(STATUS "WARNING: Doxygen not found - Reference manual will not be created")
endif()

# Installation
install(TARGETS sof DESTINATION ${SOF_INSTALLATION_DIR}/bin)
if(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/doxygen)
  install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doxygen DESTINATION ${SOF_INSTALLATION_DIR}/doc)
endif()

# Uninstallation
add_custom_target(uninstall xargs rm -f < install_manifest.txt)
