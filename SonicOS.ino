#include "HomeSpan.h" 
#include "NeonSign.h"          

void setup() {
  Serial.begin(115200);
  homeSpan.setApSSID("Sonic Neon Sign");
  homeSpan.setApPassword("supersonic");
  homeSpan.setApTimeout(3600);
  homeSpan.enableAutoStartAP();
  
  homeSpan.begin(Category::Lighting, "Neon Sign", "SonicNeonSign", "Prototype");
  
  new SpanAccessory();
    new Service::AccessoryInformation();    
      new Characteristic::Name("Neon Sign");    
      new Characteristic::Manufacturer("Breitburg Ilya"); 
      new Characteristic::SerialNumber("Prototype");  
      new Characteristic::Model("Sonic Neon Sign");   
      new Characteristic::FirmwareRevision("1.0");  
      new Characteristic::Identify();               
      
    new Service::HAPProtocolInformation();
      new Characteristic::Version("1.1.0");
  
    new NeonSign(2);
}

void loop() {
  homeSpan.poll(); 
}
