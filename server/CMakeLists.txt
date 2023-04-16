cmake_minimum_required(VERSION 3.14)

aux_source_directory(. SONE_LIB_SERVER_SRCS)

add_library(server SHARED ${SONE_LIB_SERVER_SRCS})

target_link_libraries(server base pthread)

target_include_directories(server PUBLIC ${PROJECT_SOURCE_DIR}/)