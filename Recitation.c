#include <stdio.h>
#include <stdint.h>
#include "bitOpr.h"

/* MS-DOS Date bit layout (16 bits total)
*
* Bits 15–9 : Year  (7 bits)  -> year since 1980
* Bits  8–5 : Month (4 bits)  -> 1–12
* Bits  4–0 : Day   (5 bits)  -> 1–31
*/

//#define YEAR_MASK   0xFE00  // 1111111000000000
//#define MONTH_MASK  0x01E0  // 0000000111100000
//#define DAY_MASK    0x001F  // 0000000000011111



int main(void)
{
   int year = 2025;
   int month = 9;
   int day = 1;

   uint16_t dos_date = pack_dos_date(year, month, day);

   printf("Original date: %d/%d/%d\n", month, day, year);
   printf("Packed MS-DOS date (hex): 0x%04X\n", dos_date);
   printf("Packed MS-DOS date (binary): ");
   print_bits(dos_date);

   printf("\nDecoded values:\n");
   printf("Year : %d\n", get_year(dos_date));
   printf("Month: %d\n", get_month(dos_date));
   printf("Day  : %d\n", get_day(dos_date));

   return 0;
}
