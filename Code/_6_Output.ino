#include <SPI.h>

#define OUTPUT_DP_CS 16

void output_setup() {
  /*pinMode(OUTPUT_DP_CS, OUTPUT);
  digitalWrite(OUTPUT_DP_CS, HIGH);

  SPI.begin();*/
}

void output_set(int v){
  /*SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
  digitalWrite(OUTPUT_DP_CS, LOW);
  SPI.transfer(B00000111);
  digitalWrite(OUTPUT_DP_CS, HIGH);
  SPI.endTransaction();*/
}
