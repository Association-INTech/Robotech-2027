#include <Arduino.h>

#include <AccelStepper.h>
#include "Palettes/Palettes.hpp"


Palette palette(2, 3, 4, 5, 6, 7, 8, 9, 10, 11);


void setup() {
  delay(5000);
  Serial.begin(115200);
}

void loop() {
  Serial.println("Debut grab");
  palette.grab_box();
  Serial.println("Fin grab");

  delay(5000);

  Serial.println("Debut release");
  palette.release_box();
  Serial.println("Fin release");

  delay(5000);

}