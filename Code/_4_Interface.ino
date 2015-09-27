#define INTERFACE_INTERVAL 200
#define INTERACE_IN A0
#define INTERFACE_OUT 16
#define INTERFACE_HISTORY 20

int interface_input_history[INTERFACE_HISTORY];
int interface_last_input = 0;
long long interface_last_read = 0;

void interface_setup() {
  pinMode(OUTPUT, INTERFACE_OUT);
  interface_out(0);

  for(int i=0; i < INTERFACE_HISTORY; i++) {
    interface_input_history[i] = 0;
  }
}

void interface_loop() {
  int v = interface_filter(analogRead(INTERACE_IN));

  if(v != interface_last_input) {
    if(millis() - INTERFACE_INTERVAL > interface_last_read) {
      interface_last_input = v;
      interface_last_read = millis();

      if(config_publish) {
        mqtt_client.publish(config_publish_topic, String(v));
        display_touch_in();
      }
    }
  }
}

void interface_out(int v) {
  if(v <= 0) {
    analogWrite(INTERFACE_OUT, 1);
  } else if(v >= 1023) {
    analogWrite(INTERFACE_OUT, 1023);
  } else {
    analogWrite(INTERFACE_OUT, v);  
  }
}

int interface_filter(int v) {
  for(int i=1; i < INTERFACE_HISTORY; i++) {
    interface_input_history[i - 1] = interface_input_history[i];
  }
  
  interface_input_history[INTERFACE_HISTORY - 1] = v;

  int sum = 0;
  for(int j=0; j < INTERFACE_HISTORY; j++) {
    sum += interface_input_history[j];
  }
  
  return sum / INTERFACE_HISTORY;
}
