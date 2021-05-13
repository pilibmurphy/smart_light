#include <WiFi.h>
#include "ws2812.h"
const int DATA_PIN = 18;
const uint16_t NUM_PIXELS = 100;
rgbVal *pixels;
char picture = 1;
bool doonce = 1;
const char* ssid     = "";
const char* password = "";

void setup()
{
  ws2812_init(DATA_PIN, LED_WS2812B);
  pixels = (rgbVal*)malloc(sizeof(rgbVal) * NUM_PIXELS);
  displayOff();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  server.begin();
}

void loop() {

  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    String req = client.readStringUntil('\r');
    client.flush();
    if (req.indexOf("/picture/1") != -1) {
      picture = 1;
      doonce = 0;
    }
    else if (req.indexOf("/picture/2") != -1) {
      picture = 2;
      doonce = 0;
    }
  }

  if (picture == 1 && doonce == 0) {
    displayOff();
    for (int i = 0; i < 10; i++) {
      pixels[i] = makeRGBVal (100, 0, 0);
    }
    for (int i = 10; i < 20; i++) {
      pixels[i] = makeRGBVal (0, 100, 0);
    }
    for (int i = 20; i < 30; i++) {
      pixels[i] = makeRGBVal (0, 0, 100);
    }
    for (int i = 30; i < 40; i++) {
      pixels[i] = makeRGBVal (100, 100, 100);
    }
    for (int i = 40; i < 50; i++) {
      pixels[i] = makeRGBVal (100, 0, 0);
    }
    for (int i = 50; i < 60; i++) {
      pixels[i] = makeRGBVal (0, 100, 0);
    }
    for (int i = 60; i < 70; i++) {
      pixels[i] = makeRGBVal (0, 0, 100);
    }
    for (int i = 70; i < 80; i++) {
      pixels[i] = makeRGBVal (100, 100, 100);
    }
    for (int i = 80; i < 90; i++) {
      pixels[i] = makeRGBVal (100, 0, 0);
    }
    for (int i = 90; i < 100; i++) {
      pixels[i] = makeRGBVal (0, 100, 0);
    }
    ws2812_setColors(NUM_PIXELS, pixels);
    doonce = 1;
  }
  if (picture == 2 && doonce == 0) {
    displayOff();
    for (int i = 0; i < 10; i++) {
      pixels[i] = makeRGBVal (100, 100, 0);
    }
    for (int i = 10; i < 20; i++) {
      pixels[i] = makeRGBVal (0, 100, 100);
    }
    for (int i = 20; i < 30; i++) {
      pixels[i] = makeRGBVal (100, 0, 100);
    }
    for (int i = 30; i < 40; i++) {
      pixels[i] = makeRGBVal (100, 100, 100);
    }
    for (int i = 40; i < 50; i++) {
      pixels[i] = makeRGBVal (100, 100, 0);
    }
    for (int i = 50; i < 60; i++) {
      pixels[i] = makeRGBVal (0, 100, 100);
    }
    for (int i = 60; i < 70; i++) {
      pixels[i] = makeRGBVal (100, 0, 100);
    }
    for (int i = 70; i < 80; i++) {
      pixels[i] = makeRGBVal (100, 100, 100);
    }
    for (int i = 80; i < 90; i++) {
      pixels[i] = makeRGBVal (100, 100, 0);
    }
    for (int i = 90; i < 100; i++) {
      pixels[i] = makeRGBVal (0, 100, 100);
    }
    ws2812_setColors(NUM_PIXELS, pixels);
    doonce = 1;
  }
}

void displayOff() {
  for (int i = 0; i < NUM_PIXELS; i++) {
    pixels[i] = makeRGBVal(0, 0, 0);
  }
  ws2812_setColors(NUM_PIXELS, pixels);
}

