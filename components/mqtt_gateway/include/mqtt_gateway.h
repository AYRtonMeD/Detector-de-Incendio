#include "mqtt_client.h"

typedef struct Mqtt_Response {
  int is_connected;
} mqtt_response_t;

void mqtt_setup(void);
esp_mqtt_client_handle_t mqtt_app_start(mqtt_response_t* response);
mqtt_response_t* build_mqtt_response_struct();
