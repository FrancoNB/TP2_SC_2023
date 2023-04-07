cmake_minimum_required (VERSION 3.22)

project(STACK_FRAME)

file(MAKE_DIRECTORY bin)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pedantic -Wextra -Wconversion -std=gnu11 -m32")
set(CMAKE_ASM_NASM_FLAGS "${CMAKE_ASM_NASM_FLAGS} -f elf32")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(TP2 src/stack_frame.c src/api_consumption.c src/exchange.asm)

set_target_properties(TP2 PROPERTIES LINKER_LANGUAGE C)