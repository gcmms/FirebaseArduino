/*******************************************************************************
* FC LED (v1.0)
*  
* Controlando Placa de Acrilico com fita Led RGB
* Ao ligar a placa ela ficará piscando amarelo até se conectar ao wifi 
* Luz vermelha pulsante pode significafr que a mesma não se contectou ao wifi
*
* Copyright 2019 Fcamara.
* Escrito por Gabriel Chirico Mahtuk de Melo Sanzone
*
*Para este codigo funcionar corretamente, será nescessario configurar as portas do firebase
*********************************************************************************/

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Definicao do Firebase
#define FIREBASE_HOST "iotteste-cd442.firebaseio.com"
#define FIREBASE_AUTH "UOJyFDfNgasydwYOaTJXnMHFTIZjeaia2x87DZLT"

//Configuração de Rede Wifi
#define WIFI_SSID "FC-CORP"
#define WIFI_PASSWORD "fcamara@123"

//Pinos da placa 
#define VERMELHO 16  //D0
#define VERDE  05  //D1
#define AZUL     04  //D2

int n = 0;
//Definicao de Variavel para Animacao do LED ao carregar WIFI
int brightness = 0;     //Inicio do LED vermelho
int fadeAmount = 50;    // em quantos pontos aplicar o fade no LED

 void setup() {

  pinMode(VERMELHO,OUTPUT);
  pinMode(VERDE,OUTPUT);
  pinMode(AZUL,OUTPUT);
  
  //Conctando a rede WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
  Serial.print("Conectando ....");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    aguardandoWiFi();
    delay(500);
  }
  define_led(218, 52, 237);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); //connect to firebase
  delay(2000);
}

void loop() {

  n = Firebase.getInt("led");
  if(n==1){
    Serial.println("Led On");
    Firebase.set("Call", "LED ON");
    define_led(0, 255, 0);

  } else if ( n == 0){
     //ERRO DE COMUNICACAO
     define_led(255, 0, 0);
  }else {     
    Serial.println("Led Off");
    Firebase.set("Call", "LED OFF");
    define_led(0, 0, 0);
  }
}


void define_led(int R, int G, int B){
  analogWrite(VERMELHO, R);
  analogWrite(VERDE, G);
  analogWrite(AZUL, B);
 }

void aguardandoWiFi(){
  define_led(brightness,brightness,brightness);
  analogWrite(VERMELHO, brightness);    
  // muda o brilho para o proximo loop:
  brightness = brightness + fadeAmount;
  // inverte a direcao do fade ao final do mesmo:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }    
}
 
