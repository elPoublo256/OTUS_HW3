cmake_minimum_required(VERSION 3.1)

project(my_stl)

set(CMAKE_CXX_STANDART 14)

set(CMAKE_CXX_STANDART_REQUIRED ON)

#set(CMAKE_CXX_EXTENSIONS OFF)

#find_package(Boost COMPONENTS unit_test_framework REQUIRED)


#add_library(libmy_stl STATIC  my_alloc.h)

#include_directories(&{Boost_INCLUDE_DIRS})

add_executable(run_my_stl main.cpp)

#target_link_libraries(run_my_stl my_stl)

# target_link_libraries(unit_boost_test)

install(TARGETS run_my_stl RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_CONTACT elpoublo@gmail.com)

include(CPack)

#enable_testing()

#add_test()
