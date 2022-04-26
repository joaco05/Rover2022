const int M1A = 9;  // Connect pin 9 to Motor 1 Diretction A pin
const int M1B = 5;  // Connect pin 5 to Motor 1 Diretction B pin
const int M2A = 10; // Connect pin 10 to Motor 2 Diretction A pin
const int M2B = 6;  // Connect pin 6 to Motor 2 Diretction B pin

byte speed = 255;  // change this (0-255) to control the speed of the motors 

void setup() {
  pinMode(M1A, OUTPUT); // set pins to output
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
}

void loop() {
  forward(); 
  delay(1000);
  backward();
  delay(1000);
  left();
  delay(1000);
  right();
  delay(1000);
}

void backward()
{
  analogWrite(M1A, 0);
  analogWrite(M1B, speed);
  analogWrite(M2A, 0);
  analogWrite(M2B, speed);
}

void forward()
{
  analogWrite(M1A, speed);
  analogWrite(M1B, 0);
  analogWrite(M2A, speed);
  analogWrite(M2B, 0);
}

void left()
{
  analogWrite(M1A, speed);
  analogWrite(M1B, 0);
  analogWrite(M2A, 0);
  analogWrite(M2B, speed);
}

void right()
{
  analogWrite(M1A, 0);
  analogWrite(M1B, speed);
  analogWrite(M2A, speed);
  analogWrite(M2B, 0);
}
