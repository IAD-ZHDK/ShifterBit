#define INTERFACE_INTERVAL 200
#define INTERACE_IN A0
#define INTERFACE_OUT 16

int interface_input = 0;
long long interface_last_read = 0;

void interface_setup() {
  pinMode(OUTPUT, INTERFACE_OUT);
  interface_out(0);
}

void interface_loop() {
  int v = analogRead(INTERACE_IN);

  if(v != interface_input) {
    if(millis() - INTERFACE_INTERVAL > interface_last_read) {
      interface_input = v;
      interface_last_read = millis();

      if(config_publish) {
        mqtt_client.publish(config_publish_topic, String(v));
        display_touch_in();
      }
    }
  }
}

void interface_out(int v) {
  analogWrite(INTERFACE_OUT, v);
}

