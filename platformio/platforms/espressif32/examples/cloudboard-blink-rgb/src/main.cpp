#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// This is a non-blocking example of how to use the Neopixel on the Cloudboard

#define ON_TIME 200
#define OFF_TIME 200
#define HUE_INCREMENT 400

// Declare our NeoPixel strip object:
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)

Adafruit_NeoPixel pixel(1, PIXEL, NEO_GRB + NEO_KHZ800);
int colorIndex = 0;
bool pixelState = false;
unsigned long waitTime = 0;

// updatePixel() function -- Turns the Neopixel On or off as well as setting a color --------------------------------
void updatePixel(){
  if(pixelState){
    waitTime = millis() + OFF_TIME;
    pixel.setPixelColor(0, pixel.Color(0, 0, 0)); 
  } 
  else {
    waitTime = millis() + ON_TIME;
    colorIndex = colorIndex+HUE_INCREMENT > 65536 ? 0 : colorIndex+HUE_INCREMENT;
    pixel.setPixelColor(0, pixel.gamma32(pixel.ColorHSV(colorIndex)));
  }

  pixelState = !pixelState;
  pixel.show();  
}

// setup() function -- runs once at startup --------------------------------
void setup() {
  pixel.begin();
  pixel.setBrightness(100);
  pixel.setPixelColor(1, pixel.Color(0, 0, 0));
  pixel.show();   
}

// loop() function -- runs repeatedly as long as board is on ---------------
void loop() {
  if( waitTime < millis() ){
    updatePixel();
  }
}