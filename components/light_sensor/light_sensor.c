#include <stdio.h>
#include "driver/gpio.h"
#include "light_sensor.h"

void light_sensor_init(const int sensor_pin) {
  gpio_set_direction(sensor_pin, GPIO_MODE_INPUT);
}

int light_sensor_read(int sensor_pin) {
  return gpio_get_level(sensor_pin);
}
