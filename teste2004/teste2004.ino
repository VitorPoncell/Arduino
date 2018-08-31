#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


void setup() {
 lcd.begin (20,4);

}

void loop() {
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,1);
  lcd.print("Arduino e Cia !!!!!!");
  lcd.setCursor(0,2);
  lcd.print("LCD e modulo I2C");
  delay(1000);
}
