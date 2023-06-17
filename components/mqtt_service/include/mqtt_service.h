#include "mqtt_gateway.h"

typedef struct Response_Data {
  mqtt_response_t* response;
} response_data_t;

response_data_t* build_response_data_struct();
void init_mqtt(response_data_t* response_data);

void publish(const char* message);