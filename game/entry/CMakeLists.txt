cmake_minimum_required(VERSION 3.14)

aux_source_directory(. SONE_GAME_ENTRY_SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/extern/json11 SONE_GAME_EXTERN_JSON11)
aux_source_directory(../proto/ SONE_GAME_PROTO_SRCS)

add_executable(Entry ${SONE_GAME_ENTRY_SRCS} ${SONE_GAME_EXTERN_JSON11} ${SONE_GAME_PROTO_SRCS})

target_link_libraries(Entry common base pthread protobuf)
target_include_directories(Entry PUBLIC ${PROJECT_SOURCE_DIR})