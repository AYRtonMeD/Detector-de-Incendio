static adc1_channel_t _gas_sensor_channel;
static esp_adc_cal_characteristics_t* _adc_chars;

void configure_gas_sensor(const adc1_channel_t channel, esp_adc_cal_characteristics_t* adc_chars);

int read_gas_sensor_value();

int read_gas_sensor_voltage();

int convert_gas_sensor_voltage(int gas_sensor_value);