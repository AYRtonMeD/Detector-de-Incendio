typedef struct Components_Values {
  float temperature;
  float humidity;
  int has_gas;
  int has_flame;
} components_values_t;

void components_setup();
void read_values(components_values_t* values);