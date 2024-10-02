cmake_minimum_required(VERSION 3.29)
project(ExsamenRaport2)

# Import opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)

add_executable(ExsamenRaport2 main.cpp)

# Link opencv
target_link_libraries(ExsamenRaport2 ${OpenCV_LIBS})
