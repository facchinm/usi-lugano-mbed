#include "mbed.h"

DigitalOut pin(LED1);

int main() {
   while (1) {
     pin = 1;
     wait(1.0f);
     pin = 0;
     wait(1.0f);
   }
}
