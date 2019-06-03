#include "Display.h"

#include "Colors.h"

void Display::begin() {
  uint16_t ID = tft.readID();
  if (ID == 0xD3) ID = 0x9481;
  tft.begin(ID);
  tft.setRotation(0);
}

void Display::message(int x, int y, int size, const char *msg)
{
  tft.fillScreen(BLACK);
  tft.setCursor(x, y);
  tft.setTextColor(GREEN);
  tft.setTextSize(size);
  tft.print(msg);
}
