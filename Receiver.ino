#include <LiquidCrystal.h>
#include <RH_ASK.h>
#include <SPI.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
RH_ASK rf_driver(2000, 13);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Temperatura:");
  rf_driver.init();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t buf[5];
  uint8_t buflen=sizeof(buf);

  if(rf_driver.recv(buf, &buflen)){
    lcd.setCursor(0,1);
    lcd.print((char *)buf);
    lcd.setCursor(5,1);
    lcd.print(char(223));
    lcd.setCursor(6,1);
    lcd.print("C");
    Serial.print((char *)buf);
  }
}
