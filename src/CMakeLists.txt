add_library(Figures Figures.cpp)

add_executable(main main.cpp)

target_link_libraries(main Figures)