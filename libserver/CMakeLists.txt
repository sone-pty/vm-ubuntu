cmake_minimum_required(VERSION 3.14)

include_directories(${PROJECT_SOURCE_DIR}/include)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

aux_source_directory(. SONE_LIB_SERVER_SRCS)

add_library(libserver SHARED ${SONE_LIB_SERVER_SRCS})

target_link_libraries(libserver base)