cmake_minimum_required(VERSION 3.23)
project(deik_kepfeldolgozas)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(week1_img_loading week1/img_loading.cpp)
target_link_libraries(week1_img_loading ${OpenCV_LIBS})

add_executable(week2_montage week2/montage.cpp)
target_link_libraries(week2_montage ${OpenCV_LIBS})

add_executable(week2_pixel_manipulation week2/pixel_manipulation.cpp)
target_link_libraries(week2_pixel_manipulation ${OpenCV_LIBS})

add_executable(week3_padlolapok week3/padlolapok.cpp)
target_link_libraries(week3_padlolapok ${OpenCV_LIBS})

add_executable(week4_histogram week4/histogram.cpp lib/histo.cpp lib/histo.hpp)
target_link_libraries(week4_histogram ${OpenCV_LIBS})

add_executable(week5_kuszoboles week5/kuszoboles.cpp lib/histo.cpp lib/histo.hpp)
target_link_libraries(week5_kuszoboles ${OpenCV_LIBS})

add_executable(week7_konturkezeles week7/konturkezeles.cpp)
target_link_libraries(week7_konturkezeles ${OpenCV_LIBS})

add_executable(week7_savkizaras week7/savkizaras.cpp)
target_link_libraries(week7_savkizaras ${OpenCV_LIBS})

add_executable(zh_feladat4 zh/feladat4.cpp)
target_link_libraries(zh_feladat4 ${OpenCV_LIBS})

add_executable(zh_feladat3 zh/feladat3.cpp)
target_link_libraries(zh_feladat3 ${OpenCV_LIBS})

add_executable(zh_feladat2 zh/feladat2.cpp)
target_link_libraries(zh_feladat2 ${OpenCV_LIBS})

add_executable(zh_feladat1 zh/feladat1.cpp)
target_link_libraries(zh_feladat1 ${OpenCV_LIBS})
