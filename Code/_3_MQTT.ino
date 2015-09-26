#include <MQTTClient.h>

MQTTClient mqtt_client;

void mqtt_setup() {
  mqtt_client.begin(config_mqtt_broker, wifi_client);
  
  Serial.print("Connecting to shiftr.io...");
  while (!mqtt_client.connect(config_mqtt_client_id, config_mqtt_user, config_mqtt_password)) {
    Serial.print(".");
  }

  Serial.println("\nConnected!");

  if(config_subscribe) {
    mqtt_client.subscribe(config_subscribe_topic);
  }
}

void mqtt_loop() {
  mqtt_client.loop();
}

void messageReceived(String topic, String payload, char * bytes, unsigned int length) {
  if(config_subscribe) {
    display_touch_out();
    interface_out(payload.toInt());
  }
}
