cmake_minimum_required(VERSION 3.5)
project(SolvingProgram)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ParseGraphFile.cpp ParseGraphFile.h)

add_library(SolvingLibrary STATIC IMPORTED)
SET_TARGET_PROPERTIES(SolvingLibrary PROPERTIES IMPORTED_LOCATION /home/dan/CSC_final_year/CSC3002_project/code/SolvingLibrary/cmake-build-release/src/libSolvingLibrary.a)

include_directories(/home/dan/CSC_final_year/CSC3002_project/code/SolvingLibrary/src)

add_executable(SolvingProgram ${SOURCE_FILES})

target_link_libraries(SolvingProgram SolvingLibrary)

