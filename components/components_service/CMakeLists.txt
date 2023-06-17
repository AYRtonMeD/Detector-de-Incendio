idf_component_register(SRCS "components_service.c"
                    INCLUDE_DIRS "include"
                    REQUIRES driver esp_adc flame_sensor dht light_sensor gas_sensor)
