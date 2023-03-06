

#ifndef TIME_H
#define TIME_H


#define CPU_FREQ_KHZ 1193180 // 1.19318 MHz

unsigned char inportb(unsigned short port) {
  unsigned char value;
  asm volatile ("inb %1, %0" : "=a" (value) : "d" (port));
  return value;
}


unsigned int get_cpu_freq_mhz() {
  
  unsigned int result = 0;
  unsigned int tsc1, tsc2;
  unsigned int start, end, elapsed;
  
  // Get initial timestamp counter value
  asm volatile("rdtsc" : "=a" (tsc1));
  
  // Wait for 1 millisecond
  start = inportb(0x40);
  while (1) {
      end = inportb(0x40);
      if (end - start >= 1) {
          break;
      }
  }
  
  // Get final timestamp counter value
  asm volatile("rdtsc" : "=a" (tsc2));
  
  // Calculate elapsed cycles
  elapsed = tsc2 - tsc1;
  
  // Calculate frequency in MHz
  result = elapsed / 1000;
  result = CPU_FREQ_KHZ + (result / 1000);
  
  return result;
  
}


void delay(unsigned int msec) {

  unsigned long long start, end, cycles;

  // Read the timestamp counter at the beginning of the delay
  __asm__ __volatile__ ("rdtsc" : "=A" (start));

  // Convert milliseconds to CPU cycles
  cycles = msec * get_cpu_freq_mhz() * 1000;

  // Wait until the required number of cycles has elapsed
  do {
  	__asm__ __volatile__ ("rdtsc" : "=A" (end));
  } 

	while ((end - start) < cycles);

}


#endif