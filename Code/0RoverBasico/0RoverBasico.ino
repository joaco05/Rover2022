// Initialize
String vers = "RoverBasico v1.1 2022Ene26";

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
long Dis; 
int IRDer = A0;
int IRIzq = A1;
int IRValue = 0;
#define Debug 1
#if Debug ==1
 #define Print(x) Serial.print(x)
 #define Println(x) Serial.println(x)
#else
 #define Print(x)
 #define Println(x)
#endif

void setup()
{

  // Seteo Constantes por tipo Rover (ver Codez)
  //    rover_rojo();
  //  rover_negro();
  //rover_Sab();
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
Avanza(2000); 
GiroDer(2000);
Para();delay(300);
//GiroIzq(1000);
Para();delay(300);
}//setup


// Main program
void loop()
{
Dis=distancia(BajoTrig,BajoEcho);
if ((Dis<15)) {GiroIzq(1000); }
Print("Dist: "); Println(Dis);
Avanza(100); 
//IRValue = analogRead(A0);
//Print("Der: "); Println(IRValue);
//IRValue = analogRead(A1);
//Print("Izq: "); Println(IRValue);

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
  delay(5);
  
  analogWrite(PoM1, BackFwdIzq) ;   //izq avanza
  analogWrite(PWM1, ValM1) ;
  analogWrite(PoM2, ValM2) ;
  analogWrite(PWM2,BackFwdDer );
  delay(Dly);
}
void GiroIzq(int Dly) {
  analogWrite(PoM1, ValMax1) ;   //izq retrocede
  analogWrite(PWM1, BackFwdIzq) ;
  analogWrite(PoM2, BackFwdDer) ;
  analogWrite(PWM2,ValMax2 ) ;
  delay(5);
 
  analogWrite(PoM1, ValM1) ;   //Motor izq retrocede
  analogWrite(PWM1, BackFwdIzq) ;
  analogWrite(PoM2, BackFwdDer) ;
  analogWrite(PWM2, ValM2);
  delay(Dly);
}


void ArcoDer() {
  analogWrite(PoM1, HIGH) ;   //Motor izq retrocede
  analogWrite(PWM1, ValM1) ;
  analogWrite(PoM2, LOW) ;
  analogWrite(PWM2, LOW) ;
}

void ArcoIzq() {
  analogWrite(PoM1, 0) ;   //Motor izq
  analogWrite(PWM1, 0) ;
  analogWrite(PoM2, 255) ;
  analogWrite(PWM2, ValM2) ;
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
