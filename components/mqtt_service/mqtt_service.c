#include <stdio.h>
#include "mqtt_service.h"
#include "mqtt_client.h"

static esp_mqtt_client_handle_t client;

response_data_t* build_response_data_struct() {
  response_data_t* response_data = (response_data_t*)malloc(sizeof(response_data_t));
  response_data->response = NULL;

  response_data->response = build_mqtt_response_struct(response_data->response);

  return response_data;
}

void init_mqtt(response_data_t* response_data) {
  build_response_data_struct(response_data);
  mqtt_setup();

  client = mqtt_app_start(response_data->response);
}

void publish(const char* message) {
  int message_len = strlen(message);
  esp_mqtt_client_publish(client, "/topic/data", message, message_len, 2, 0);
}
