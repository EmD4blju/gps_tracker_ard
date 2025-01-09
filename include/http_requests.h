#include <ArduinoHttpClient.h>
#include <TinyGPS++.h>
#include <ArduinoJson.h>

void post_gps_location(HttpClient http_client, TinyGPSPlus gps);