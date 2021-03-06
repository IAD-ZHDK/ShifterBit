// predefine functions
void display_setup();
void display_set(int, int);
void wifi_setup();
void mqtt_setup();
void input_setup();
void output_setup();
void mqtt_loop();
void input_loop();
void display_loop();

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
  input_setup();
  output_setup();
}

void loop() {
  mqtt_loop();
  input_loop();
  display_loop();
}
