void setup() {
  Serial.begin(9600);
  Serial.println("\nStarting...");
  
  config_setup();
  config_read();
  config_print();

  wifi_setup();
  mqtt_setup();
}

void loop() {
  mqtt_loop();
}
