#include "apis/api_client.hpp"

ApiClient::ApiClient(std::shared_ptr<Channel> channel): stub_(VehicleController::NewStub(channel)) {
  
}

ApiClient::~ApiClient() {}

int ApiClient::set_actuators(float a1, float a2, float a3, float a4) {
  ClientContext context;
  ActuatorCommands commands;
  ActuatorCommands response;
  commands.add_actuator_commands(a1);
  commands.add_actuator_commands(a2);
  commands.add_actuator_commands(a3);
  commands.add_actuator_commands(a4);
  grpc::Status status = this->stub_->set_actuators(&context, commands, &response);
  if (status.ok()) {
    std::cout << "RPC returns: OK" << std::endl;
    std::cout << "RPC response: " << response.actuator_commands(0) << std::endl;
    std::cout << "RPC response: " << response.actuator_commands(1) << std::endl;
    std::cout << "RPC response: " << response.actuator_commands(2) << std::endl;
    std::cout << "RPC response: " << response.actuator_commands(3) << std::endl;
    return 0;
  } else {
    std::cerr << status.error_code() << std::endl;
    std::cerr << "RPC failed: " << status.error_message() << std::endl;
    return -1;
  }
}