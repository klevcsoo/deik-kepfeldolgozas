cmake_minimum_required(VERSION 3.23)
project(deik_kepfeldolgozas)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(week1_img_loading week1/img_loading.cpp)
target_link_libraries(week1_img_loading ${OpenCV_LIBS})
