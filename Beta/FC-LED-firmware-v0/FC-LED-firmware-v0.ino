/*******************************************************************************
  FC LED (v0.0)

  Controlando Placa de Acrilico com fita Led RGB
  Ao ligar a placa ela ficará piscando amarelo até se conectar ao wifi
  Luz vermelha pulsante pode significafr que a mesma não se contectou ao wifi

  Copyright 2019 Fcamara.
  Escrito por Gabriel Chirico Mahtuk de Melo Sanzone

  Para este codigo funcionar corretamente, será nescessario configurar as portas do firebase
*********************************************************************************/
//Definição dos pinos do NodeMCU
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
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h> //Biblioteca que permite chamar o seu modulo ESP8266 na sua rede pelo nome ao inves do IP.
#include <ESP8266HTTPUpdateServer.h> //Biblioteca que cria o servico de atualizacão via wifi (ou Over The Air - OTA)
#include <FirebaseArduino.h>

#define REDPIN D0   //Pino D6 do NodeMCU
#define GREENPIN D1 //Pino D5 do NodeMCU
#define BLUEPIN D2  //Pino D7 do NodeMCU

#define INICAR_CORES_ALEATORIAS 15000 //Tempo ocioso antes de começar a trocar as cores automaticamente

unsigned long ultimoAcessoHost = 0;
unsigned long ultimaTrocaCor = 0;
unsigned long ultimaTrocaCorAutomatica = 0;

boolean trocaAutomatica = 1; //Se voce mudar para 0 (zero), ira desligar a troca automatica de cores.
const char* host      = "ipz-fita-led-esp8266"; //Nome que seu ESP8266 (ou NodeMCU) tera na rede
const char* ssid      = "FC-CORP"; //Nome da rede wifi da sua casa
const char* password  = "fcamara@123"; //Senha da rede wifi da sua casa

int RGB[3];
int cnt = 0;
int tempoTrocaCor = 50; //Velicidade que as cores trocam automaticamente
ESP8266HTTPUpdateServer atualizadorOTA; //Este e o objeto que permite atualizacao do programa via wifi (OTA)
ESP8266WebServer servidorWeb(90); //Servidor Web na porta 80

//Esta e a pagina enviada para o navegador de internet
String paginaWeb = "";
//////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  //Se vc ativou o debugging, devera descomentar esta linha abaixo tambem.
  //Serial.begin(115200);
  InicializaPinos();
  InicializaWifi();
  InicializaMDNS();
  InicializaServicoAtualizacao();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    InicializaWifi();
    InicializaMDNS();
  }
  else {
    if (millis() - ultimoAcessoHost > 10) {
      servidorWeb.handleClient();
      ultimoAcessoHost = millis();
    }
    if (trocaAutomatica && (millis() - ultimaTrocaCor > INICAR_CORES_ALEATORIAS) && (millis() - ultimaTrocaCorAutomatica > tempoTrocaCor)) {
      ultimaTrocaCorAutomatica = millis();
      CoresAleatorias(cnt++, RGB);
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
