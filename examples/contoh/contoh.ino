#include<ESP8266Mapid.h>

int sensor1,sensor2,sensor3;
String keyPost = "isi_keyPost_Mapid";
String keyGet  = "isi_keyGet_Mapid";
String getUrl= "http://api.mapid.io/api/request?key="
                + keyGet; 

void setup() {
  Serial.begin(9600);
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

  // Perintah ambil data dari server mapid
  String data1 = readMapid(getUrl,1); // membaca data variabel ke-1
  Serial.println(data1);
  String data2 = readMapid(getUrl,2); // membaca data variabel ke-2, dst
  Serial.println(data2);
}
