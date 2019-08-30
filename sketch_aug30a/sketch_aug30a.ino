//Motores
int Motor11 = 4;
int Motor12 = 5;

int Motor21 = 6;
int Motor22 = 7;

// Bases para rodas
void esquerdaPara()
{
  digitalWrite(Motor11, LOW);
  digitalWrite(Motor12, LOW);
}
void direitaPara()
{
  digitalWrite(Motor21, LOW);
  digitalWrite(Motor22, LOW);
}
void esquerdaTras()
{
  digitalWrite(Motor11, HIGH);
  digitalWrite(Motor12, LOW);
}
void direitaTras()
{
  digitalWrite(Motor21, HIGH);
  digitalWrite(Motor22, LOW);
}
void esquerdaFrente()
{
  digitalWrite(Motor11, LOW);
  digitalWrite(Motor12, HIGH);
}
void direitaFrente()
{
  digitalWrite(Motor21, LOW);
  digitalWrite(Motor22, HIGH);
}

//Movimentos

void Frente()
{
  direitaFrente();
  esquerdaFrente();
}
void Tras()
{
  direitaTras();
  esquerdaTras();
}
void giroEsquerda()
{
  esquerdaFrente();
  direitaTras();
}
void giroDireita()
{
  direitaFrente();
  esquerdaTras();
}
void parado()
{
  esquerdaPara();
  direitaPara();
}

//CO TCRT


#define tcrt_Direita A4
#define tcrt_Esquerda A5
//#define tcrt_Frente A4

int sensorDireita = 0;
int sensorEsquerda = 0;
int sensorFrente=0;

void ligarTCRT()
{
  delay(900);
    sensorDireita= analogRead(tcrt_Direita);
    sensorEsquerda= analogRead(tcrt_Esquerda);
//    sensorFrente= analogRead(tcrt_Frente);
    Serial.println(sensorDireita); //direita
    Serial.println(sensorEsquerda); //esquerda 
    Serial.println("========");
    
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //MOTORES
    pinMode(Motor11, OUTPUT);
    pinMode(Motor12, OUTPUT);
    pinMode(Motor21, OUTPUT);
    pinMode(Motor22, OUTPUT);

    //TCRT
    pinMode(tcrt_Esquerda, INPUT);
    pinMode(tcrt_Direita, INPUT);
//    pinMode(tcrt_Frente, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  ligarTCRT();
  if(analogRead(tcrt_Direita)<=500)
  {
    esquerdaFrente();
    direitaPara();
    Serial.println("vai para direita");
  }
  if(analogRead(tcrt_Esquerda)<=500)
  {
    direitaFrente();
    esquerdaPara();
    Serial.println("vai para esquerda");
  }
  if(analogRead(tcrt_Direita)>=500 && analogRead(tcrt_Esquerda)>=500)
  {
    //Frente();
   }
   if(analogRead(tcrt_Direita)>=500 && analogRead(tcrt_Esquerda)>=500)
   {
    parado();
    }
}
