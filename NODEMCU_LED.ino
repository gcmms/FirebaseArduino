#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "iotteste-cd442.firebaseio.com"
#define FIREBASE_AUTH "UOJyFDfNgasydwYOaTJXnMHFTIZjeaia2x87DZLT"
#define WIFI_SSID "FC-CORP"
#define WIFI_PASSWORD "fcamara@123"

int n = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  //connect to internet
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
  Serial.print("connecting");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); //connect to firebase
}

void loop() {
  n = Firebase.getInt("led");
  Serial.print(n);
  if(n==1){
    Serial.println("Led On");
    Firebase.set("Call", "LED ON");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {     
    Serial.println("Led Off");
    Firebase.set("Call", "LED OFF");
    digitalWrite(LED_BUILTIN, LOW);
  }
}
