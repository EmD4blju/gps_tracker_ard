#include <Arduino.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <WiFiS3.h>
#include <secrets.h>
#include <wifi_tools.h>

#define GPS_BAUD 9600
#define SERIAL_BAUD 9600
#define RX_PIN 5
#define TX_PIN 4

TinyGPSPlus gps;
SoftwareSerial ss(RX_PIN, TX_PIN);
int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(SERIAL_BAUD);
  ss.begin(GPS_BAUD);
  delay(2000);
  if(WiFi.status() == WL_NO_MODULE){
    Serial.println("WiFi module: ERROR");
    while(true) {}
  }
  Serial.println("WiFi module: OK");
  if (WiFi.firmwareVersion() < WIFI_FIRMWARE_LATEST_VERSION){
    Serial.println("Firmware: ERROR");
  }else{
    Serial.println("Firmware: OK");
  }
  while (status != WL_CONNECTED){
    Serial.println("Establishing connection...");
    status = WiFi.begin(WIFI_SSID, WIFI_PASS);
  }
  Serial.println("** WIFI CONNECTION ESTABLISHED **");
  printCurrentNetInfo();
}

void loop() {
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude=   "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude=   "); 
      Serial.println(gps.location.lng(), 6);
    }
  }
}

