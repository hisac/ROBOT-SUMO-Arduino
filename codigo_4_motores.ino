/* Ejercicio I: Realizar código de control de 4 motores de forma 
  síncrona hacia adelante, detenerse y atrás. */
  
#include <AFMotor.h> //incluimos libreria de shield motor
AF_DCMotor M1(1); //motor uno conectar en M1
AF_DCMotor M2(2); //motor uno conectar en M2
AF_DCMotor M3(3); //motor uno conectar en M3
AF_DCMotor M4(4); //motor uno conectar en M4

int vel=200; //Variable de velocidad

void setup() 
{
  M1.run(RELEASE); //motor inicia apagado
  M2.run(RELEASE); //motor inicia apagado
  M3.run(RELEASE); //motor inicia apagado
  M4.run(RELEASE); //motor inicia apagado
  delay(2000);
}

void loop() 
{   
  //ADELANTE//
    M1.setSpeed(vel); //Escribe la velocidad
    M2.setSpeed(vel); //Escribe la velocidad
    M3.setSpeed(vel); //Escribe la velocidad
    M4.setSpeed(vel); //Escribe la velocidad
    M1.run(FORWARD);  //Gira hacia adelante
    M2.run(FORWARD);  //Gira hacia adelante
    M3.run(FORWARD);  //Gira hacia adelante
    M4.run(FORWARD);  //Gira hacia adelante
    delay(3000);
    
    //DETENERSE//
    M1.run(RELEASE);  //Gira hacia adelante
    M2.run(RELEASE);  //Gira hacia adelante
    M3.run(RELEASE);  //Gira hacia adelante
    M4.run(RELEASE);  //Gira hacia adelante
    delay(500);
   
   //ATRAS//
    M1.setSpeed(vel); //Escribe la velocidad
    M2.setSpeed(vel); //Escribe la velocidad
    M3.setSpeed(vel); //Escribe la velocidad
    M4.setSpeed(vel); //Escribe la velocidad
    M1.run(BACKWARD);  //Gira hacia adelante
    M2.run(BACKWARD);  //Gira hacia adelante
    M3.run(BACKWARD);  //Gira hacia adelante
    M4.run(BACKWARD);  //Gira hacia adelante
    delay(500);

}
