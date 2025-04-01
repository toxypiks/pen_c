cmake_minimum_required(VERSION 3.16)
project(wasm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(html_path_string "${CMAKE_CURRENT_BINARY_DIR}/")
configure_file(lighttpd.conf.in lighttpd.conf)

include_directories(../include)

set(CMAKE_C_COMPILER clang)
set(WASM_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/wasm.c
)

add_executable(wasm)
target_sources(wasm
  PRIVATE
  ${WASM_SRC}
)
set_target_properties(wasm PROPERTIES COMPILE_FLAGS "-Wall -Wextra --target=wasm32")
set(CMAKE_C_LINK_EXECUTABLE "wasm-ld -m wasm32 --no-entry --export-all --allow-undefined <FLAGS> <CMAKE_C_LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
set_target_properties(wasm PROPERTIES OUTPUT_NAME "wasm.wasm")
target_link_libraries(wasm)
add_custom_command(
        TARGET wasm POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/wasm/html
                ${CMAKE_CURRENT_BINARY_DIR}/html)
add_custom_command(
        TARGET wasm POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_BINARY_DIR}/wasm.wasm
                ${CMAKE_CURRENT_BINARY_DIR}/html)
