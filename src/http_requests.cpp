#include <ArduinoHttpClient.h>
#include <TinyGPS++.h>
#include <ArduinoJson.h>

void post_gps_location(HttpClient http_client, TinyGPSPlus gps){
    Serial.println("LOCATION:\tUPDATE");
    JsonDocument location;
    String json_location;
    location["gps_id"] = "ead729d4-1c95-4719-ba39-cb6ccfc808c8";
    location["lat"] = gps.location.lat();
    location["lon"] = gps.location.lng();
    serializeJson(location, json_location);
    Serial.print("SENDING: ");
    Serial.println(json_location);
    http_client.post("/gps", "application/json", json_location);
    int status_code = http_client.responseStatusCode();
    String response = http_client.responseBody();
    Serial.print("RESPONSE: ");
    Serial.println(response);
    Serial.print("STATUS_CODE: ");
    Serial.println(status_code);
    http_client.stop();
}