//Servos
#include <Servo.h>
#define SERVO 8 // Servo daEsquerda
#define SERVO2 9 // Servo da Direita
#define SERVO3 10 // Servo da Base
#define SERVO4 11 // Servo da Garra
 
Servo s1; // Variável Servo
int pos1; // Posição Servo

Servo s2; // Variável Servo
int pos2; // Posição Servo

Servo s3; // Variável Servo
int pos3; // Posição Servo

Servo s4; // Variável Servo
int pos4; // Posição Servo

void servo(Servo servo, int pos, int n) 
{
  for(pos = pos; pos < n; pos++)
  {
    servo.write(pos);
    delay(100);
  }
delay(1000);
  for(pos = pos; pos >= n; pos--)
  {
    servo.write(pos);
    delay(100);
  }
} // Move o Servo servo da posição pos à posição n

void Agarrar(){
  s4.write(90);
  s1.write(60);
  s2.write(100);
  s3.write(0);
}

void setup() {
  // put your setup code here, to run once:
  //servo
    s1.attach(SERVO);
    s1.write(180);
    s2.attach(SERVO2);
    s2.write(180);
    s3.attach(SERVO3);
    s3.write(90);
    s4.attach(SERVO4);
    s4.write(90);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);

  delay(1000);
}
