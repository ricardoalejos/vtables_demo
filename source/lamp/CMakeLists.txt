file(GLOB_RECURSE lamp_sources
    ${CMAKE_CURRENT_LIST_DIR}/*.c
)
add_library(lamp ${lamp_sources})
target_link_libraries(lamp switchable)
install(
    TARGETS lamp
    DESTINATION lib
)
install(
    FILES lamp.h
    DESTINATION include/lamp
)
target_include_directories(
    lamp
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
