/*******************************************************************************
  FC LED (v1.0)

  Controlando Placa de Acrilico com fita Led RGB
  Ao ligar a placa ela ficará piscando amarelo até se conectar ao wifi
  Luz vermelha pulsante pode significafr que a mesma não se contectou ao wifi

  Copyright 2019 Fcamara.
  Escrito por Gabriel Chirico Mahtuk de Melo Sanzone

  Para este codigo funcionar corretamente, será nescessario configurar as portas do firebase
*********************************************************************************/
static const uint8_t D0 = 16;
static const uint8_t D1 = 5;
static const uint8_t D2 = 4;
static const uint8_t D3 = 0;
static const uint8_t D4 = 2;
static const uint8_t D5 = 14;
static const uint8_t D6 = 12;
static const uint8_t D7 = 13;
static const uint8_t D8 = 15;
static const uint8_t D9 = 3;
static const uint8_t D10 = 1;


#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Definicao do Firebase
#define FIREBASE_HOST "iotteste-cd442.firebaseio.com"
#define FIREBASE_AUTH "UOJyFDfNgasydwYOaTJXnMHFTIZjeaia2x87DZLT"

//Configuração de Rede Wifi
#define WIFI_SSID "FC-CORP"
#define WIFI_PASSWORD "fcamara@123"
//Pinos da placa
#define VERMELHO D0  //D0
#define VERDE    D1  //D1
#define AZUL     D2  //D2

int n = 0;
int r = 0;
int g = 0;
int b = 0;
//Definicao de Variavel para Animacao do LED ao carregar WIFI
int brightness = 0;     //Inicio do LED vermelho
int fadeAmount = 100;    // em quantos pontos aplicar o fade no LED

void setup() {
  Serial.begin(115200);
  pinMode(VERMELHO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);

  //Conctando a rede WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando ....");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    aguardandoWiFi();
    delay(500);
  }
  define_led(218, 52, 237);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); //connect to firebase
  delay(2000);
}

void loop() {
  Serial.println("teste");
  n = Firebase.getInt("led");
  if (n == 1) {
    Serial.println("Led On");
    Firebase.set("Call", "LED ON");
    r = Firebase.getInt("red");
    g = Firebase.getInt("green");
    b = Firebase.getInt("blue");
    define_led(r, g, b);

  } else {
    Serial.println("Led Off");
    Firebase.set("Call", "LED OFF");
    define_led(0, 0, 0);
  }
}
