cmake_minimum_required(VERSION 3.16)
project(music_visualizer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(EXAMPLE_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/example.c
  )

add_executable(example)
target_sources(example
 PRIVATE
  ${EXAMPLE_SRC}
)

target_link_libraries(example
  m
  )

set(TEST_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/test.c
  )

add_executable(test)
target_sources(test
 PRIVATE
  ${TEST_SRC}
)
target_link_libraries(test
  m
  )
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")

add_subdirectory(./wasm)
