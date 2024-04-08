///
/// @file BWRY_Colours.ino
/// @brief Example for Pervasive Displays Library Suite
///
/// @details Project Pervasive Displays Library Suite
/// @n Based on highView technology
///
/// @author Rei Vilo
/// @date 31 Aug 2023
/// @version 614
///
/// @copyright (c) Rei Vilo, 2010-2023
/// @copyright Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
///
/// @see ReadMe.txt for references
/// @n
///

// Screen
#include "PDLS_EXT3_Basic_BWRY.h"

// SDK
#include <Arduino.h>
#undef min
#undef max
#include "hV_HAL_Peripherals.h"

// Include application, user and local libraries
// #include <SPI.h>
#include <iomanip>
#include <sstream>

// Configuration
#include "hV_Configuration.h"

// Set parameters
#define DISPLAY_COLOURS_BWRY 1
#define DISPLAY_CONTRASTS_BWRY 0
#define DISPLAY_PALETTE_BWRY 0

// Define structures and classes

// Define variables and constants
//Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_154_BWRY, boardRaspberryPiPico_RP2040);
// Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_213_BWRY, boardRaspberryPiPico_RP2040);
 Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_266_BWRY, boardArduinoZero);

// Prototypes

// Utilities
///
/// @brief Wait with countdown
/// @param second duration, s
///
void wait(uint8_t second)
{
    for (uint8_t i = second; i > 0; i--)
    {
        Serial.print(formatString(" > %i  \r", i));
        delay(1000);
    }
    Serial.print("         \r");
}

// Functions
#if (DISPLAY_COLOURS_BWRY == 1)

String convertReading(double reading)
{
  std::stringstream ss;
  ss << std::fixed << std::setprecision(1) << reading;
  return String(ss.str().c_str());
}

void displayColoursBWRY(double start_height, double current_height, double peak_height, double current_temperature)
{
    //myScreen.setOrientation(ORIENTATION_PORTRAIT);
    myScreen.setOrientation(ORIENTATION_LANDSCAPE);
    myScreen.setPenSolid(false);
    //myScreen.selectFont(Font_Terminal8x12);
    myScreen.selectFont(Font_Terminal16x24);

    uint16_t x, y, dx, dy;
    String s_start_height, s_current_height, s_peak_height, s_current_temperature;

    const uint8_t grid = 4; // 4 or 5

    x = myScreen.screenSizeX();
    y = myScreen.screenSizeY();
    dx = x / 1;
    dy = y / 4;

    s_start_height = "Start: " + convertReading(start_height) + " cm";
    s_current_height = "Current: " + convertReading(current_height) + " cm";
    s_peak_height = "Peak: " + convertReading(peak_height) + " cm";
    s_current_temperature = "Temp: " + convertReading(current_temperature) + " F";

    myScreen.setPenSolid(true);
    myScreen.dRectangle(dx * 0, dy * 0, dx, dy, myColours.black);
    myScreen.dRectangle(dx * 0, dy * 1, dx, dy, myColours.white);
    myScreen.dRectangle(dx * 0, dy * 2, dx, dy, myColours.black);
    myScreen.dRectangle(dx * 0, dy * 3, dx, dy, myColours.white);

    myScreen.setFontSolid(false);
    myScreen.gText(dx * 0 + 4, dy * 0 + 4, s_start_height, myColours.white);
    myScreen.gText(dx * 0 + 4, dy * 1 + 4, s_current_height, myColours.black);
    myScreen.gText(dx * 0 + 4, dy * 2 + 4, s_peak_height, myColours.white);
    myScreen.gText(dx * 0 + 4, dy * 3 + 4, s_current_temperature, myColours.black);

    myScreen.flush();
}

#endif // DISPLAY_COLOURS_BWRY

// Add setup code
///
/// @brief Setup
///
void setup()
{
    Serial.begin(115200);
    delay(500);
    Serial.println();
    Serial.println("=== " __FILE__);
    Serial.println("=== " __DATE__ " " __TIME__);
    Serial.println();

    Serial.print("begin... ");
    myScreen.begin();
    Serial.println(formatString("%s %ix%i", myScreen.WhoAmI().c_str(), myScreen.screenSizeX(), myScreen.screenSizeY()));

#if (DISPLAY_COLOURS_BWRY == 1)

    Serial.println("DISPLAY_COLOURS_BWRY... ");
    myScreen.clear();

    double start_height = 9.2;
    double current_height = 11.7;
    double peak_height = 11.9;
    double current_temperature = 78.4;

    displayColoursBWRY(start_height, current_height, peak_height, current_temperature);
    wait(8);

#endif // DISPLAY_COLOURS_BWRY

    Serial.print("White... ");
    //myScreen.clear();
    myScreen.flush();

    Serial.println("=== ");
    Serial.println();
}

// Add loop code
///
/// @brief Loop, empty
///
void loop()
{
    delay(1000);
}
