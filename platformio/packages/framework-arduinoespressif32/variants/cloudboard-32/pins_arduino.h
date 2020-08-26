#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define EXTERNAL_NUM_INTERRUPTS 16
#define NUM_DIGITAL_PINS        40
#define NUM_ANALOG_INPUTS       16

#define analogInputToDigitalPin(p)  (((p)<20)?(esp32_adc2gpio[(p)]):-1)
#define digitalPinToInterrupt(p)    (((p)<40)?(p):-1)
#define digitalPinHasPWM(p)         (p < 34)

static const int8_t LED_BUILTIN = -1; // Not Connected
#define BUILTIN_LED  LED_BUILTIN // backward compatibility

#define OLED_CS     4
#define OLED_DC     5
#define OLED_MOSI   13
#define OLED_CLK    14
#define OLED_RST    -1 // Not Connected
#define SS  4
#define SCK 14

#define GPIO18 18
#define GPIO19 19
#define GPIO22 22
#define GPIO23 23

#define NEOPIXEL16 16
#define NEOPIXEL17 17

#define PIXEL 12

#define PWM26 26
#define PWM27 27

#define TOUCH2 2
#define TOUCH3 15

static const uint8_t TX = 1; 
static const uint8_t RX = 3;

static const uint8_t SDA = 21;
static const uint8_t SCL = 20;

static const uint8_t CS    = OLED_CS;
static const uint8_t DC    = OLED_DC;
static const uint8_t MOSI  = OLED_MOSI;
static const int8_t  MISO  = -1; // Not Connected
static const uint8_t CLK   = OLED_CLK;
static const int8_t  RST   = -1; // Not Connected

static const uint8_t T2 = TOUCH2;
static const uint8_t T3 = TOUCH3;

static const uint8_t D2 = GPIO19;
static const uint8_t D7 = GPIO18; 

#endif /* Pins_Arduino_h */
