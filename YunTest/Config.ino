const char * _cu = "mqtt_user: ";
const char * _cp = "mqtt_password: ";
const char * _ci = "mqtt_client_id: ";
const char * _pt = "publish_topic: ";
const char * _st = "subscribe_topic: ";

void readConfig() {
  File fd = FileSystem.open("/mnt/sd/arduino/config.txt", FILE_READ);
  while(fd.available() > 0) {
    readConfigLine(fd.readStringUntil('\n'));
  }
  fd.close();
}

 void readConfigLine(String c) {
  int colon = c.indexOf(": ");
  
    if (c.startsWith(_cu)) {
      c.substring(colon + 2).toCharArray(configUser, 32);
    } else if(c.startsWith(_cp)) {
      c.substring(colon + 2).toCharArray(configPassword, 32);
    } else if(c.startsWith(_ci)) {
      c.substring(colon + 2).toCharArray(configClientId, 32);
    } else if(c.startsWith(_pt)) {
      c.substring(colon + 2).toCharArray(configPublishTopic, 32);
    } else if(c.startsWith(_st)) {
      c.substring(colon + 2).toCharArray(configSubscribeTopic, 32);
    }
}

void printConfig() {
  Serial.print(_cu);
  Serial.println(configUser);
  Serial.print(_cp);
  Serial.println(configPassword);
  Serial.print(_ci);
  Serial.println(configClientId);
  Serial.print(_pt);
  Serial.println(configPublishTopic);
  Serial.print(_st);
  Serial.println(configSubscribeTopic);
}

