cmake_minimum_required(VERSION 3.1)

project(my_stl)

add_executable(run_my_stl main.cpp)

set_target_properties(run_my_stl PROPERTIES
 CXX_STANDART 14
 CMAKE_CXX_STANDART_REQUIRED ON
 COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

install(TARGETS run_my_stl RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_CONTACT elpoublo@gmail.com)

include(CPack)

