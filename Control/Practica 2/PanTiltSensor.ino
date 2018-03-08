#include <Servo.h>

Servo H;
Servo V;
int IZ = 9; //Lectura de Joystick
int DE = 10; //Lectura de Joystick
int AR = 11;
int AB = 12;
int PosX = 90;
int PosY = 90;
int iz;
int de;
int ar;
int ab;

void setup() {
  H.attach(7);
  V.attach(8);
  Serial.begin(9600);
  pinMode(IZ, INPUT);
  pinMode(DE, INPUT);
  pinMode(AR, INPUT);
  pinMode(AB, INPUT);
  H.write(PosX);
  V.write(PosY);

}

void loop(){
  iz = digitalRead(IZ);
  de = digitalRead(DE);
  ar = digitalRead(AR);
  ab = digitalRead(AB);

if (iz ==1){
  PosX++;
  H.write(PosX);
}
if (de == 0){
  PosX--;
  H.write(PosX);
}
if (ar == 0){
  PosY++;
  V.write(PosY);
}
if (ab == 0){
  PosY--;
  V.write(PosY);
}




  Serial.print("IZ: ");
  Serial.print(iz);
  Serial.print("   DE: ");
  Serial.print(de);
  Serial.print("   AR: ");
  Serial.print(ar);
  Serial.print("   AB: ");
  Serial.println(ab);
  
  delay(25);
}

