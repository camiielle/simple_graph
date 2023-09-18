cmake_minimum_required(VERSION 3.16)
project(graph VERSION 0.1.0)

# enables support for testing, including the BUILD_TESTING option used below
include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fsanitize=address -fno-omit-frame-pointer")
string(APPEND CMAKE_EXE_LINKER_FLAGS_DEBUG " -fsanitize=address -fno-omit-frame-pointer")

add_executable(graph source/main.cpp source/graph.cpp)
add_subdirectory(Lyra)
target_link_libraries(boids PRIVATE bfg::lyra)

# to disable testing, pass -DBUILD_TESTING=OFF to cmake during the configuration phase
if (BUILD_TESTING)

 add_executable(graph.t source/graph.test.cpp)

 add_test(NAME graph.t COMMAND graph.t)

endif()
