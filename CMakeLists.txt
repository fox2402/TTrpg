cmake_minimum_required(VERSION 3.9)
project(TTrpg)



add_compile_definitions(ASIO_STANDALONE)
#external dependencies
set(ASIO_PATH ${CMAKE_SOURCE_DIR}/external/asio/asio/include)

#compiler def
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g0 -O3")

#asio dependency resolution
#find_path(ASIO_PATH)

if (((NOT ASIO_PATH) OR (NOT EXISTS ${ASIO_PATH})))
        message("Unable to find asio")
        #workaround for git submodule bug, kinda sad but works
        execute_process(COMMAND rm -rf external/asio)
        execute_process(COMMAND git submodule update)
endif()



add_executable(ttrpg src/main.cpp src/Socket.cpp src/grid.cpp src/winsock_errors.cpp src/server.cpp)

target_include_directories(ttrpg PRIVATE ${CMAKE_SOURCE_DIR}/include ${ASIO_PATH})
#target_link_libraries(ttrpg ${Boost_LIBRARIES})

if (WIN32)
    target_link_libraries(ttrpg wsock32 ws2_32)
endif(WIN32)
