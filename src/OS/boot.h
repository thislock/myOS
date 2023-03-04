
#ifndef BOOT_H
#define BOOT_H

#include "../drivers/text_driver.h"

// first time processing, like loading drivers, and kernal
void startup() {

  print_string("welcome to universeOS!\n");

}


#endif
