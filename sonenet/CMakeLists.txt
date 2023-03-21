cmake_minimum_required(VERSION 3.14)

#link_directories()
include_directories(./base)
aux_source_directory(. SONE_SONENET_SRCS)

add_library(sonenet SHARED ${SONE_SONENET_SRCS})
target_link_libraries(sonenet base)