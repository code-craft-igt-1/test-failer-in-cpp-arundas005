cmake_minimum_required(VERSION 3.5.0)
project(test_failer VERSION 0.1.0 LANGUAGES C CXX)


# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_library(PrintColorMap misaligned.cpp)

add_library(tshirts tshirts.cpp)

add_library(weatherreport weatherreport.cpp)

add_executable(runtests TestPrintColorMap.cpp TestTShirtSize.cpp TestWeatherReport.cpp)

target_link_libraries(
    runtests
    PrintColorMap
    tshirts
    weatherreport
    GTest::gtest_main
    GTest::gmock_main
)
