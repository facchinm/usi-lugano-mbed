#include "mbed.h"
#include "USBSerial.h"
#include "LSM9DS1.h"

USBSerial pc;

/*
namespace mbed {
FileHandle *mbed_override_console(int fd) {
  return &stream;
}
FileHandle *mbed_target_override_console(int fd) {
  return &stream;
}
}
*/

LSM9DS1 lol(P0_14, P0_15);

REDIRECT_STDOUT_TO(pc);

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

  lol.begin();
  if (!lol.begin()) {
      pc.printf("Failed to communicate with LSM9DS1.\n");
  }

  while(1) {
      lol.readAccel();
      lol.readMag();
      lol.readGyro();

      //pc.printf("%d %d %d %d %d %d %d %d %d\n\r", lol.calcGyro(lol.gx), lol.calcGyro(lol.gy), lol.calcGyro(lol.gz), lol.ax, lol.ay, lol.az, lol.mx, lol.my, lol.mz);
      //pc.printf("%d %d %d\n\r", lol.calcGyro(lol.gx), lol.calcGyro(lol.gy), lol.calcGyro(lol.gz));
      pc.printf("gyro: %f %f %f\n\r", lol.gx, lol.gy, lol.gz);
      pc.printf("accel: %f %f %f\n\r", lol.ax, lol.ay, lol.az);
      pc.printf("mag: %f %f %f\n\n\r", lol.mx, lol.my, lol.mz);
      wait(2);
  }
}
