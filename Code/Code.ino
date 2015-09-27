void setup() {
  Serial.begin(9600);
  Serial.println("\nStarting...");

  display_setup();

  display_set(HIGH, LOW);
  config_setup();
  config_print();

  display_set(HIGH, HIGH);
  wifi_setup();
  mqtt_setup();

  display_set(LOW, LOW);
  interface_setup();
}

void loop() {
  mqtt_loop();
  interface_loop();
  display_loop();
}
