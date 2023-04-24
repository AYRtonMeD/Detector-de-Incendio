#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include <esp_log.h>
#include "light_sensor.h"

#define NO_OF_SAMPLES   64 // number of samples to take for averaging

void configure_light_sensor(const adc1_channel_t channel, esp_adc_cal_characteristics_t* adc_chars) {
  _light_sensor_channel = channel;
  _adc_chars = adc_chars;
}

int read_light_sensor_value() {
  int adc_reading = 0;
  for (int i = 0; i < NO_OF_SAMPLES; i++) {
    adc_reading += adc1_get_raw(_light_sensor_channel);
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }

  adc_reading /= NO_OF_SAMPLES;

  return adc_reading;
}

int read_light_sensor_voltage() {
  return esp_adc_cal_raw_to_voltage(read_light_sensor_value(), _adc_chars);
}

int convert_light_sensor_voltage(int light_sensor_value) {
  return esp_adc_cal_raw_to_voltage(light_sensor_value, _adc_chars);
}
