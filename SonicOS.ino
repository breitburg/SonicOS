#include "HomeSpan.h" 
#include "NeonSign.h"          

void setup() {
  Serial.begin(115200);
  
  homeSpan.setPairingCode("42156873");
  homeSpan.setWifiCredentials("4GUFI_5047", "1234567890");
  homeSpan.begin(Category::Lighting, "Neon Sign", "SonicNeonSign", "P1ECE");
  
  new SpanAccessory();
    new Service::AccessoryInformation();    
      new Characteristic::Name("Neon Sign");
      new Characteristic::Manufacturer("Breitburg Ilya");
      new Characteristic::SerialNumber("P1ECE");
      new Characteristic::Model("Sonic Neon Sign");
      new Characteristic::FirmwareRevision("1.1.0");
      new Characteristic::Identify();
      
    new Service::HAPProtocolInformation();
      new Characteristic::Version("1.1.0");
    
    new NeonSign(2);
}

void loop() {
  homeSpan.poll(); 
}
