cmake_minimum_required(VERSION 3.26)
project(forward_list64)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(.)

add_executable(forward_list64
        forward_list64.cc
        forward_list64.h
        bench_struct.h)
add_executable(forward_list
        forward_list.cc
        bench_struct.h)
add_executable(bench_aligned_alloc
        bench_aligned_alloc.c
        bench_alloc.h)
add_executable(bench_posix_memalign
        bench_posix_memalign.c
        bench_alloc.h)
add_executable(bench_malloc
        bench_malloc.c
        bench_alloc.h)
add_executable(bench_cacheline
        bench_cacheline.c)
add_executable(forward_list64_test
        forward_list64_test.cc
        forward_list64.h)
