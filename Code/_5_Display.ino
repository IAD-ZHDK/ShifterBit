#define DISPLAY_DURATION 50

bool display_a = false;
bool display_b = false;

long long display_last_touch_a = 0;
long long display_last_touch_b = 0;

void display_setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  display_set(LOW, LOW);
}

void display_loop() {
  if(display_a && millis() - DISPLAY_DURATION > display_last_touch_a) {
    display_a = false;
  }

  if(display_b && millis() - DISPLAY_DURATION > display_last_touch_b) {
    display_b = false;
  }

  display_set(display_a, display_b);
}

void display_set(int a, int b) {
  digitalWrite(4, a);
  digitalWrite(5, b);
}

void display_touch_a() {
  display_a = true;
  display_last_touch_a = millis();
}

void display_touch_b() {
  display_b = true;
  display_last_touch_b = millis();
}

