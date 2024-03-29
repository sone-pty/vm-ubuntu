PROJECT(sone)

SET(MY_TARGET sone)
SET(MY_LINK base)

CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

SET(CMAKE_CXX_COMPILER "/usr/bin/g++")

#SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -Wno-sign-compare -Wno-reorder -std=c++17")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -Wno-sign-compare -Wno-reorder -std=c++17")

#执行文件输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#库输出路径
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

MESSAGE("++++++++++++++Start Build+++++++++++++++++")

#源文件
AUX_SOURCE_DIRECTORY(. SRC_LIST)
AUX_SOURCE_DIRECTORY(./extern/http_parser EXTERN_HTTPPARSER_SRC)
AUX_SOURCE_DIRECTORY(./extern/json11 EXTERN_JSON11_SRC)

#添加子目录
ADD_SUBDIRECTORY(base)

ADD_SUBDIRECTORY(Logservice)
add_dependencies(Logservice base)

ADD_SUBDIRECTORY(test)
add_dependencies(Test base)

##game##
add_subdirectory(game/common)
add_dependencies(common base)

ADD_SUBDIRECTORY(game/entry)
add_dependencies(Entry common base)

ADD_SUBDIRECTORY(game/list)
add_dependencies(List common base)
##game##

#链接库搜索路径
LINK_DIRECTORIES(lib)

#设置链接库
SET(EXTRA_LIBS ${EXTRA_LIBS} ${MY_LINK} pthread)

#生成可执行文件
ADD_EXECUTABLE(${MY_TARGET} ${SRC_LIST} ${EXTERN_HTTPPARSER_SRC} ${EXTERN_JSON11_SRC})

#执行文件链接属性
TARGET_LINK_LIBRARIES(${MY_TARGET} ${EXTRA_LIBS})

target_include_directories(${MY_TARGET} PUBLIC ${PROJECT_SOURCE_DIR}/extern ${PROJECT_SOURCE_DIR})