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
    line_sequencer_test
    FSTLineSequencer_test.cpp
)

target_link_libraries(
    line_sequencer_test
    line_sequencer_library
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(line_sequencer_test)