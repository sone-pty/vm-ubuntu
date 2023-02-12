cmake_minimum_required(VERSION 3.14)

#link_directories()
#include_directories()
aux_source_directory(. SONE_UTILS_SRCS)

add_library(utils SHARED ${SONE_UTILS_SRCS})
#target_link_libraries()