#include <Arduino.h>
#include <TinyGPS++.h>

void printGPSInfo(TinyGPSPlus gps){
  Serial.print("Lat:\t"); 
  Serial.println(gps.location.lat(), 6);
  Serial.print("Lon:\t"); 
  Serial.println(gps.location.lng(), 6);
  Serial.print("Sat:\t");
  Serial.println(gps.satellites.value());
}