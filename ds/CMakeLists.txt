cmake_minimum_required(VERSION 3.14)

#link_directories()
#include_directories()
aux_source_directory(. SONE_DS_SRCS)

add_library(ds SHARED ${SONE_DS_SRCS})
#target_link_libraries()