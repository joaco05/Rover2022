// Encuentra Umbrales de desicion  FindUmbras() Feb18
//1.- Busca el valor maximo de blanco (ValBlco), 
//      que difiera en >100 con cualquier otro valor 
//2.- Busca el Valor minimo de negro (ValNegro)
//      que difiera en >100 del maximo Blanco(ValBlco)
int ValBlco,ValNegro,Val;
int Lect[20]={40,50,45,30,35,55,290,210,205,290,
              203,240,200,240,222,200,250,204,50,40};
void setup()
{
Serial.begin(9600);         // Inicializo canal de comunicaciones
Serial.println("Start");
pinMode(LED_BUILTIN, OUTPUT);
ValBlco=0; ValNegro=999;  
for (int i = 0; i <= 20; i++) {
  Val=Lect[i];
  if (  (Val>ValBlco)and ((Val-ValBlco)<100) )
      {ValBlco=Val;} // encuentro el valor maximo
 }// For  minimos
  Serial.print("Maximo de los minimos ");
Serial.println(ValBlco);  
  
for (int i = 0; i <= 20; i++) {
  Val=Lect[i];
  if ( (Val<ValNegro) and ((Val-ValBlco)>100) )
       {ValNegro=Val;} // encuentro el valor minimo
 }// For  Maximos
Serial.print("Minimo de los maximos ");
Serial.println(ValNegro);  
  
}// setup

void loop()
{
 
}