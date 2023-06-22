# Note that headers are optional, and do not affect add_library, but they will
# not show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later: file(GLOB HEADER_LIST
# CONFIGURE_DEPENDS "${minecraft_block_finder_SOURCE_DIR}/include/modern/*.hpp")
set(HEADER_LIST
    "${solver_lib_SOURCE_DIR}/include/Solver/ISolver.hpp"
    "${solver_lib_SOURCE_DIR}/include/Solver/DeductionSolver.hpp")

set(EXTERNAL_HEADER_LIST
    "${grid_lib_SOURCE_DIR}/include/grid/grid.hpp"
    "${image_lib_SOURCE_DIR}/include/Image/Image.hpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(solver_library
            ISolver.cpp
            DeductionSolver.cpp
            ${HEADER_LIST}
            ${EXTERNAL_HEADER_LIST})

target_link_libraries(solver_library
                        grid_library)

# We need this directory, and users of our library will need it too
target_include_directories(solver_library PUBLIC
                            ../include/Solver
                            "${image_lib_SOURCE_DIR}/include/Image")

# All users of this library will need at least C++17
target_compile_features(solver_library PUBLIC cxx_std_17)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})