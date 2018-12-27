#include <AFMotor.h>
int sensorTrasero=A0; //sensor ir en A0
int lecturaTrasera=0; //lectura del sensor trasero

int sensorDelantero=A1; //sensor ir en A1
int lecturaDelantera=0; //lectura del sensor trasero

AF_DCMotor M1(1);    //objetos motor y numero de motor
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

void setup() 
{
  Serial.begin(9600);    // set up Serial library at 9600 bps
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
  Serial.println("Tiempo de seguridad"); 
  delay(100);          //Tiempo de seguridad
}

void loop() 
{
   //lectura de sensores ir
   lecturaTrasera=digitalRead(sensorTrasero);
   lecturaDelantera=digitalRead(sensorDelantero);
   
   // impresion de sensores ir
   Serial.print("Sensor Delantero: ");
   Serial.print(lecturaTrasera);
   Serial.print("Sensor Trasero:");
   Serial.println(lecturaDelantera);
 
  ///rutina IR ///////////
  //posicion trasera
  if (lecturaTrasera==0)
  {
   M1.setSpeed(200);
   M2.setSpeed(200);
   M3.setSpeed(200);
   M4.setSpeed(200);
  ///ADELANTE////
   M1.run(FORWARD);
   M2.run(FORWARD);
   M3.run(FORWARD);
   M4.run(FORWARD);
  Serial.println("Adelante 2 segundos");
  delay(2000);
  }
  if (lecturaDelantera==0)
  {
   M1.setSpeed(200);
   M2.setSpeed(200);
   M3.setSpeed(200);
   M4.setSpeed(200);
  ///ADELANTE////
   M1.run(BACKWARD);
   M2.run(BACKWARD);
   M3.run(BACKWARD);
   M4.run(BACKWARD);
  Serial.println("Atras 2 segundos");
  delay(2000);
  }
   if (lecturaDelantera==1 && lecturaTrasera==1)
  {
   M1.setSpeed(150);
   M2.setSpeed(150);
   M3.setSpeed(150);
   M4.setSpeed(150);
  ///ADELANTE////
   M1.run(RELEASE);
   M2.run(RELEASE);
   M3.run(RELEASE);
   M4.run(RELEASE);
  Serial.println("DENTRO DEL RING...");
  delay(2000);
  }
}
