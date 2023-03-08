
#include "drivers/int_to_char.h"

extern void cppmain() {


  int rad = middle_square();

  int test = 100;

  char str[10];

  intToString(rad, str, 10);

  print_string(str);

}