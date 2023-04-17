cmake_minimum_required(VERSION 3.14)

aux_source_directory(. SONE_GAME_ENTRY_SRCS)

add_executable(Entry ${SONE_GAME_ENTRY_SRCS})

target_link_libraries(Entry base pthread protobuf)
target_include_directories(Entry PUBLIC ${PROJECT_SOURCE_DIR})