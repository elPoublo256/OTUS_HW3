cmake_minimum_required(VERSION 3.1)

project(test_my_stl)

enable_testing()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(unit_boost_test unit_boost_test.cpp)

include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(unit_boost_test ${Boost_LIBRARIES})

add_test(NAME test1 COMMAND unit_boost_test)
