cmake_minimum_required(VERSION 3.16)

project(VTABLES C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pedantic")

link_directories(
    ${CMAKE_INSTALL_PREFIX}/lib
)

add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/apps
)

add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/lamp
)

add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/switchable
)
