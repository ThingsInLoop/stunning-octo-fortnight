cmake_minimum_required(VERSION 3.14)
project(stunning-octo-fortnight)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

set(sof-src
  src/main.cpp
  src/lib.cpp
)

add_executable(sof ${sof-src})
# gtest_main is unnecessary because we use RUN_ALL_TESTS() macro in
# our own main
target_link_libraries(sof gtest)
