#include <Arduino.h>
#include <TinyGPS++.h>
#include <WiFiS3.h>
#include <ArduinoHttpClient.h>
#include <certificate.h>
#include <connection_info.h>
#include <wifi_tools.h>
#include <http_requests.h>
#include <debugger.h>

#define SERIAL_BAUD 9600

TinyGPSPlus gps;
WiFiSSLClient ssl_client;
HttpClient http_client = HttpClient(ssl_client, SERVER_ADDR, SERVER_PORT);

void setup() {
  Serial.begin(SERIAL_BAUD);
  Serial1.begin(SERIAL_BAUD);
  delay(2000);
  wifi_setup();
  ssl_client.setCACert(root_ca_certificate);
  Serial.println("CA_CERT:\tOK");
}

void loop() {
  if (Serial1.available() > 0){
    if(gps.encode(Serial1.read())){
      if(gps.location.isUpdated()){
        printGPSInfo(gps);
        while (WiFi.status() != WL_CONNECTED){
          Serial.println("WIFI_CONNECTION:\tERROR");
          delay(10000);
        }
        post_gps_location(http_client, gps);
        delay(10000);
      }
    }
  }
}



