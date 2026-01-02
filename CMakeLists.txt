cmake_minimum_required(VERSION 3.15)
project(perfect6502)

add_library(${PROJECT_NAME} STATIC
   netlist_sim.c
   perfect6502.c)

target_include_directories(${PROJECT_NAME} PUBLIC
   .)