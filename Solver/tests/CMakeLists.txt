# Testing library
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
    solver_test
    Solver_test.cpp
)

target_link_libraries(
    solver_test
    solver_library
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(solver_test)