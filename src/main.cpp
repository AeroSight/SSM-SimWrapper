#include <string>
#include "apis/api_client.hpp"

int main() {
  std::string server_address = "0.0.0.0:30031";

  ApiClient* apiClient = new ApiClient(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));

  return apiClient->set_actuators(1, 1, 1, 1);
}