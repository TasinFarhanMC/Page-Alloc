cmake_minimum_required(VERSION 3.10)
project(PAGE_ALLOC C)

add_library(page_alloc STATIC src.c)
target_include_directories(page_alloc PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
