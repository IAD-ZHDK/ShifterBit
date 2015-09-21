#include <ESP8266WiFi.h>

WiFiClient client;

void wifi_setup() {
  Serial.print("Joining WiFi...");
  WiFi.begin(config_wifi_ssid, config_wifi_key);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("\nJoined with IP Address: ");  
  Serial.println(WiFi.localIP());
}

