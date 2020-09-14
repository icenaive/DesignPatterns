cmake_minimum_required(VERSION 3.11)
project(simple_factory)

aux_source_directory(. DIR_SRCS)
add_executable(test_simple_factory ${DIR_SRCS})