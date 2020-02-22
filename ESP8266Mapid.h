#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
HTTPClient http;
 
String readMapid(String getUrl,int n){
 http.begin(getUrl); 
 http.GET();
 String hasil = http.getString();
 http.end();
 DynamicJsonDocument doc(1024);
 deserializeJson(doc, hasil);
 String  isiVar= doc["last_data"][n-1]["value"];
 return isiVar;
}

void koneksiWifi(String NAMA ,String PSWD){
  WiFi.mode(WIFI_STA);
  WiFi.begin(NAMA, PSWD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}


void sendMapid(String postUrl){
 http.begin(postUrl); 
 http.GET();
 http.end();
}
