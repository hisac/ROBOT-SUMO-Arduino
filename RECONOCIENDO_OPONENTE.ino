#include <AFMotor.h> //libreria
int echo = 9;            //  SERVO 2 define el pin 2 como (pecho) para el Ultrasonido
int trig = 10;            // SERVO 1 define el pin 3 como (ptrig) para el Ultrasonido
int duracion, distancia;  // para Calcular distacia
//************Damos de Alta los 4 motores************//
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);
//***************************************************//

void setup() 
{
  Serial.begin(9600);           // comunicacion serial
  //*********sensor ultrasonico****//
  pinMode(echo, INPUT);   // 
  pinMode(trig,OUTPUT);   // 
  //*******************************//
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
  Serial.println("Tiempo de seguridad"); 
  delay(1000);          //Tiempo de seguridad
}

void loop() 
{
   //******Rutina de sensor Ultrasonico********//
   digitalWrite(trig, HIGH);   // genera el pulso de trigger por 10us
   delay(0.01);
   digitalWrite(trig, LOW);
   duracion = pulseIn(echo, HIGH);          // Lee el tiempo del Echo
   distancia = (duracion/2) / 29;            // calcula la distancia en centimetros 
   Serial.print(distancia);
   Serial.println("cm");
   delay(1);
   //******************************************//
  ///si detecto oponete
   if (distancia<=15)
   {
    M1.setSpeed(200);
    M2.setSpeed(200);
    M3.setSpeed(200);
    M4.setSpeed(200);
    M1.run(FORWARD);  //Activamos motores adelante
    M2.run(FORWARD);
    M3.run(FORWARD);
    M4.run(FORWARD);
    Serial.println("DETENCTO OPONENTE");
    delay(1000);
   }
  //Buscando oponete
    if (distancia>=21)
   {
    M1.setSpeed(150);
    M2.setSpeed(150);
    M3.setSpeed(150);
    M4.setSpeed(150);
    
    M1.run(BACKWARD);  //Activamos motores adelante
    M2.run(FORWARD);
    M3.run(FORWARD);
    M4.run(BACKWARD);
    Serial.println("DETENCTO OPONENTE");
    delay(10);
   }
}
