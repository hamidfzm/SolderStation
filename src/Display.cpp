#include "Display.h"

#include "Colors.h"


void Display::begin() {
  uint16_t ID = tft.readID();
  if (ID == 0xD3) ID = 0x9481;
  tft.begin(ID);
  tft.setRotation(0);
  tft.fillScreen(BLACK);

  inc_btn.initButton(&tft, 180, 200, 100, 40 , WHITE, CYAN, BLACK, ">", 4);
  dec_btn.initButton(&tft, 60, 200, 100, 40, WHITE, CYAN, BLACK, "<", 4);
  inc_btn.drawButton(false);
  dec_btn.drawButton(false);

  tft.fillRect(40, 80, 160, 80, RED);

  buttons[0] = &dec_btn;
  buttons[1] = &inc_btn;

}

void Display::update()
{
  TSPoint p = ts.getPoint();
  pinMode(YP, OUTPUT);      //restore shared pins
  pinMode(XM, OUTPUT);
  digitalWrite(YP, HIGH);   //because TFT control pins
  digitalWrite(XM, HIGH);

  bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
  if (pressed) {
    touch_x = map(p.y, TS_LEFT, TS_RT, 0, 320);
    touch_y = map(p.x, TS_TOP, TS_BOT, 0, 480);

    for (int i = 0 ; i < 2; i++) {
      buttons[i]->press(buttons[i]->contains(touch_x, touch_y));
      if (buttons[i]->justReleased())
        buttons[i]->drawButton(false);
      if (buttons[i]->justPressed())
        buttons[i]->drawButton(true);
    }
  }

  if (inc_btn.justPressed()) {
    tft.fillRect(40, 80, 160, 80, GREEN);
  }
  if (dec_btn.justPressed()) {
    tft.fillRect(40, 80, 160, 80, RED);
  }
}

void Display::message(int x, int y, int size, const char *msg)
{
  tft.setCursor(x, y);
  tft.setTextColor(GREEN);
  tft.setTextSize(size);
  tft.print(msg);
}

void Display::message(int x, int y, int size, int msg)
{
  tft.setCursor(x, y);
  tft.setTextColor(GREEN);
  tft.setTextSize(size);
  tft.print(msg);
}
