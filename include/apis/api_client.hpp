#ifndef API_CLIENT_H
#define API_CLIENT_H

#include <string>
#include <iostream>
#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include "protos/VehicleController.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;

class ApiClient {
public:
  ApiClient(std::shared_ptr<Channel> channel);
  ~ApiClient();

  int set_actuators(float a1, float a2, float a3, float a4);

private:
  std::unique_ptr<VehicleController::Stub> stub_;
};

#endif /* API_CLIENT_H */
