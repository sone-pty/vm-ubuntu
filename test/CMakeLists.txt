cmake_minimum_required(VERSION 3.14)

aux_source_directory(. SONE_TEST_SERVICE_SRCS)

add_executable(Test ${SONE_TEST_SERVICE_SRCS})

target_link_libraries(Test base pthread protobuf)
target_include_directories(Test PUBLIC ${PROJECT_SOURCE_DIR}/)