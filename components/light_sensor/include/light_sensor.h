#define HIGH 1
#define LOW 0

void light_sensor_init(const int sensor_pin);
int light_sensor_read(int sensor_pin);