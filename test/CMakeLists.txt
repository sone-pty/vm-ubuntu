cmake_minimum_required(VERSION 3.14)

include_directories(${PROJECT_SOURCE_DIR}/include)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

aux_source_directory(. SONE_TEST_SERVICE_SRCS)

add_executable(Test ${SONE_TEST_SERVICE_SRCS})

target_link_libraries(Test base pthread protobuf)