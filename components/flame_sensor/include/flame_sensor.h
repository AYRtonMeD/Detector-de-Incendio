static adc1_channel_t _flame_sensor_channel;
static esp_adc_cal_characteristics_t* _adc_chars;

void configure_flame_sensor(const adc1_channel_t channel, esp_adc_cal_characteristics_t* adc_chars);

int read_flame_sensor_value();

int read_flame_sensor_voltage();

int convert_flame_sensor_voltage(int flame_sensor_value);