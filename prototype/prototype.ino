#include <LPD8806.h>


const int startButton = 2;
const int magnetButton = 3;
const int electronButton = 4;
const int neutronButton = 5;
const int protonButton = 6;
const int photonButton = 7;
const int muonButton = 8;






void setup() {
  // put your setup code here, to run once:
pinMode(startButton, INPUT);
pinMode(magnetButton, INPUT);
pinMode(electronButton, INPUT);
pinMode(neutronButton, INPUT);
pinMode(protonButton, INPUT);
pinMode(muonButton, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  

}






void runThrough(){
  //random number between 0 and 5
long randNumber;
randNumber = random(6);

switch (randNumber){
  case 0: 
  Serial.println("electron");
  //LEDfunction(16, 6, 7);  

  break;

  case 1:
  Serial.println("neutron");
  // Number of RGB LEDs in strand:
int nLEDs = 16;

// Chose 2 pins for output; can be any valid output pins:
int dataPin  = 6;  //11
int clockPin = 7;  //13
// Time delay of each LED
int TO = 50;
// First parameter is the number of LEDs in the strand.  The LED strips
// are 32 LEDs per meter but you can extend or cut the strip.  Next two
// parameters are SPI data and clock pins:
LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);

// You can optionally use hardware SPI for faster writes, just leave out
// the data and clock pin parameters.  But this does limit use to very
// specific pins on the Arduino.  For "classic" Arduinos (Uno, Duemilanove,
// etc.), data = pin 11, clock = pin 13.  For Arduino Mega, data = pin 51,
// clock = pin 52.  For 32u4 Breakout Board+ and Teensy, data = pin B2,
// clock = pin B1.  For Leonardo, this can ONLY be done on the ICSP pins.
//LPD8806 strip = LPD8806(nLEDs);, 

  // Start up the LED strip
  strip.begin();

  // Update the strip, to start they are all 'off'
  strip.show();



  /*
  colorChase(strip.Color(127,  0,  0), TO); // Red
  colorChase(strip.Color(  0,127,  0), TO); // Green
  colorChase(strip.Color(  0,  0,127), TO); // Blue
  */
  colorChase(strip.Color(127,127,127), TO); // White


// Chase one dot down the full strip.  Good for testing purposes.
void colorChase(uint32_t c, uint8_t wait) {
  int i;
  
  // Start by turning all pixels off:
  for(i=0; i<strip.numPixels(); i++) strip.setPixelColor(i, 0);

  // Then display one pixel at a time:
  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c); // Set new pixel 'on'
    strip.show();              // Refresh LED states
    strip.setPixelColor(i, 0); // Erase pixel, but don't refresh!
    delay(wait);
  }

  strip.show(); // Refresh to turn off last pixel
}
  break;

  case 2: 
  Serial.println("proton");

  break;

  case 3:
  Serial.println("photon");

  case 4:
  Serial.println("muon");

  break;  
}


}

