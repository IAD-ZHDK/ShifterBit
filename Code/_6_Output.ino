#include <SPI.h>

#define OUTPUT_DP_CS 16

void output_setup() {
  pinMode(OUTPUT_DP_CS, OUTPUT);
  digitalWrite(OUTPUT_DP_CS, HIGH);
  SPI.begin();
}

void output_set(int v){
  digitalWrite(OUTPUT_DP_CS, LOW);
  SPI.transfer(B00010001);
  SPI.transfer(constrain(map(v, 0, 1023, 0, 254), 0, 254));
  digitalWrite(OUTPUT_DP_CS, HIGH);
}
