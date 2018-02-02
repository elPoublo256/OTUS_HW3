cmake_minimum_required(VERSION 3.1)

project(my_stl)

#set(CMAKE_CXX_STANDART 14)

#set(CMAKE_CXX_STANDART_REQUIRED ON)

#set(CMAKE_CXX_EXTENSIONS OFF)

#set(TEST_SOURCES unit_boost_test.cpp)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

#include_directories(${Boost_INCLUDE_DIRS})

add_executable(run_my_stl main.cpp)

#add_executable(test_project unit_boost_test.cpp)

set_target_properties(run_my_stl unit_boost_test PROPERTIES
 CXX_STANDART 14
 CMAKE_CXX_STANDART_REQUIRED ON
 COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(unit_boost_test PROPERTIES
 COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
 INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS}
)

#set_target_properties(

install(TARGETS run_my_stl RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_CONTACT elpoublo@gmail.com)

include(CPack)

enable_testing()

add_test(unit_boost_test unit_boost_test)
