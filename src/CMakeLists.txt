# Note that headers are optional, and do not affect add_library, but they will
# not show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later: file(GLOB HEADER_LIST
# CONFIGURE_DEPENDS "${minecraft_block_finder_SOURCE_DIR}/include/modern/*.hpp")
set(HEADER_LIST
    "${nonograms_solver_SOURCE_DIR}/include/NonogramSolver/NonogramSolver.hpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(nonograms_solver_library
            NonogramSolver.cpp
            ${HEADER_LIST}
            ${EXTERNAL_HEADER_LIST})

target_link_libraries(nonograms_solver_library PUBLIC
                        thread_pool)

# We need this directory, and users of our library will need it too
target_include_directories(nonograms_solver_library PUBLIC
                            ../include/NonogramSolver
                            ${thread_pool_SOURCE_DIR})

# All users of this library will need at least C++17
target_compile_features(nonograms_solver_library PUBLIC cxx_std_17)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})