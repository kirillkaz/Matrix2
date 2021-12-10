cmake_minimum_required(VERSION 3.20)
project(untitled3)

set(CMAKE_CXX_STANDARD 23)

add_library(MATRIX_MATH STATIC MatrixMath.cpp MatrixMath.h )
add_library(MATRIX_PRINT_STATIC STATIC MatrixConsolePrint.cpp MatrixConsolePrint.h  MatrixFilePrint.cpp MatrixFilePrint.h PrintTo.cpp PrintTo.h)
add_executable(MAIN main.cpp)
target_link_libraries(MAIN MATRIX_MATH MATRIX_PRINT_STATIC)


