#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;
#define LM35 A0

void setup() {
  Serial.begin(9600);
  rf_driver.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  float result = ((analogRead(LM35) * 5.0) / 1024.0) * 100; 
  char msg[5];
  dtostrf(result, 4, 2, msg);
  rf_driver.send((uint8_t *)msg, strlen(msg));
  rf_driver.waitPacketSent();
  delay(1000);
}
