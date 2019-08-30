//Ultrassonicos
//variáveis para o sensor ultrassônico
long durTras;
long durFrente;
long distTras = 0;
long distFrente = 0;
int minRange = 5;//tempo de resposta do sensor
int maxRange = 200;

//Ultrassonicos
#define trigFrente 2 //é o da frente
#define echoFrente 3 //é o da frente
#define trigTras 12 //é o de trás
#define echoTras 13 //é o de trás

void ligarUltra()
{ 
        //Frente
  digitalWrite(trigFrente,HIGH); //envia o som 
  delayMicroseconds(10); // espera 
  digitalWrite(trigFrente,LOW);//não envia som e espera o retorno 
  durFrente = pulseIn(echoFrente,HIGH);//Captura a duração do tempo do retorno do som
  distFrente = durFrente; //calcula a distancia 1 OBS: APAGUEI O /56
        //Tras
  digitalWrite(trigTras,HIGH); //envia o som 
  delayMicroseconds(10); // espera 
  digitalWrite(trigTras,LOW);//não envia som e espera o retorno 
  durTras = pulseIn(echoTras,HIGH);
  distTras = durTras;// calcula a distancia 2 OBS: APAGUEI O /56
  Serial.println(distFrente); //Exibe a distancia 1 na porta serial
  Serial.println(distTras); // Exibe a distancia 2 na porta serial 
  Serial.println("//////////////");
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //ultrassonico
        //Frente
    pinMode(trigFrente,OUTPUT);//define trig como saída de dados
    pinMode(echoFrente,INPUT);//define o echo como entrada de dados
    digitalWrite(trigFrente,LOW);
        //Tras
    pinMode(trigTras,OUTPUT);//define trig como saída de dados
    pinMode(echoTras,INPUT);
    digitalWrite(trigTras,LOW);
    

}

void loop() {
  // put your main code here, to run repeatedly:
  ligarUltra();

}
