#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sensor = A0;
double temperatura;

void setup() {
lcd.begin(16, 2);

pinMode(sensor, INPUT);
Serial.begin(9600);
}

void loop() {
  temperatura = analogRead(sensor);
  temperatura = temperatura/9.31;
  
  lcd.clear();
  lcd.print("Temperatura:");
  lcd.setCursor(0,2);
  lcd.print(temperatura);
  lcd.print(" C");
  


Serial.print("temperatura: ");
Serial.println(temperatura);

delay (500);
}
