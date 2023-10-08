cmake_minimum_required(VERSION 3.0)

project(SSM_SimWrapper)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_PREFIX_PATH thirdparty/grpc/.build/install/lib/cmake)

find_package(Protobuf CONFIG REQUIRED)
find_package(absl CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
set(_GRPC_GRPCPP_UNSECURE gRPC::grpc++_unsecure)
file(GLOB SOURCES "src/*/*.cpp")
file(GLOB PROTO_SOURCES "src/*/*.cc")

add_library(SSM_SimWrapper SHARED
    ${SOURCES}
    ${PROTO_SOURCES}
    ${_PROTOBUF_LIBPROTOBUF}
)
target_include_directories(SSM_SimWrapper PUBLIC 
  include
  ${_GRPC_GRPCPP_INCLUDE_DIR}
)
target_link_libraries(SSM_SimWrapper
    gRPC::grpc++
)

include_directories(
  include
  ${_GRPC_GRPCPP_INCLUDE_DIR}
)

add_executable(main src/main.cpp)

target_link_libraries(main SSM_SimWrapper gRPC::grpc++)
