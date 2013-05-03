project(SoundexTpp)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{CPPUTEST_HOME}/include)
link_directories($ENV{CPPUTEST_HOME}/lib) 

add_definitions(-g -std=c++0x)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")
set(testSources SoundexTest.cpp)
add_executable(utest testmain.cpp ${testSources})

target_link_libraries(utest CppUTest)

