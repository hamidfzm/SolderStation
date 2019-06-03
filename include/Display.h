#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>   // Hardware-specific library
#include <TouchScreen.h>
#define MINPRESSURE 200
#define MAXPRESSURE 1000

const int XP = 6, XM = A2, YP = A1, YM = 7; //ID=0x9341
const int TS_LEFT = 113, TS_RT = 924, TS_TOP = 910, TS_BOT = 162;

class Display {
private:
  MCUFRIEND_kbv tft;
  TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
  Adafruit_GFX_Button dec_btn, inc_btn;
  Adafruit_GFX_Button *buttons[2];
  int touch_x, touch_y;
public:
  void begin();
  void update();
  void message(int x, int y, int size, const char *msg);
  void message(int x, int y, int size, int msg);
};

#endif
