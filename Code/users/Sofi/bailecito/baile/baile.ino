 String vers = "Sensor IR vers 0.1  2019May22";
int TipoRover=2;// 1-Rojo 2-Negro
int sensorIzqPin = A0;    // 
int sensorDerPin = A1;    // 
int sensorIzqValue = 0;    // 
int sensorDerValue = 0;    // 
int ledPin = 13;      //
int BackFwdDer,BackFwdIzq;
int TEsqIzq = 1; // Tiempo de esquiva Giro izquierdo
int TEsqDer = 1; // Tiempo de esquiva Giro derecho
int DistDetect = 1; //Distancia minima //para esquivar lo cambie estaba en 15
int TPorPasos = 0; // Cant de Tiempo (mS) a avanzar por cada paso programado (depende de cada bot)//lo cambie estaba en 250
int PasosPorCm = 0; // Cant de pasos por cada CM medido en el seteo del juego
int ValMax1 = 200; //Valor maximo motor izquierdo
int ValMax2 = 200; //Valor maximo motor derecho
int ValM1 = 200; // Potencia Motor Izq
int ValM2 = 200; // Potencia Motor Der // cambie la potencia,estaba en 175
//******************************************


int Pasos = 0;//Cant de pasos seteados (se decrementa por cada Avance/Giro)
//boolean goUp = true ; // Used to detect acceleration or deceleration
int PWM1   = 6; // Pin Motor 1  (Izq)    PWM1 = ValM1  , PoM1= HIGH => avanza
int PoM1 = 11;   // Pin Motor 1 (Izq)  PWM1 = HIGH  , PoM1= ValM1 => retrocede
int PWM2   = 5; // Pin Motor 2  
int PoM2 = 3;   // Pin Motor 2  (Der)
int BajoTrig = 10 ; // TRIG Ultrasonido bajo
int BajoEcho = 9;  // ECHO  ultrasonido bajo
int PinBotonA = 7; int BotonA;
int x,y;
int i = 1;     // increment 
int Obs = 0; 
int HN,HNmax;//unbrales de negro
int ValBlco,ValNegro,Val;
int Lect[20];
int umbral;



void setup() {
  
  // Seteo Constantes por tipo Rover (ver Codez)
  //rover_rojo_mesa();
  //rover_rojo();
  //rover_negro();
  //rover_Sab();
  rover_DC();
  
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  delay (50);
  Serial.println("Start");
  Serial.print("Version: "); Serial.println(vers);
  delay (50);


Avanza(500);
GiroDer(400);
GiroIzq(400);
Avanza(200);
Para();

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
void Para(){
    delay (100);
    digitalWrite(PoM1, LOW) ;   // Both motor with same polarity
    digitalWrite(PoM2, LOW) ;  
    digitalWrite(PWM1, LOW) ;   // Both motor with same polarity
    digitalWrite(PWM2, LOW) ;   
    delay(10);
}
void Avanza(int Dly) {
  analogWrite(PoM1, HIGH) ;  // High en rover
  analogWrite(PWM1, ValM1) ;
  analogWrite(PoM2, HIGH) ;   // High en rover
  analogWrite(PWM2, ValM2);
  delay(Dly);
  
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
