#include <MQTTClient.h>

WiFiClient mqtt_net;
MQTTClient mqtt_client;

void mqtt_setup() {
  mqtt_client.begin(config_mqtt_broker, mqtt_net);
  
  Serial.println("Connecting to shiftr.io...");
  if (mqtt_client.connect(config_mqtt_client_id, config_mqtt_user, config_mqtt_password)) {
    Serial.println("Connected!");

    if(config_subscribe) {
      mqtt_client.subscribe(config_subscribe_topic);
    }
  } else {
    Serial.println("Not connected!");
  }
}

void mqtt_loop() {
  mqtt_client.loop();
}

void messageReceived(String topic, String payload, char * bytes, unsigned int length) {
  Serial.print("incoming: ");
  Serial.print(topic);
  Serial.print(" - ");
  Serial.print(payload);
  Serial.println();
}