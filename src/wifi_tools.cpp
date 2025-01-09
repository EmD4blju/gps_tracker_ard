#include <WiFiS3.h>
#include <wifi_pass.h>

void printCurrentNetInfo() {
  Serial.print("SSID:\t");
  Serial.println(WiFi.SSID());

  long rssi = WiFi.RSSI();
  Serial.print("RSSI:\t");
  Serial.print(rssi);
  Serial.println("dBm");
}

void wifi_setup(){
  int status = WL_IDLE_STATUS;
  if(WiFi.status() == WL_NO_MODULE){
    Serial.println("WIFI_MODULE:\tERROR");
    while(true) {}
  }
  Serial.println("WIFI_MODULE:\tOK");
  if (WiFi.firmwareVersion() < WIFI_FIRMWARE_LATEST_VERSION){
    Serial.println("FIRMWARE:\tERROR");
  }else{
    Serial.println("FIRMWARE:\tOK");
  }
  while (status != WL_CONNECTED){
    Serial.println("CONNECTION:\tAWAITING");
    status = WiFi.begin(WIFI_SSID, WIFI_PASS);
  }
  Serial.println("** WIFI CONNECTION ESTABLISHED **");
  printCurrentNetInfo();
}