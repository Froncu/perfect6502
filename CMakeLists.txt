cmake_minimum_required(VERSION 3.15)
project(perfect6502)

add_library(${PROJECT_NAME} STATIC
   private/emulator.cpp
   private/netlist_sim.c
   private/perfect6502.c)

target_include_directories(${PROJECT_NAME}
   PRIVATE private
   PUBLIC public)

set_target_properties(${PROJECT_NAME} PROPERTIES
   CXX_STANDARD 23
   CXX_STANDARD_REQUIRED TRUE)

target_compile_options(${PROJECT_NAME}
   PRIVATE $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic -Werror>
   PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>)