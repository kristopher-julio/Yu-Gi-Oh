// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        8 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 50// Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 200 // Time (in milliseconds) to pause between pixels
#define DELAYVAL2 200 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(20, pixels.Color(150, 150, 150));
    pixels.setPixelColor(i, pixels.Color(0, 0, 150));
    pixels.setPixelColor(i + 11, pixels.Color(150, 0, 0));
    pixels.setPixelColor(i + 20, pixels.Color(150, 150, 0));
    pixels.setPixelColor(i + 30, pixels.Color(150, 0, 150));
    pixels.setPixelColor(i + 40, pixels.Color(0, 150, 150));
    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
    if (i == 10)
    {
      for (int test = 0; test < 5; test++)
      {
        for (int i = 0; i < 11; i++) { // For each pixel...

          // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
          // Here we're using a moderately bright green color:
          pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        }
        pixels.show();   // Send the updated pixel colors to the hardware.
        delay(DELAYVAL2); // Pause before next pass through loop
        for (int i = 0; i < 11; i++) { // For each pixel...
          pixels.setPixelColor(i, pixels.Color(0, 150, 0));
        }
        pixels.show();   // Send the updated pixel colors to the hardware.

        delay(DELAYVAL2); // Pause before next pass through loop
      }
    }
  }
  for (int i = NUMPIXELS; i > -1; i--) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(106, 24, 59));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
    if (i == 10)
    {
      for (int test = 0; test < 5; test++)
      {
        for (int i = 0; i < 11; i++) { // For each pixel...

          // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
          // Here we're using a moderately bright green color:
          pixels.setPixelColor(i, pixels.Color(0, 0, 255));
        }
        pixels.show();   // Send the updated pixel colors to the hardware.
        delay(DELAYVAL2); // Pause before next pass through loop
        for (int i = 0; i < 11; i++) { // For each pixel...
          pixels.setPixelColor(i, pixels.Color(255, 255, 255));
        }
        pixels.show();   // Send the updated pixel colors to the hardware.
        delay(DELAYVAL2); // Pause before next pass through loop
        for (int i = 0; i < 11; i++) { // For each pixel...

          // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
          // Here we're using a moderately bright green color:
          pixels.setPixelColor(i, pixels.Color(0, 255, 0));
        }
        pixels.show();   // Send the updated pixel colors to the hardware.
        delay(DELAYVAL2); // Pause before next pass through loop
      }
      for (int test = 0; test < 5; test++)
      {
        for (int i = 0; i < 11; i++) { // For each pixel...

          // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
          // Here we're using a moderately bright green color:
          pixels.setPixelColor(i + 20, pixels.Color(150, 0, 255));
          pixels.setPixelColor(i + 30, pixels.Color(0, 0, 0));
        }
        pixels.show();   // Send the updated pixel colors to the hardware.
        delay(DELAYVAL2); // Pause before next pass through loop
        for (int i = 0; i < 11; i++) { // For each pixel...
          pixels.setPixelColor(i + 30, pixels.Color(0, 150, 255));
          pixels.setPixelColor(i + 20, pixels.Color(0, 0, 0));
        }
        pixels.show();   // Send the updated pixel colors to the hardware.
        delay(DELAYVAL2); // Pause before next pass through loop
      }
    }
  }
}
