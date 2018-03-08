#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sensor = A0;
int motor = 9;
int velocidad = 0;
double temperatura;


void setup() {

lcd.begin(16, 2);
pinMode(sensor, INPUT);
pinMode(motor, OUTPUT);
Serial.begin(9600);

}

void loop() {
  temperatura = analogRead(sensor);
  temperatura = temperatura/9.31;
 
  if(temperatura > 105)
  {
    velocidad = 255;
  }
  else if (temperatura > 90){
    velocidad = 204;
  }
  else if (temperatura > 70){
    velocidad = 153;
  }
  else if (temperatura > 50){
    velocidad =102;
  }
  else if (temperatura >30){
    velocidad =51;
  }
  
  else {
    velocidad = 0;
  }

    lcd.clear();
  lcd.print("Temperatura:");
  lcd.setCursor(0,2);
  lcd.print(temperatura);
  lcd.print(" C");
  
  analogWrite(motor, velocidad);


Serial.print("temperatura: ");
Serial.println(temperatura);
Serial.print("motor: ");
Serial.println(motor);

   
  delay(500);

}
