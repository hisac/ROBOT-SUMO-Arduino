int echo = 9;            //  SERVO 2 define el pin 2 como (pecho) para el Ultrasonido
int trig = 10;            // SERVO 1 define el pin 3 como (ptrig) para el Ultrasonido
int duracion, distancia;  // para Calcular distacia

void setup() 
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  //////sensor ultrasonico////
  pinMode(echo, INPUT);   // define el pin 2 como entrada (pecho) 
  pinMode(trig,OUTPUT);   // define el pin 3 como salida  (ptrig) 

  Serial.println("Tiempo de seguridad"); 
  delay(100);          //Tiempo de seguridad
}

void loop() 
{
   digitalWrite(trig, HIGH);   // genera el pulso de trigger por 10us
   delay(0.01);
   digitalWrite(trig, LOW);
   duracion = pulseIn(echo, HIGH);          // Lee el tiempo del Echo
   distancia = (duracion/2) / 29;            // calcula la distancia en centimetros
   delay(1); 
   Serial.print("Distancia: ");
   Serial.print(distancia);
   Serial.println(" cm");
}
