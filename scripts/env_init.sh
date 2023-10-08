#!/bin/bash
# clone the gRPC repo from github
export SIM_WRAPPER_ROOT=$(pwd)
cd $SIM_WRAPPER_ROOT/thirdparty
git clone --recurse-submodules -b v1.59.x --depth 1 --shallow-submodules https://github.com/grpc/grpc
cd grpc
mkdir .build
cd .build
cmake -DgRPC_INSTALL=ON -DCMAKE_INSTALL_PREFIX=install .. 
cmake --build . --config Release
cmake --install .
