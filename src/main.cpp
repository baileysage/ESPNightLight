//#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
//#include <WiFiUdp.h>
#include <ArduinoOTA.h>

int leds[6] = {16, 5, 4, 0, 12, 14};
int brightness[6] = {255, 16, 500, 10, 50, 10};
int fadeAmount[6] = {5, 10, 20, 17, 15, 25};

// the setup routine runs once when you press reset:
void setup()  {
  for(int i = 0; i < 6; i++){
    pinMode(leds[i], OUTPUT);
  }
}

void loop()  {
  for(int i = 0; i < 6; i++){
    analogWrite(leds[i], brightness[i]);
    brightness[i] = brightness[i] + fadeAmount[i];
    if (brightness[i] <=25 || brightness[i] >= 998) {
      fadeAmount[i] = -fadeAmount[i] ;
    } //!!!: this will get pulled out....
  }
  delay(40);
}

/*
static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;
*/
