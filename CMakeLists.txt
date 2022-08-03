cmake_minimum_required(VERSION 3.0.0)
project(NonogramsSolver VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(CTest)
enable_testing()

add_executable(NonogramsSolver
                src/main.cpp
                src/NonogramSolver.cpp
                src/ILineGenerator.cpp
                src/LineGeneratorBruteForce.cpp)

target_include_directories(NonogramsSolver PRIVATE
                            Include/NonogramSolver
                            thread-pool)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
