#include <Arduino.h>
//#include <SPI.h>
//#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI:
Adafruit_SSD1306 display(
  SCREEN_WIDTH, 
  SCREEN_HEIGHT,
  OLED_MOSI, 
  OLED_CLK, 
  OLED_DC, 
  OLED_RST, 
  OLED_CS);

void setup() {
  Serial.begin(115200);
  Serial.print("Starting OLED... ");

  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  Serial.println("Done");

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  display.display();

  int pad = 10;
  int radius = 5;

  // Draw a recteangle
  display.drawRoundRect(
    pad, 
    pad, 
    display.width()-2*pad, 
    display.height()-2*pad, 
    radius, 
    SSD1306_WHITE);

  display.setTextSize(1);               // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Draw white text
  display.setCursor(26,28);             // Start in the rectagle
  display.println(F("Cloudboard 32"));
  display.display();
}

void loop() {
  // Invert and restore display
  display.invertDisplay(false);
  delay(2000);
  display.invertDisplay(true);
  delay(2000);
}