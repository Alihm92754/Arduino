#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte happy[8] =
{
 B00000,
 B10001,
 B00000,
 B00000,
 B10001,
 B01110,
 B00000,
 B00000
};
byte sad[8] =
{
 B00000,
 B10001,
 B00000,
 B00000,
 B01110,
 B10001,
 B00000,
 B00000
};

void setup() {
 lcd.begin(16, 2);
 lcd.createChar(0, happy);
 lcd.createChar(1, sad);
}
void loop() {
 for (int i=0; i<2; i++){
   lcd.setCursor(0,0);
   lcd.write(i);
   delay(500);
 }
}
