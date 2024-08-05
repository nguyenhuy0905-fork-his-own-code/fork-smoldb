include(GoogleTest)
find_package(GTest REQUIRED)

add_executable(smoldb-test-automata test-automata.cpp)
target_link_libraries(smoldb-test-automata PRIVATE smoldb-compile-opts
                                                   smoldb-cli GTest::gtest_main)

gtest_discover_tests(smoldb-test-automata)
