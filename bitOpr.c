#include "bitOpr.h"
#include <stdio.h>

/* MS-DOS Date bit layout (16 bits total)
*
* Bits 15–9 : Year  (7 bits)  -> year since 1980
* Bits  8–5 : Month (4 bits)  -> 1–12
* Bits  4–0 : Day   (5 bits)  -> 1–31
*/

#define YEAR_MASK   0xFE00  // 1111111000000000
#define MONTH_MASK  0x01E0  // 0000000111100000
#define DAY_MASK    0x001F  // 0000000000011111





uint16_t pack_dos_date(int year, int month, int day)
{
   uint16_t dos_date = 0;

   year = year - 1980;          // MS-DOS stores year offset

   dos_date |= (year  << 9);    // put year in bits 15–9
   dos_date |= (month << 5);    // put month in bits 8–5
   dos_date |= day;             // put day in bits 4–0

   return dos_date;
}


int get_year(uint16_t dos_date)
{
   return ((dos_date & YEAR_MASK) >> 9) + 1980;
}

int get_month(uint16_t dos_date)
{
   return (dos_date & MONTH_MASK) >> 5;
}

int get_day(uint16_t dos_date)
{
   return dos_date & DAY_MASK;
}

void print_bits(uint16_t value)
{
   for (int i = 15; i >= 0; i--) {
       printf("%d", (value >> i) & 1);
       if (i % 4 == 0) printf(" ");
   }
   printf("\n");
}
