
add_executable(test_calculator test_calculator.c)
target_link_libraries(test_calculator calculator mtest)

# Add test cases to CTest (our test framework has a nice macro for that).
discover_tests(test_calculator)
