#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Smart_Methods1_5g";
const char* password = "123456";

const String url = "https://s-m.com.sa/f.html";
String payload = "";
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  pinMode(25, OUTPUT);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("OK! IP=");
  Serial.println(WiFi.localIP());

  Serial.print("Fetching " + url + "... ");

}

void loop() {
  HTTPClient http;
  http.begin(url);
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    Serial.print("HTTP ");
    Serial.println(httpResponseCode);
    payload = http.getString();
    Serial.println();
    Serial.println(payload);
   if(payload == "forward"){
       digitalWrite(25,HIGH);
    }
   if( payload == "stop" ){
      digitalWrite(25, LOW);
    }
     if( payload == "right" ){
      digitalWrite(32, HIGH);
    }
     if( payload == "left" ){
      digitalWrite(35, HIGH);
    }
      if( payload == "backward" ){
      digitalWrite(33, HIGH);
    }
 }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
    Serial.println(":-(");
  }
 
}
