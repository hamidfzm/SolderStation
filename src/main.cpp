/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include <Arduino.h>

#include "Display.h"

Display display;


void setup()
{
  display.begin();
  display.message(20, 10, 1, "System x1");
}

void loop()
{
  display.update();
}
