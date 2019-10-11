#include "Arduino.h"
#include "mbed.h"
#include "USBSerial.h"

DigitalOut pin(LED1);
Thread th;

void blinker() {
  while (1) {
    arduino::digitalWrite(LEDB, HIGH);
    delay(1000);
    arduino::digitalWrite(LEDB, LOW);
    delay(1000);
  }
}

int main() {
   arduino::pinMode(LEDB, OUTPUT);
   th.start(blinker);
   while (1) {
     pin = 1;
     wait(1.0f);
     pin = 0;
     wait(1.0f);
   }
}

