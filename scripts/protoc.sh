#!/bin/bash
# Retrieve the protoc command first
export SIM_WRAPPER_ROOT=$(pwd)
export PROTOC_CMD=thirdparty/grpc/.build/install/bin/protoc
rm -rf src/protos
rm -rf include/protos
mkdir -p src/protos
mkdir -p include/protos
for file in protos/*; do
  # use the proto to compile the gRPC message and service
  if [ -f "$file" ]; then
    $PROTOC_CMD -I . --cpp_out=src $file
    $PROTOC_CMD -I . --plugin=protoc-gen-grpc=thirdparty/grpc/.build/install/bin/grpc_cpp_plugin --grpc_out=src $file
  fi
done

mv src/protos/*.grpc.pb.h include/protos
mv src/protos/*.pb.h include/protos
