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
