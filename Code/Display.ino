#define DISPLAY_DURATION 50
#define DISPLAY_LED_IN 5
#define DISPLAY_LED_OUT 4

bool display_in = false;
bool display_out = false;

long long display_last_touch_in = 0;
long long display_last_touch_out = 0;

void display_setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  display_set(LOW, LOW);
}

void display_loop() {
  if(display_in && millis() - DISPLAY_DURATION > display_last_touch_in) {
    display_in = false;
  }

  if(display_out && millis() - DISPLAY_DURATION > display_last_touch_out) {
    display_out = false;
  }

  display_set(display_in, display_out);
}

void display_set(int in, int out) {
  digitalWrite(DISPLAY_LED_IN, in);
  digitalWrite(DISPLAY_LED_OUT, out);
}

void display_touch_in() {
  display_in = true;
  display_last_touch_in = millis();
}

void display_touch_out() {
  display_out = true;
  display_last_touch_out = millis();
}

