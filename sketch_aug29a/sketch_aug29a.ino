//tcrt
#define tcrt_Direita A5
#define tcrt_Esquerda A3
#define tcrt_Frente A4

int sensorDireita = 0;
int sensorEsquerda = 0;
int sensorFrente=0;

void ligarTCRT()
{
    sensorDireita= analogRead(tcrt_Direita);
    sensorEsquerda= analogRead(tcrt_Esquerda);
    sensorFrente= analogRead(tcrt_Direita);
    Serial.println(sensorDireita); //direita
    Serial.println(sensorEsquerda); //esquerda 
    Serial.println(sensorFrente); //Frente 
    Serial.println("========");
    delay(900);
}

void setup() {
  // put your setup code here, to run once:
  //TCRT
    pinMode(tcrt_Esquerda, INPUT);
    pinMode(tcrt_Direita, INPUT);
    pinMode(tcrt_Frente, INPUT);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ligarTCRT();

}
