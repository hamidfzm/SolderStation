#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>   // Hardware-specific library

class Display {
private:
  MCUFRIEND_kbv tft;
public:
  void begin();
  void message(int x, int y, int size, const char *msg);
};

#endif
