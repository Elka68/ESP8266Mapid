#include<ESP8266Mapid.h> 
#include "DHT.h"

#define DHTPIN 5 // GPIO5  (D1)
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
String keyPost = "ISI KEY POST";

void setup() {  
  koneksiWifi("SSID","PASSWORD");
  dht.begin();
} 
void loop() { 
 float h = dht.readHumidity();
 float t = dht.readTemperature();
  String postUrl = "http://api.mapid.io/api/update?key=" 
                 + keyPost 
                 + "&var1="                 
                 + String(t)                 
                 + "&var2="                 
                 + String(h);                
  // Perintah kirim data ke server mapid 
  sendMapid(postUrl); 
  delay(5000);
}
