#define INTERACE_IN A0
#define INPUT_INTERVAL 200
#define INPUT_HISTORY 20

int input_input_history[INPUT_HISTORY];
int input_last_input = 0;
long long input_last_read = 0;

void input_setup() {
  for(int i=0; i < INPUT_HISTORY; i++) {
    input_input_history[i] = 0;
  }
}

int input_filter(int v) {
  for(int i=1; i < INPUT_HISTORY; i++) {
    input_input_history[i - 1] = input_input_history[i];
  }
  
  input_input_history[INPUT_HISTORY - 1] = v;

  int sum = 0;
  for(int j=0; j < INPUT_HISTORY; j++) {
    sum += input_input_history[j];
  }
  
  return sum / INPUT_HISTORY;
}

void input_loop() {
  int v = input_filter(constrain(analogRead(INTERACE_IN), 0, 1023));

  if(v != input_last_input) {
    if(millis() - INPUT_INTERVAL > input_last_read) {
      input_last_input = v;
      input_last_read = millis();

      if(config_publish) {
        display_touch_in();

        if(!config_json) {
          mqtt_client.publish(config_publish_topic, String(v));
          return;
        }

        const size_t bufferSize = JSON_OBJECT_SIZE(1);
        DynamicJsonBuffer jsonBuffer(bufferSize);
        JsonObject& root = jsonBuffer.createObject();
        root["value"] = v;
        String jsonOut;
        root.printTo(jsonOut);
        mqtt_client.publish(config_publish_topic, jsonOut);
      }
    }
  }
}

