#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include <esp_log.h>
#include "flame_sensor.h"

#define NO_OF_SAMPLES   64 // number of samples to take for averaging

static adc1_channel_t _flame_sensor_channel;
static esp_adc_cal_characteristics_t* _adc_chars;

void configure_flame_sensor(const adc1_channel_t channel, esp_adc_cal_characteristics_t* adc_chars) {
  _flame_sensor_channel = channel;
  _adc_chars = adc_chars;
}

int flame_sensor_read() {
  int adc_reading = 0;
  for (int i = 0; i < NO_OF_SAMPLES; i++) {
    adc_reading += adc1_get_raw(_flame_sensor_channel);
    vTaskDelay(1 / portTICK_PERIOD_MS);
  }

  adc_reading /= NO_OF_SAMPLES;
  printf("%d\n", adc_reading);
  if (adc_reading < 100) {
    return 0;
  }
  else {
    return 1;
  }
}
