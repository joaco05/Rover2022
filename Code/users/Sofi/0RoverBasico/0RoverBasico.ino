// Initialize
String vers = "RoverBasico v1.1 2022Ene26a";

int PWM1   = 6; // Pin Motor 1  (Izq)    PWM1 = ValM1  , PoM1= HIGH => avanza
int PoM1 = 11;   // Pin Motor 1 (Izq)  PWM1 = HIGH  , PoM1= ValM1 => retrocede
int PWM2   = 5; // Pin Motor 2
int PoM2 = 3;   // Pin Motor 2  (Der)
int ValMax1, ValMax2, ValM1, ValM2;
int BackFwdDer,BackFwdIzq;
int BajoTrig = 6; // TRIG Ultrasonido bajo
int BajoEcho = 8;  // ECHO  ultrasonido bajo
int x, y;
int i = 1;     // increment
//  int LED=13;   NO usar,  PIN 13 es para motor (PWM)
long Dis; int length;

void setup()
{

  // Seteo Constantes por tipo Rover (ver Codez)
  //    rover_rojo();
  //  rover_negro();
  rover_DC();
  
  pinMode(PWM1,  OUTPUT);
  pinMode(PoM1,   OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(PoM2, OUTPUT);
  pinMode(BajoTrig, OUTPUT);
  pinMode(BajoEcho, INPUT);
  
  Serial.begin(9600);         // Inicializo canal de comunicaciones
  Serial.println("Start");
  Dis=distancia(BajoTrig,BajoEcho);
  Serial.print("Version: "); Serial.println(vers);
  Serial.print("Rover: "); Serial.print(Dis);
  delay(2000);//Para dar tiempo luego de programarlo /conectar bateria
Avanza(1000); 
GiroDer(1000);
Para();delay(300);
GiroIzq(1000);
Para();delay(300);
}//setup


// Main program
void loop()
{
Arranca();
Avanza(400);
GiroDer(200);
GiroIzq(200);
Avanza(200);
delay(2000);


}//endloop

//*****************************  Funciones ******************************

void Arranca(){// Potencia maxima para vencer inercia del motor
  analogWrite(PoM1, BackFwdIzq) ;  // High en rover
  analogWrite(PWM1, ValMax1) ;
  analogWrite(PoM2, BackFwdDer) ;   // High en rover
  analogWrite(PWM2, ValMax2);
  delay(80);

}
void Avanza(int Dly) {
  analogWrite(PoM1, BackFwdIzq) ;  // High en rover
  analogWrite(PWM1, ValM1) ;
  analogWrite(PoM2, BackFwdDer) ;   // High en rover
  analogWrite(PWM2, ValM2);
  delay(Dly);
}
void Retrocede(int Dly) {
  analogWrite(PoM1, ValMax1) ;
  analogWrite(PWM1, BackFwdIzq) ;
  analogWrite(PoM2, ValMax2) ;
  analogWrite(PWM2, BackFwdDer) ;
  delay(50);
  analogWrite(PoM1, ValM1-30) ;
  analogWrite(PWM1, BackFwdIzq) ;
  analogWrite(PoM2, ValM2-30) ;
  analogWrite(PWM2, BackFwdDer) ;
  delay(Dly);
}
void Para() {
  digitalWrite(PoM1, LOW) ;
  digitalWrite(PoM2, LOW) ;
  digitalWrite(PWM1, LOW) ;
  digitalWrite(PWM2, LOW) ;
  delay(10);
}
void GiroDer(int Dly) {
  analogWrite(PoM1, BackFwdIzq) ;   //izq avanza
  analogWrite(PWM1, ValMax1) ;
  analogWrite(PoM2, ValMax2) ;
  analogWrite(PWM2,BackFwdDer ) ;
  delay(50);
  
  analogWrite(PoM1, BackFwdIzq) ;   //izq avanza
  analogWrite(PWM1, ValM1-10) ;
  analogWrite(PoM2, ValM2-10) ;
  analogWrite(PWM2,BackFwdDer );
  delay(Dly);
}
void GiroIzq(int Dly) {
  analogWrite(PoM1, ValMax1) ;   //izq retrocede
  analogWrite(PWM1, BackFwdIzq) ;
  analogWrite(PoM2, BackFwdDer) ;
  analogWrite(PWM2,ValMax2 ) ;
  delay(50);
 
  analogWrite(PoM1, ValM1) ;   //Motor izq retrocede
  analogWrite(PWM1, BackFwdIzq) ;
  analogWrite(PoM2, BackFwdDer) ;
  analogWrite(PWM2, ValM2);
  delay(Dly);
}


void ArcoDer(int Dly) {
  analogWrite(PoM1, HIGH) ;  // High en rover
  analogWrite(PWM1, ValM1) ;
  analogWrite(PoM2, 0) ;   // High en rover
  analogWrite(PWM2, 0);
  delay(Dly); 
}

void ArcoIzq(int Dly) {
  analogWrite(PoM1, 0) ;  // High en rover
  analogWrite(PWM1, 0) ;
  analogWrite(PoM2, HIGH) ;   // High en rover
  analogWrite(PWM2, ValM2);
  delay(Dly);
}



long distancia(int Trig, int Echo) { //Mide la distancia y la guarda en "cm"
  long resultado; long Tiempo_us;
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  Tiempo_us = pulseIn(Echo, HIGH, 4060);
  resultado = Tiempo_us / 58;
  delay(100); // Verificar
  if (Tiempo_us == 0) {
    resultado = 199;
  }
  return resultado;
} // distancia

// End.
