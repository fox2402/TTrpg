cmake_minimum_required(VERSION 3.9)
project(TTrpg)
set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)


add_compile_definitions(ASIO_STANDALONE)
#external dependencies
set(ASIO_PATH ${CMAKE_SOURCE_DIR}/external/asio/asio/include)
set(CATCH_PATH ${CMAKE_SOURCE_DIR}/external/catch/single_include/)
set(RJSON_PATH ${CMAKE_SOURCE_DIR}/external/rapidjson/include)

#compiler def
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g0 -O3")


#asio dependency resolution
if (((NOT ASIO_PATH) OR (NOT EXISTS ${ASIO_PATH})))
        message("Unable to find asio")
        #workaround for git submodule bug, kinda sad but works
        execute_process(COMMAND rm -rf ${CMAKE_SOURCE_DIR}/external/asio)
        execute_process(COMMAND git submodule update --init ${CMAKE_SOURCE_DIR}/external/asio)
endif()

#catch dependency resolution
if (((NOT CATCH_PATH) OR (NOT EXISTS ${CATCH_PATH})))
        message("Unable to find catch")
        #workaround for git submodule bug, kinda sad but works
        execute_process(COMMAND rm -rf ${CMAKE_SOURCE_DIR}/external/catch)
        execute_process(COMMAND git submodule update --init ${CMAKE_SOURCE_DIR}/external/catch)
endif()

#rjson dependency resolution
if (((NOT RJSON_PATH) OR (NOT EXISTS ${RJSON_PATH})))
        message("Unable to find rapidJson")
        #workaround for git submodule bug, kinda sad but works
        execute_process(COMMAND rm -rf ${CMAKE_SOURCE_DIR}/external/rapidjson)
        execute_process(COMMAND git submodule update --init ${CMAKE_SOURCE_DIR}/external/rapidjson)
endif()

set(TTRPG_TARGET ttrpg)
set(TESTS_TARGET catch)

set(TTRPG_SRC src/grid.cpp src/GameManagerLocal.cpp src/GameManagerServer.cpp)
#set(TESTS_SRC tests/testfile.cpp)

add_executable(${TTRPG_TARGET} src/main.cpp ${TTRPG_SRC})
add_executable(${TESTS_TARGET} tests/catch.cpp ${TTRPG_SRC})# ${TESTS_SRC})

target_link_libraries(${TTRPG_TARGET} OpenSSL::Crypto OpenSSL::SSL)

target_include_directories(${TTRPG_TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/include ${ASIO_PATH} ${RJSON_PATH} ${OPENSSL_INCLUDE_DIR})
target_include_directories(${TESTS_TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/include ${ASIO_PATH} ${RJSON_PATH} ${OPENSSL_INCLUDE_DIR} ${CATCH_PATH})


if (WIN32)
        target_link_libraries(${TTRPG_TARGET} wsock32 ws2_32)
        target_link_libraries(${TESTS_TARGET} wsock32 ws2_32)
endif(WIN32)