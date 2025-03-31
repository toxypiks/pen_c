cmake_minimum_required(VERSION 3.16)
project(music_visualizer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../include)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_LINK_EXECUTABLE wasm-ld)
set(WASM_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/wasm.c
)

#add_executable(wasm)
add_library(wasm OBJECT)
target_sources(wasm
  PRIVATE
  ${WASM_SRC}
)
set_target_properties(wasm PROPERTIES COMPILE_FLAGS "-Wall -Wextra --target=wasm32")
set_target_properties(wasm PROPERTIES LINK_FLAGS    "-m wasm32 --no-entry --export-all --allow-undefined")
set_target_properties(wasm PROPERTIES OUTPUT_NAME "wasm.wasm")
