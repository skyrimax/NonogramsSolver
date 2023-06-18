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
    image_test
    Image_constructors_test.cpp
    Image_test.cpp
)

target_link_libraries(
    image_test
    image_library
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(image_test)