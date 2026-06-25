cmake_minimum_required(VERSION 4.2.1)
project(Sorting_Visualizer)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib)

add_executable(Sorting_Visualizer
 src/main.cpp
 src/sorting/BubbleSort.cpp
 src/sorting/SelectionSort.cpp
 src/sorting/InsertionSort.cpp
 src/sorting/MergeSort.cpp
 src/sorting/QuickSort.cpp
 src/visualizer/Visualizer.cpp
 src/ui/menu.cpp)

target_link_libraries(Sorting_Visualizer PRIVATE raylib)
