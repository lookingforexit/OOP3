add_executable(Figures_tests main.cpp Figures_tests.cpp)

target_link_libraries(Figures_tests gtest gtest_main Figures)

include(GoogleTest)
gtest_discover_tests(Figures_tests)