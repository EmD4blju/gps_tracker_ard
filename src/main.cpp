#include <Arduino.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define GPS_BAUD 9600
#define SERIAL_BAUD 9600
#define RX_PIN 5
#define TX_PIN 4

TinyGPSPlus gps;

SoftwareSerial ss(RX_PIN, TX_PIN);

void setup() {
  Serial.begin(SERIAL_BAUD);
  ss.begin(GPS_BAUD);
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
