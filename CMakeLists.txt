cmake_minimum_required(VERSION 3.5.0)
project(test_failer VERSION 0.1.0 LANGUAGES C CXX)


# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



enable_testing()

add_executable(misaligned misaligned.cpp TestPrintColorMap.cpp)
add_executable(tshirts tshirts.cpp TestTshirtsize.cpp)
add_executable(weatherreport weatherreport.cpp TestWeatherReport.cpp)
