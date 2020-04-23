#include<ESP8266Mapid.h>

String keyGet  = "isi_keyGet_Mapid";
String getUrl= "http://api.mapid.io/api/request?key=" + keyGet; 

void setup() {
  Serial.begin(9600);
  koneksiWifi("SSID","PASSWORD");
}
 
void loop() {
  // Perintah ambil data dari server mapid
  String data1 = readMapid(getUrl,1); // membaca data variabel ke-1
  Serial.println(data1);
  String data2 = readMapid(getUrl,2); // membaca data variabel ke-2, dst
  Serial.println(data2);
}
