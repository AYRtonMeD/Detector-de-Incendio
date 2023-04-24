static adc1_channel_t _light_sensor_channel;
static esp_adc_cal_characteristics_t* _adc_chars;

void configure_light_sensor(const adc1_channel_t channel, esp_adc_cal_characteristics_t* adc_chars);

int read_light_sensor_value();

int read_light_sensor_voltage();

int convert_light_sensor_voltage(int light_sensor_value);