#include<ESP8266Mapid.h>

int sensor1,sensor2,sensor3;
String keyPost = "isi_keyPost_Mapid";

void setup() {
  koneksiWifi("SSID","PASSWORD");
}
 
void loop() {
  //Nilai Random ini hanya contoh
  sensor1=random(0,100);
  sensor2=random(0,100);
  sensor3=random(0,100);
  String postUrl = "http://api.mapid.io/api/update?key=" 
                + keyPost
                + "&var1=" 
                + String(sensor1) 
                + "&var2=" 
                + String(sensor2)
                + "&var3="
                + String(sensor3);
                
  // Perintah kirim data ke server mapid
  sendMapid(postUrl);
  delay(5000);
}
