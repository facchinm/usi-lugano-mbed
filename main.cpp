#include "mbed.h"
#include "USBSerial.h"
I2C i2c(P0_14, P0_15); //SDA, SCL
USBSerial pc;

DigitalOut i2c_pullup(P1_0);
DigitalOut i2c_vdd_enable(P0_22);

void fixNano33BLE() {
  CoreDebug->DEMCR = 0;
  NRF_CLOCK->TRACECONFIG = 0;
}

int main()
{
  fixNano33BLE();
  i2c_pullup = 1;
  i2c_vdd_enable = 1;
  pc.printf("RUN\r\n");
  for(int i = 0; i < 128 ; i++) {
    i2c.start();
    if(i2c.write(i << 1) == 1) pc.printf("0x%x ACK \r\n",i); // Send command string
    i2c.stop();
  }
}
