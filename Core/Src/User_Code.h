#ifndef USER_CODE
#define USER_CODE

#include "math.h"
#define GAIN 105.0
#define VDD 3.3
#define MAX_VALUE 4095.0
#define V_TO_KPA_GAIN 1250.0
#define ADJ_GAIN 3.2

void int_to_string(int integer, char* string, unsigned int size) ;
void float_to_string(float f, char* string, unsigned int string_size, unsigned int num_afterpoint);
float adc_to_kpa(unsigned int adc_value);
float kpa_to_mm(float press_kpa);
float adc_to_hg_mm(unsigned int adc_value);

#endif
