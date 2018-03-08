#include <Servo.h>
//comentario
Servo H;
Servo V;
int X = A0; //Lectura de Joystick
int Y = A1; //Lectura de Joystick
int JoyX;
int JoyY;
int PosX = 90;
int PosY = 90;

void setup() {
  H.attach(7);
  V.attach(8);
  Serial.begin(9600);
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  H.write(PosX);
  V.write(PosY);

}

void loop() {
JoyX = analogRead(X);
JoyX = map(JoyX, 550, 590, -100, 100);
JoyY = analogRead(Y);
JoyY= map(JoyY, 0, 1023, 100, -100);

Serial.print("Joystick X: ");
Serial.println(JoyX);
Serial.print("Joystick Y: ");
Serial.println(JoyY);

if (JoyX > 40 && PosX != 180){
  PosX++;
  H.write(PosX);
  //H.write (180);
}
else if(JoyX  < -40 && PosX !=0){
  PosX--;
  H.write(PosX);
  //H.write(0);
}

if(JoyY >40 && PosY!=180){
  PosY--;
  V.write(PosY);
  //V.write(180);
}
else if(JoyY < -40 && PosY !=0){
  PosY++;
  V.write(PosY);
  //V.write(0);
}

Serial.print("Pos X: ");
Serial.println(PosX);
Serial.print("Pos Y: ");
Serial.println(PosY);

delay(40);

}
