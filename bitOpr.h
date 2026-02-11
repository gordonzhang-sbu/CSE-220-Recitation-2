#include <stdint.h>

uint16_t pack_dos_date(int year, int month, int day);
int get_year(uint16_t dos_date);
int get_month(uint16_t dos_date);
int get_day(uint16_t dos_date);
void print_bits(uint16_t value);

