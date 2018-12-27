#include <AFMotor.h>
//Sensores Infrarrojos
int sensorDelantero=A0; //sensor ir en A1
int lecturaDelantera=0; //lectura del sensor trasero
int Delantero=0;        //delantero

int sensorTrasero=A1; //sensor ir en A0
int lecturaTrasera=0; //lectura del sensor trasero
int Trasero=0;        //trasero

int pecho = 9;            // define el pin 2 como (pecho) para el Ultrasonido
int ptrig = 10;            // define el pin 3 como (ptrig) para el Ultrasonido
int duracion, distancia;  // para Calcular distacia

AF_DCMotor motor1(1);    //objetos motor y numero de motor
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() 
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  //////sensor ultrasonico////
  pinMode(pecho, INPUT);   // define el pin 2 como entrada (pecho) 
  pinMode(ptrig,OUTPUT);   // define el pin 3 como salida  (ptrig) 
  
  motor1.setSpeed(255);  //velocidad del motor de 0-255, 255 es la maxima
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
 
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  Serial.println("Tiempo de seguridad"); 
  delay(1000);          //Tiempo de seguridad
}

void loop() 
{
   //rutina de sensor ultrasonico
   digitalWrite(ptrig, HIGH);   // genera el pulso de trigger por 10us
   delay(0.01);
   digitalWrite(ptrig, LOW);
   duracion = pulseIn(pecho, HIGH);          // Lee el tiempo del Echo
   distancia = (duracion/2) / 29;            // calcula la distancia en centimetros
   delay(5); 
  // Serial.println(distancia);
   
   //lectura de sensores ir
   lecturaDelantera=digitalRead(sensorDelantero);
   lecturaTrasera=digitalRead(sensorTrasero);
  
  ///rutina IR ///////////
  
   //posicion adentro
  if (lecturaDelantera==HIGH && lecturaTrasera==HIGH)
  {
  Serial.println("                   DENTRO RING...");
  Delantero=0;
  Trasero=0;
  } 
  //posicion delantera
  if (lecturaDelantera==LOW)
  {
  Serial.println("RETROCEDER 3 segundos");
  Delantero=1;
  Trasero=0;
  }
  //posicion trasera
  if (lecturaTrasera==LOW)
  {  
  Delantero=0;
  Trasero=1;
  Serial.println("ADELANTE 3 segundos");
  }

//**************si detecta un oponente  
   if(distancia<=20 && Delantero==0 && Trasero==0)
  {
 motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
  ///ADELANTE////
   motor1.run(FORWARD);
   motor2.run(FORWARD);
   motor3.run(FORWARD);
   motor4.run(FORWARD);
  Serial.println("              ENCONTRO OPONENTE VAMOS DARLE...");
  delay(100);
  }
////  
  //  //sino detecta oponente
    if(distancia>=21 && Delantero==0 && Trasero==0)
    {
    motor1.setSpeed(150);
    motor2.setSpeed(150);
    motor3.setSpeed(150);
    motor4.setSpeed(150);
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(FORWARD);
    Serial.println("BUSCANDO OPONENTE EN RING...");
   }
//  ///DETECTA OPONENTE PERO DETECTA FINAL DE RING ADELANTE
     if(Delantero==1)
    {
motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
    ///ADtras////
     motor1.run(BACKWARD);
     motor2.run(BACKWARD);
     motor3.run(BACKWARD);
     motor4.run(BACKWARD);
    Serial.println("RETROCEDER 3 SEGUNDOS PERO YA LO SACAMOS");
    delay(1000);
    }
////  ///DETACTA OPONENTE PERO DETECTA FINAL DE RING ATRAS
   if(Trasero==1)
  {
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
//  ///ADELANTE////
   motor1.run(FORWARD);
   motor2.run(FORWARD);
   motor3.run(FORWARD);
   motor4.run(FORWARD);
  Serial.println("AADELNTE 3 SEGUNDOS NO DEJAREMOS Q NOS SAQUE");
  delay(1000);
  }
}
