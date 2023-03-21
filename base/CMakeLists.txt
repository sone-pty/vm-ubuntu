cmake_minimum_required(VERSION 3.14)

#link_directories()
#include_directories()
aux_source_directory(. SONE_BASE_SRCS)

add_library(base SHARED ${SONE_BASE_SRCS})
#target_link_libraries()