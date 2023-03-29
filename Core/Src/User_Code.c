#include "User_Code.h"

void int_to_string(int integer, char* string, unsigned int size) {
	int i = size - 1;
	for (; i >= 0; --i) {
		string[i] = (integer % 10) + 0x30;
		integer /= 10;
	}
}

void float_to_string(float f, char* string, unsigned int string_size, unsigned int num_afterpoint) {
	int int_part_size = 0;
	for (int i = f; i > 0; i /=10, ++int_part_size) {}
	if (int_part_size + num_afterpoint + 1 > string_size)
		return;
	int lead_zeros = (string_size - int_part_size - num_afterpoint - 1);
	char* substring = string + lead_zeros;
	for (int i = lead_zeros - 1; i >= 0; --i) {
		string[i] = '0';
	}
	
	int_to_string((int)f, substring , int_part_size);
	string[int_part_size + lead_zeros] = ',';
		
	float fractional_part = f - (int)f;
	int afterpoint = fractional_part * pow(10, num_afterpoint);
	int_to_string(afterpoint, substring + int_part_size + 1, num_afterpoint);
}

float adc_to_kpa(unsigned int adc_value) {
	return (float)adc_value / MAX_VALUE * VDD / GAIN * V_TO_KPA_GAIN * ADJ_GAIN;
}
float kpa_to_hg_mm(float press_kpa) {
	return press_kpa*7.5;
}

float adc_to_hg_mm(unsigned int adc_value) {
	return kpa_to_hg_mm(adc_to_kpa(adc_value));
}
