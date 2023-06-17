#include <stdio.h>
#include "driver/gpio.h"
#include "gas_sensor.h"

void gas_sensor_init(const int sensor_pin) {
  gpio_set_direction(sensor_pin, GPIO_MODE_INPUT);
}

int gas_sensor_read(int sensor_pin) {
  return gpio_get_level(sensor_pin);
}