#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "components_service.h"
#include "mqtt_service.h"

static response_data_t* response;

void app_main() {
    response = build_response_data_struct();
    init_mqtt(response);
    components_setup();
    components_values_t* componentes = (components_values_t*)malloc(sizeof(components_values_t));
    char mqtt_data[30];

    vTaskDelay(4000 / portTICK_PERIOD_MS);
    while(1) {
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        read_values(componentes);
        sprintf(mqtt_data, "%d;%d;%d;%d;", (int)componentes->temperature, (int)componentes->humidity, componentes->has_gas, componentes->has_flame);
        printf("%s\n", mqtt_data);
        publish(mqtt_data);
    }
}
