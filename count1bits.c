#include "stdio.h"
#include "stdlib.h"
#include "count1bits.h"

	
/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.
 */


char* itoa(int value, char* result, int base)
{
  // check that the base if valid
  if (base < 2 || base > 36) { *result = '\0'; return result; }
  char* ptr = result, *ptr1 = result, tmp_char;
  int tmp_value;
	
  do
  {
    tmp_value = value;
    value /= base;
    *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
  } while ( value );
	
  // Apply negative sign
  if (tmp_value < 0) *ptr++ = '-';
  *ptr-- = '\0';
  while(ptr1 < ptr)
  {
    tmp_char = *ptr;
    *ptr--= *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}
	
void print_binary(int i)
{
  char buffer [33];
  itoa (i,buffer,2);
  printf ("binary: %s\n",buffer);
}


int countbits_shift(int input)
{
  int c = 0;
  unsigned int mask = 1;
  print_binary(input);
  printf("\n");
  while(mask)
  {
    if(input & mask)
    {
      c++;
    }
    mask = mask << 1;
  }
  return c;
}



int countbits_sub(int input)
{
  int count = 0;

  print_binary(input);
  printf("\n");
  while(input)
  {
    ++ count;
    input = (input - 1) & input;
  }
  return count;
}



int main()
{
  int bitcount = 0;
  int num = 34;
  bitcount = countbits_shift(num);
  printf("countbits_shift returns number of \"1\" bits in 0X%X is %d\n", num, bitcount);
  bitcount = countbits_sub(num);
  printf("countbits_sub returns number of \"1\" bits in 0x%X is %d\n", num, bitcount);

}
