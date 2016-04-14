/*
 * Config
 * 
 * Read config gile on attache SD card.
 * Pins: 14 (SCK), 12 (MISO), 13 (MOSI), 15 (SS)
 */

#include <SPI.h>
#include <SD.h>

#define CONFIG_SS_PIN 15
#define CONFIG_FILE "config.txt"

char config_wifi_ssid[64] = "";
char config_wifi_key[64] = "";
char config_mqtt_broker[64] = "";
char config_mqtt_user[64] = "";
char config_mqtt_password[64] = "";
char config_mqtt_client_id[64] = "";
bool config_publish = false;
char config_publish_topic[64] = "";
bool config_subscribe = false;
char config_subscribe_topic[64] = "";

const char * _config_ws = "wifi_ssid: ";
const char * _config_wk = "wifi_key: ";
const char * _config_mb = "mqtt_broker: ";
const char * _config_cu = "mqtt_user: ";
const char * _config_cp = "mqtt_password: ";
const char * _config_ci = "mqtt_client_id: ";
const char * _config_pt = "publish_topic: ";
const char * _config_st = "subscribe_topic: ";

void config_setup() {
  SPI.begin();
  SD.begin(CONFIG_SS_PIN);

  Serial.println("Read Config...");
  
  File fd = SD.open(CONFIG_FILE, FILE_READ);
  while(fd.available() > 0) {
    config_read_line(fd.readStringUntil('\n'));
  }
  fd.close();

  SPI.end();
}

void config_read_line(String c) {
  int colon = c.indexOf(": ");

   if (c.startsWith(_config_ws)) {
     c.substring(colon + 2).toCharArray(config_wifi_ssid, 64);
   } else if (c.startsWith(_config_wk)) {
     c.substring(colon + 2).toCharArray(config_wifi_key, 64);
   } else if (c.startsWith(_config_mb)) {
     c.substring(colon + 2).toCharArray(config_mqtt_broker, 64);
   } else if (c.startsWith(_config_cu)) {
     c.substring(colon + 2).toCharArray(config_mqtt_user, 64);
   } else if(c.startsWith(_config_cp)) {
     c.substring(colon + 2).toCharArray(config_mqtt_password, 64);
   } else if(c.startsWith(_config_ci)) {
     c.substring(colon + 2).toCharArray(config_mqtt_client_id, 64);
   } else if(c.startsWith(_config_pt)) {
     String p = c.substring(colon + 2);
     p.toCharArray(config_publish_topic, 64);
     config_publish = !p.equals("-");
   } else if(c.startsWith(_config_st)) {
     String s = c.substring(colon + 2);
     s.toCharArray(config_subscribe_topic, 64);
     config_subscribe = !s.equals("-");
   }
}

void config_print() {
  Serial.print(_config_ws);
  Serial.println(config_wifi_ssid);
  Serial.print(_config_wk);
  Serial.println(config_wifi_key);
  Serial.print(_config_mb);
  Serial.println(config_mqtt_broker);
  Serial.print(_config_cu);
  Serial.println(config_mqtt_user);
  Serial.print(_config_cp);
  Serial.println(config_mqtt_password);
  Serial.print(_config_ci);
  Serial.println(config_mqtt_client_id);
  Serial.print(_config_pt);
  Serial.println(config_publish_topic);
  Serial.print(_config_st);
  Serial.println(config_subscribe_topic);
}

