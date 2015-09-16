#include <Bridge.h>
#include <FileIO.h>
#include <YunMQTTClient.h>

char configUser[32] = "";
char configPassword[32] = "";
char configClientId[32] = "";
char configPublishTopic[32] = "";
char configSubscribeTopic[32] = "";

YunMQTTClient client("broker.shiftr.io");

unsigned long lastMillis = 0;

void setup() {
  Bridge.begin();
  Serial.begin(9600);
  FileSystem.begin();

  Serial.println("Upadting Bridge...");
  client.installBridge(false);

  Serial.println("Reading Config...");
  readConfig();
  printConfig();

  Serial.println("Connecting...");
  if (client.connect(configClientId, configUser, configPassword)) {
    Serial.println("Connected!");
    client.subscribe(configSubscribeTopic);
  } else {
    Serial.println("Not connected!");
  }
}

void loop() {
  client.loop();
  
  if(millis() - lastMillis > 300 && strlen(configPublishTopic) > 0) {
    lastMillis = millis();
    client.publish(configPublishTopic, String(analogRead(0)));
  }
}

void messageReceived(String topic, String payload, char * bytes, unsigned int length) {
  analogWrite(3, payload.toInt() / 4);
}
