
 void rover_rojo(){
 TEsqIzq = 770; // Tiempo de esquiva Giro izquierdo
 TEsqDer = 750; // Tiempo de esquiva Giro derecho
 DistDetect=15; //Distancia minima //para esquivar lo cambie estaba en 15
 TPorPasos = 150; // Cant de Tiempo (mS) a avanzar por cada paso programado (depende de cada bot)//lo cambie estaba en 250
 PasosPorCm = 1; // Cant de pasos por cada CM medido en el seteo del juego
 ValMax1   = 255; //Valor maximo motor izquierdo
 ValMax2   = 255; //Valor maximo motor derecho
 ValM1   = 250; // Potencia Motor Izq
 ValM2   = 250; // Potencia Motor Der // cambie la potencia,estaba en 175
 BackFwdIzq=1;
 BackFwdDer=1;
 PWM1   = 6; // Pin Motor 1  (Izq)    PWM1 = ValM1  , PoM1= HIGH => avanza
 PoM1 = 11;   // Pin Motor 1 (Izq)  PWM1 = HIGH  , PoM1= ValM1 => retrocede
 PWM2   = 5; // Pin Motor 2  
 PoM2 = 3;   // Pin Motor 2  (Der)
 }
void rover_rojo_mesa(){
 TEsqIzq = 770; // Tiempo de esquiva Giro izquierdo
 TEsqDer = 750; // Tiempo de esquiva Giro derecho
 DistDetect=15; //Distancia minima //para esquivar lo cambie estaba en 15
 TPorPasos = 150; // Cant de Tiempo (mS) a avanzar por cada paso programado (depende de cada bot)//lo cambie estaba en 250
 PasosPorCm = 1; // Cant de pasos por cada CM medido en el seteo del juego
 ValMax1   = 255; //Valor maximo motor izquierdo
 ValMax2   = 255; //Valor maximo motor derecho
 ValM1   = 120; // Potencia Motor Izq
 ValM2   = 120; // Potencia Motor Der // cambie la potencia,estaba en 175
 BackFwdIzq=1;
 BackFwdDer=1;
 PWM1   = 6; // Pin Motor 1  (Izq)    PWM1 = ValM1  , PoM1= HIGH => avanza
 PoM1 = 11;   // Pin Motor 1 (Izq)  PWM1 = HIGH  , PoM1= ValM1 => retrocede
 PWM2   = 5; // Pin Motor 2  
 PoM2 = 3;   // Pin Motor 2  (Der)
 }
