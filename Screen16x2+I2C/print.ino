#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,2,1,0,4,5,6,7,3, POSITIVE);

void setup() {
 lcd.begin (16,2);
 lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Arduino e Cia !!");
  lcd.setCursor(0,1);a
  lcd.print("LCD e modulo I2C");
}

// the loop function runs over and over again forever
void loop() {
}