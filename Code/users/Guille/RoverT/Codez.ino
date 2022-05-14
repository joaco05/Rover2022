 
 void rover_rojo(){
  
 ValMax1   = 255; //Valor maximo motor izquierdo
 ValMax2   = 235; //Valor maximo motor derecho
 ValM1   = 220; // Potencia Motor Izq
 ValM2   = 170; // Potencia Motor Der // cambie la potencia,estaba en 175
 
 }
 void rover_negro(){
 
 ValMax1   = 255; //Valor maximo motor izquierdo
 ValMax2   = 255; //Valor maximo motor derecho
 BackFwdIzq=1;
 BackFwdDer=1;
 ValM1   = 250; // Potencia Motor Izq
 ValM2   = 200; // Potencia Motor Der
 PWM1   = 6; // Pin Motor 1  (Der)    PWM1 = ValM1  , PoM1= HIGH => avanza
 PoM1 = 11;   // Pin Motor 1 (Der)  PWM1 = HIGH  , PoM1= ValM1 => retrocede
 PWM2   = 5; // Pin Motor 2  
 PoM2 = 3;   // Pin Motor 2  (Izq)
 BajoTrig = 10; // TRIG Ultrasonido bajo
 BajoEcho = 9;  // ECHO  ultrasonido bajo
 
  }  

void rover_DC(){
 ValMax1   = 130; //Valor maximo motor izquierdo
 ValMax2   = 130; //Valor maximo motor derecho
 BackFwdIzq=1;
 BackFwdDer=1;
 //S3 ValM1 = 90 ValM2 = 110
 ValM1   = 90; // Potencia Motor Izq
 ValM2   = 110; // Potencia Motor Der
 PWM1   = 11; // Pin Motor 1  (Der)    PWM1 = ValM1  , PoM1= HIGH => avanza
 PoM1 = 6;   // Pin Motor 1 (Der)  PWM1 = HIGH  , PoM1= ValM1 => retrocede
 PWM2   = 5; // Pin Motor 2  
 PoM2 = 3;   // Pin Motor 2  (Izq)
 BajoTrig = 13; // TRIG Ultrasonido bajo
 BajoEcho = 12;  // ECHO  ultrasonido bajo
    
  }  
  
  void rover_Sab(){
 ValMax1   = 255; //Valor maximo motor izquierdo
 ValMax2   = 255; //Valor maximo motor derecho
 BackFwdIzq=0;
 BackFwdDer=0;
 ValM1   = 250; // Potencia Motor Izq
 ValM2   = 250; // Potencia Motor Der
 PWM1   = 11; // Pin Motor 1  (Der)    PWM1 = ValM1  , PoM1= HIGH => avanza
 PoM1 = 10;   // Pin Motor 1 (Der)  PWM1 = HIGH  , PoM1= ValM1 => retrocede
 PWM2   = 5; // Pin Motor 2  
 PoM2 = 3;   // Pin Motor 2  (Izq)
 BajoTrig = 6; // TRIG Ultrasonido bajo
 BajoEcho = 7;  // ECHO  ultrasonido bajo
    
  }
// Chequea memoria RAM libre en tiempo de ejecucion
// SRAM para  ATmega328p = 2048Kb.
int availableMemory() {
    // Use 1024 with ATmega168
    int size = 2048;
    byte *buf;
    while ((buf = (byte *) malloc(--size)) == NULL);
        free(buf);
    return size;
}
