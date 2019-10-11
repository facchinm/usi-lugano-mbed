#include "mbed.h"

DigitalOut pin(LED1);
DigitalOut pin2(P0_24);
Thread th;

void blinker() {
  while (1) {
     pin2 = 1;
     wait(1.0f);
     pin2 = 0;
     wait(1.0f);
  }
}

int main() {
   th.start(blinker);
   while (1) {
     pin = 1;
     wait(1.0f);
     pin = 0;
     wait(1.0f);
   }
}

