cmake_minimum_required(VERSION 3.5)
project(SolvingProgram)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ParseGraphFile.cpp ParseGraphFile.h mmio.h mmio.cpp)

set(LibraryBuildSrcLocation "/home/dan/CSC_final_year/CSC3002_project/code/SolvingLibrary/cmake-build-release/src")
set(LibraryHeaderFolder "/home/dan/CSC_final_year/CSC3002_project/code/SolvingLibrary/src")

add_library(SolvingLibrary STATIC IMPORTED)
SET_TARGET_PROPERTIES(SolvingLibrary PROPERTIES IMPORTED_LOCATION ${LibraryBuildSrcLocation}/libSolvingLibrary.a)

include_directories(${LibraryHeaderFolder})

add_executable(SolvingProgram ${SOURCE_FILES})


target_link_libraries(SolvingProgram SolvingLibrary)

