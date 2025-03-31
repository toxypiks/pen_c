cmake_minimum_required(VERSION 3.16)
project(music_visualizer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
