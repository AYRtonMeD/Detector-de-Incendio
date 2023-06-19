#include <stdio.h>
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "components_service.h"
#include "flame_sensor.h"
#include "dht.h"
#include "light_sensor.h"
#include "gas_sensor.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define TEMP_HUMI_SENSOR 22
#define GAS_SENSOR 23
#define FLAME_SENSOR 7

#define DEFAULT_VREF 1100

static esp_adc_cal_characteristics_t adc_chars;


void components_setup() {
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(FLAME_SENSOR, ADC_ATTEN_DB_11);
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, DEFAULT_VREF, &adc_chars);

    configure_flame_sensor(FLAME_SENSOR, &adc_chars);
    gas_sensor_init(GAS_SENSOR);
}

void read_values(components_values_t* values)
{ 
  dht_read_float_data(DHT_TYPE_DHT11, TEMP_HUMI_SENSOR, &values->humidity, &values->temperature);
  values->has_gas = gas_sensor_read(GAS_SENSOR) ? 0 : 1;
  values->has_flame = flame_sensor_read(FLAME_SENSOR) ? 0 : 1;
}
