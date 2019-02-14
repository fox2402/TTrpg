cmake_minimum_required(VERSION 3.9)
project(TTrpg)

set(CMAKE_CXX_STANDARD 17)


set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Werror -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g0 -O3")

add_executable(ttrpg src/main.cpp src/Socket.cpp src/grid.cpp src/winsock_errors.cpp)

target_include_directories(ttrpg PRIVATE ${CMAKE_SOURCE_DIR}/include)

if (WIN32)
    target_link_libraries(ttrpg wsock32 ws2_32)
endif(WIN32)
