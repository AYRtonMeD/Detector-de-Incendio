typedef struct Components_Values {
  int16_t temperature;
  int16_t humidity;
  int has_light;
  int has_gas;
  int has_flame;
} components_values_t;

void components_setup();
void read_values(components_values_t* values);