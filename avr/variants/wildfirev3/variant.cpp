#include <Arduino.h>
#include <pins_arduino.h>
#include <variant.h>
#include <stdint.h>

void initVariant(void){
  // These Pins are Hardware-Bound Outputs
  // Set them up as such
  
  // Pin 10 and 4 should not be set LOW at the same time
  // because they control common-output buffers
  digitalWrite(10, HIGH);   // Slave Select for WiFi 
  digitalWrite(4, HIGH);    // Slave Select for SD Card
        
  pinMode(8, INPUT);        // WiFi IRQ Signal
  digitalWrite(8, HIGH);    // Pulled Up
        
  pinMode(12, INPUT);       // MISO 
  digitalWrite(12, HIGH);   // Pulled Up  

  #if defined(WILDFIRE_VERSION) && (WILDFIRE_VERSION == 2)
    uint8_t p[] = {4,7,9,10,11,13}; 
    for(uint8_t i = 0; i < 6; i++){
      pinMode(p[i], OUTPUT);        
    }

  #elif defined(WILDFIRE_VERSION) && (WILDFIRE_VERSION == 3) 
    // pin 9 is SS, and *must* be an output for SPI to work correctly
    
    // Pin 7, 15, 21 and 16 should not be set LOW at the same time
    // because they control common-output buffers   
    digitalWrite(9,  HIGH);   // MCU chip select high   
    digitalWrite(6,  LOW);    // initialize the LED to off
    digitalWrite(21, HIGH);   // Slave Select for WiFi 
    digitalWrite(16, HIGH);   // Slave Select for SD Card
    digitalWrite(7,  HIGH);   // Slave Select for RFM69 
    digitalWrite(15, HIGH);   // Slave Select for SPI Flash    
    digitalWrite(14, HIGH);   // Tiny Watchdog interface starts high
    uint8_t p[] = {6,7,14,15,16,21,23,9,11,13}; 
    for(uint8_t i = 0; i < 7; i++){
      //Serial.print("Setting pin ");
      //Serial.print(p[i]);
      //Serial.println(" to Output");
      pinMode(p[i], OUTPUT);        
    }                          

  #endif
  
  /* 
  pinMode(6, OUTPUT);
  for(uint8_t ii = 0; ii < 5; ii++){
    digitalWrite(6, HIGH);
    delay(500);
    digitalWrite(6, LOW);
    delay(500);
  }
  */
    
  
  
}
