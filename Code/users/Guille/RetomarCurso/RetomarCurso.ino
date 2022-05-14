// Initialize
String vers = "RetomarCurso";

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
int dist = 0;


int Direccion = 0;
int PasosDesvio = 0;

int Giro90Grados = 500;
int TiempoEsperaEsquive = 4; //segundos
bool FlagPuedeRetomarCurso = true;
int SegsEspera = 0;
bool FlagMirarAlFrente = false;

void setup()
{

  // Seteo Constantes por tipo Rover (ver Codez)
  //    rover_rojo();
    rover_negro();
  //rover_Sab();
  //rover_DC();
  
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
}//setup


// Main program
void loop()
{
 //Test();
 
  Avanza(100);
  Serial.println("Avanza");
  Serial.println(Direccion);
  dist = distancia(BajoTrig,BajoEcho);
  if(dist<13){
    Serial.println(dist);
    Serial.println("Esquiva");
    Esquiva();
    SegsEspera = (millis()/1000) + TiempoEsperaEsquive;
    FlagMirarAlFrente = true;
    Para();
    delay(500);
  }
 
  if(millis()/1000 < SegsEspera)
  {
    FlagPuedeRetomarCurso = false;
  }
  else
  {
    FlagPuedeRetomarCurso = true;
  }
  
  if(FlagPuedeRetomarCurso)
  {
   RetomarCurso();    
  }
}//endloop

//*****************************  Funciones ******************************

void RetomarCurso(){
  Serial.println("RetomarCurso");
  if(FlagMirarAlFrente == true){
    GirarADireccion(0);
  FlagMirarAlFrente = false;
  }
  else
  {
  if (PasosDesvio > 1000 && Direccion != -1){
    GirarADireccion(-1);
  }
  if(PasosDesvio < -1000 && Direccion != 1){
    GirarADireccion(1);
  }
  if(PasosDesvio < 200 && PasosDesvio > -200 && Direccion != 0){
    GirarADireccion(0);
  }
  }
}//endRetomarCurso

void GirarADireccion(int dir){
  if (dir == -1 && Direccion == 0)
  {
    GiroIzq(Giro90Grados);
    Para();
    delay(500);
  }
  else if (dir == -1 && Direccion == 1){
    GiroIzq(Giro90Grados);
    Para();
    delay(500);
    GiroIzq(Giro90Grados);
    Para();
    delay(500);
  }
  else if(dir == 0 && Direccion == -1){
    GiroDer(Giro90Grados);
    Para();
    delay(500);
  }
  else if(dir == 0 && Direccion == 1){
    GiroIzq(Giro90Grados);
    Para();
    delay(500);
  }
  else if(dir == 1 && Direccion == 0){
    GiroDer(Giro90Grados);
    Para();
    delay(500);
  }
  else if(dir == 1 && Direccion == -1){
    GiroDer(Giro90Grados);
    Para();
    delay(500);
    GiroDer(Giro90Grados);
    Para();
    delay(500);
  }
}//endGirarDireccion

void Esquiva(){
  Para();
  delay(500);
  if (random(2) == 0){
    GiroDer(Giro90Grados);
    Para();
  }
  else{
    GiroIzq(Giro90Grados);
    Para();
  }
  delay(500);
}//endEsquiva

void Test(){
   Avanza(2500);
   Para();
   delay(500);
   GiroDer(Giro90Grados);
   Para();
   delay(500);
   GiroDer(Giro90Grados);
   Para();
   delay(500);
   delay(3000);
}//endTest

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

  if(Direccion == 1)
  {
    PasosDesvio = PasosDesvio + Dly;
  }
  if(Direccion == -1)
  {
    PasosDesvio = PasosDesvio - Dly;
  }
}
void Retrocede(int Dly) {
  analogWrite(PoM1, ValMax1) ;
  analogWrite(PWM1, BackFwdIzq) ;
  analogWrite(PoM2, ValMax2) ;
  analogWrite(PWM2, BackFwdDer) ;
  delay(50);
  analogWrite(PoM1, ValM1) ;
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
  Para();
  delay(500);
  if(Direccion !=1){
    
  analogWrite(PoM1, BackFwdIzq) ;   //izq avanza
  analogWrite(PWM1, ValMax1) ;
  analogWrite(PoM2, ValMax2) ;
  analogWrite(PWM2,BackFwdDer) ;
  delay(50);
  
  analogWrite(PoM1, BackFwdIzq) ;   //izq avanza
  analogWrite(PWM1, ValM1) ;
  analogWrite(PoM2, ValM2) ;
  analogWrite(PWM2,BackFwdDer);
  delay(Dly);
  }

  if (Direccion == 0)
  {
    Direccion = 1;
  }
  else if (Direccion == -1)
  {
    Direccion = 0;
  }
  else if (Direccion == 1)
  {
    GiroIzq(Giro90Grados);
    delay(250);
    GiroIzq(Giro90Grados);
    delay(250);
  }
  
}
void GiroIzq(int Dly) {
  Para();
  delay(500);
  if(Direccion != -1){
    
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

  if (Direccion == 0)
  {
    Direccion = -1;
  }
  else if (Direccion == 1)
  {
    Direccion = 0;
  }
  else if (Direccion == -1)
  {
    GiroDer(Giro90Grados);
    delay(250);
    GiroDer(Giro90Grados);
    delay(250);
  }
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
