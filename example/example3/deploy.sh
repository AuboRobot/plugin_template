#!/bin/bash -e
export  CPM_SOURCE_CACHE=$HOME/.cache/CPM
ROOT_DIR=$(dirname $(readlink -f $0))

# 编译debug版本
rm -rf ${ROOT_DIR}/build||:
mkdir -p ${ROOT_DIR}/build

cd ${ROOT_DIR}/build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j`nproc` package

# 编译release版本
#mkdir -p ${ROOT_DIR}/build/release
#cd ${ROOT_DIR}/build/release
#cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=${ROOT_DIR}/build/${INSTALL_DIR} ../..
#make install


