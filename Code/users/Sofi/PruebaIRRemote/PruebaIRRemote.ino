#include <IRremote.h>

const int RECV_PIN = A1;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("hola usuario,");
}

void loop(){
  if (irrecv.decode(&results)){
    Serial.println("hola control");
        Serial.println(results.value, HEX);
        if(results.value==0xC1AA0DF2){Serial.println("arriba");} //solucion :)
//        if(results.value==C1AA4DB2){}
//        if(results.value==C1AACD32){}
//        if(results.value==C1AA8D72){}
//        if(results.value==C1AAA15E){}
//        if(results.value==C1AA59A6){}
//        if(results.value==C1AA21DE){}
//        if(results.value==C1AAF906){}
//        if(results.value==C1AAD926){}
//        if(results.value==C1AA29D6){}
//        if(results.value==C1AAC936){}
//        if(results.value==C1AA49B6){}
//        if(results.value==C1AAA956){}
        irrecv.resume();
  
  }
}
