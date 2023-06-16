# Works with 3.14
cmake_minimum_required(VERSION 3.14)

# Project name and a few useful settings. Other commands can pick up the results
project(
    nonograms_solver
    VERSION 0.1.0
    DESCRIPTION "Program solving nonograms"
    LANGUAGES CXX)

# Only do these if this is the main project, and not if it is included through
# add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDE's
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app. Note this needs to be done
    # in the main CMakeLists since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

    # Docs only available if this is the main app
    find_package(Doxygen)
    if(Doxygen_FOUND)
        add_subdirectory(docs)
    else()
        message(STATUS "Doxygen not found, not building docs")
    endif()
endif()

include(FetchContent)

# Load line sequencer library
add_subdirectory(LineSequencer)

# Load line filter library
add_subdirectory(LineFilter)

# Load line generator library
add_subdirectory(LineGenerator)

# Load grid library
add_subdirectory(grid)

# Load image library
add_subdirectory(Image)

# Load solver library
add_subdirectory(Solver)

# Load external dependencies
add_subdirectory(extern)

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(apps)

# Testing only available if this is the main app
if(BUILD_TESTING)
  add_subdirectory(tests)
endif()

# add_executable(NonogramsSolver
#                 src/main.cpp
#                 src/NonogramSolver.cpp
#                 src/ILineGenerator.cpp
#                 src/LineGeneratorBruteForce.cpp)

# target_include_directories(NonogramsSolver PRIVATE
#                             Include/NonogramSolver
#                             thread-pool)
