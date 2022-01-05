#include "HomeSpan.h" 
#include "extras/PwmPin.h"

struct NeonSign : Service::LightBulb {
  LedPin *ledPin;
  SpanCharacteristic *power;
  SpanCharacteristic *level;

  NeonSign(int pin) : Service::LightBulb() {
    power = new Characteristic::On();
    level = new Characteristic::Brightness(80);
    level->setRange(5, 80, 1);
    
    this->ledPin = new LedPin(pin);
    analogWrite(pin, 80);
  }

  boolean update() {
    ledPin->set(power->getNewVal() * level->getNewVal());
    return(true);
  }
};
