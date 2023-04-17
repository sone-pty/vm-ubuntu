cmake_minimum_required(VERSION 3.14)

aux_source_directory(. SONE_LOG_SERVICE_SRCS)

add_executable(Logservice ${SONE_LOG_SERVICE_SRCS})

target_link_libraries(Logservice base pthread protobuf)
target_include_directories(Logservice PUBLIC ${PROJECT_SOURCE_DIR}/)