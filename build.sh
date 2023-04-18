#!/bin/bash  

set -e  

# build proto
./build_proto.sh

# 默认构建类型为 Release
BUILD_TYPE=Release

# 处理命令行参数
while [[ $# -gt 0 ]]
do
    key="$1"

    case $key in
        --debug)
        BUILD_TYPE=Debug
        shift
        ;;
        *)
        # 未知的选项
        echo "Unknown option: $key"
        exit 1
        ;;
    esac
done

PROJ_ROOT=$PWD  
BUILD_ROOT=$PROJ_ROOT  
echo -e "\033[31m Current Build Root: $BUILD_ROOT \033[0m"  

BIN_PATH=$BUILD_ROOT/bin

if [ -d $BIN_PATH ];then
    cd $BIN_PATH
    rm -rf *
    cd ..
else
    mkdir -p $BIN_PATH  
fi

: <<COMMENT
INC_PATH=$BUILD_ROOT/include

if [ -d $INC_PATH ];then
    cd $INC_PATH
    rm -rf *
    cd ..
else
    mkdir -p $INC_PATH  
fi

#cp without path
DEST_PATH="./include/"
headers=`find . -name '*.h' \
        ! -path './3rd/*' \
        ! -path './extern/*'`

for file in $headers
do
    temp=${file#*/}
    dstfile=$DEST_PATH$temp
    dstpath=${dstfile%/*}
    #echo $dstpath
    [ -d $dstpath ] || mkdir -p  $dstpath

    cp -R $file $dstfile
done
COMMENT

LIB_PATH=$BUILD_ROOT/lib

if [ -d $LIB_PATH ];then
    cd $LIB_PATH
    rm -rf *
    cd ..
else
    mkdir -p $LIB_PATH  
fi

BUILD_PATH=$BUILD_ROOT/build

if [ -d $BUILD_PATH ];then
    cd $BUILD_PATH
    rm -rf *
else
    mkdir -p $BUILD_PATH  
    cd $BUILD_PATH
fi

export LD_LIBRARY_PATH=LD_LIBRARY_PATH:./
cmake $PROJ_ROOT -DCMAKE_BUILD_TYPE=$BUILD_TYPE
make -j4