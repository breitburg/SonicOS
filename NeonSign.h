#include "extras/PwmPin.h"

struct NeonSign : Service::LightBulb {
  LedPin *ledPin;
  SpanCharacteristic *power;
  SpanCharacteristic *level;
  
  NeonSign(int pin) : Service::LightBulb() {
    power = new Characteristic::On();
    level = new Characteristic::Brightness(100);
    level->setRange(5, 100, 1);
    this->ledPin=new LedPin(pin);
  }

  boolean update() {
    ledPin->set(power->getNewVal()*level->getNewVal());
    return(true);
  }
};
