/*

*/
//Motores
int Motor11 = 8;
int Motor12 = 9;

int Motor21 = 10;
int Motor22 = 11;

//Ultrassonicos
//variáveis para o sensor ultrassônico
long duracao;
long duracao_2;
long HR_dist = 0;
long HR_dist_2 = 0;
int minimumRange = 5;//tempo de resposta do sensor
int maximumRange = 200;

//Ultrassonicos
#define trigger_1 4
#define echo_1 2 //é o da frente
#define trigger_2 4
#define echo_2 3 //é o de trás

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

//Ultrassonicos
void ligarUltra()
{
  digitalWrite(trigger_1,HIGH); //envia o som 
  delayMicroseconds(10); // espera 
  digitalWrite(trigger_1,LOW);//não envia som e espera o retorno 
  duracao= pulseIn(echo_1,HIGH);//Captura a duração do tempo do retorno do som
  duracao_2=pulseIn(echo_2,HIGH);
  HR_dist = duracao/56; //calcula a distancia 1
  HR_dist_2 = duracao_2/56;// calcula a distancia 2 
  Serial.begin(9600);
  Serial.println(HR_dist); //Exibe a distancia 1 na porta serial
  Serial.println(HR_dist_2); // Exibe a distancia 2 na porta serial 
}
void setup() {
    pinMode(Motor11, OUTPUT);
    pinMode(Motor12, OUTPUT);
    pinMode(Motor21, OUTPUT);
    pinMode(Motor22, OUTPUT);
    
    //ultrassonico
    pinMode(trigger_1,OUTPUT);//define trig como saída de dados
    pinMode(trigger_2,OUTPUT);
    pinMode(echo_1,INPUT);//define o echo como entrada de dados
    pinMode(echo_2,INPUT);
    digitalWrite(trigger_1,LOW);
    digitalWrite(trigger_2,LOW);
}

void loop() {
    ligarUltra();
    if (HR_dist>20)
    {
      parado();
    }
    else
    {
      giroDireita();
      delay(500);
      giroEsquerda();
      delay(500);
    }  
}
