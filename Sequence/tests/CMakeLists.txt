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
    sequence_test
    Sequence_test.cpp
)

target_link_libraries(
    sequence_test
    sequence_library
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(sequence_test)