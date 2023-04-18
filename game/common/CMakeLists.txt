cmake_minimum_required(VERSION 3.14)

aux_source_directory(. SONE_GAME_COMMON_SRCS)

add_library(common SHARED ${SONE_GAME_COMMON_SRCS})

target_link_libraries(common base pthread protobuf)
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR})