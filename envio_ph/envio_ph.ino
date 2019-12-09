/* Monitoramento de pH utilizando sensor de cor RGB TCS34725
 * Universidade Federal do Espírito Santo
 * Lucas Sachetti
 */
 
#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include "ThingSpeak.h"


//Variáveis para comunicação com a plataforma ThingSpeak
unsigned long myChannelNumber = 932062;
const char * myWriteAPIKey = "TMCN3JGPCDJPSJ5E";

#include <ESP8266WiFi.h>

//Variáveis para comunicação Wi-Fi
char ssid[] = "iPhone de Gabriel";   // your network SSID (name)
char pass[] = "12345678";   // your network password
int keyIndex = 0;            // your network key index number (needed only for WEP)
WiFiClient  client;

 
/* Example code for the Adafruit TCS34725 breakout library */
 
/* Connect SCL to analog 5
Connect SDA to analog 4
Connect VDD to 3.3V DC
Connect GROUND to common ground */
 
/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();
 
/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
 
void setup(void) {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);
  
  ThingSpeak.begin(client);
   
  if (tcs.begin()) {
  Serial.println("Found sensor");
  } else {
  Serial.println("No TCS34725 found ... check your connections");
  while (1);
  }

}
 
void loop(void) {

//Fazendo conexão com o Wi-Fi, em caso de erros é feita uma reconexão a cada 5 segundos
  // Connect or reconnect to WiFi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println("iPhone de Gabriel");
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
  
uint16_t r, g, b, c, colorTemp, lux;
 
tcs.getRawData(&r, &g, &b, &c);
colorTemp = tcs.calculateColorTemperature(r, g, b);
lux = tcs.calculateLux(r, g, b);
 
Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
Serial.println(" ");

long ph = 0;

//Medindo o nível de pH de acordo com a intensidade das cores

if (r > g && g > b){
 Serial.println("vermelho");
 if(c >= (10*lux)){
  Serial.println("limão ph 2");
  ph = 2;
  } else {
    Serial.println("vinagre ph 3");
    ph = 3;
  }
}
else if (g > r && g > b){
  Serial.println("verde");
  Serial.println("ph 8 a 11");
  ph = 9;
} else if (r > g && b > g){
  Serial.println("roxo");
  Serial.println("ph de 6 a 8");
  ph = 7;
} else if (r > g && r > (2*b) && g > (2*b)) {
  Serial.println("amarelo");
  Serial.println("ph 12+");
  ph = 12;
}


//Envio do dado de pH para a plataforma

  int httpCode = ThingSpeak.writeField(myChannelNumber, 1, ph, myWriteAPIKey);
  
  if (httpCode == 200) {
    Serial.println("Channel write successful.");
  }
  else {
    Serial.println("Problem writing to channel. HTTP error code " + String(httpCode));
  }







}
