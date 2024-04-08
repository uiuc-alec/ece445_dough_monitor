// Includes for the Display
#include "PDLS_EXT3_Basic_BWRY.h"
#include "hV_HAL_Peripherals.h"
#include "hV_Configuration.h"
// Includes for the Distance Sensor
#include <VCNL3040.h>
#include <Wire.h>
// Defines for the Display
#define DISPLAY_COLOURS_BWRY 1
#define DISPLAY_CONTRASTS_BWRY 0
#define DISPLAY_PALETTE_BWRY 0
// Defines for the Sensors
#define ADCPIN 1
// Variables
uint32_t temp_reading;
double current_temperature, start_height, current_height, peak_height=0;
uint16_t distance_data_out;
VCNL3040 sens;
Screen_EPD_EXT3 myScreen(eScreen_EPD_266_QS_0F, boardNucleo64);

// Functions
String convertReading(double reading)
{
  int decimal_index = 0;
  String value_str = String(reading);
  while(value_str[decimal_index] != '.'){
    decimal_index++;
  }
  String final_str = value_str.substring(0,decimal_index+2);
  return final_str;
}

void displaySensorReadings(double start_height, double current_height, double peak_height, double current_temperature)
{
    myScreen.setOrientation(ORIENTATION_LANDSCAPE);
    myScreen.setPenSolid(false);
    myScreen.selectFont(Font_Terminal16x24);

    uint16_t x, y, dx, dy;
    String s_start_height, s_current_height, s_peak_height, s_current_temperature;

    const uint8_t grid = 4; // 4 or 5

    x = myScreen.screenSizeX();
    y = myScreen.screenSizeY();
    dx = x / 1;
    dy = y / 4;

    s_start_height = "Start:   " + convertReading(start_height) + " cm";
    s_current_height = "Current: " + convertReading(current_height) + " cm";
    s_peak_height = "Peak:    " + convertReading(peak_height) + " cm";
    s_current_temperature = "Temp:    " + convertReading(current_temperature) + " F";

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


void setup() {
  // put your setup code here, to run once:
  delay(2000);
  Serial.begin(9600);
  Serial.print("Setup is starting!");
  Wire.begin();
  sens.begin();
  sens.setPSResolution(1);
  sens.startReading();
  myScreen.begin();
  Serial.print("Setup is done!");
  delay(250);
  start_height = sens.readPSData();
}

void loop() {
  // put your main code here, to run repeatedly:
  distance_data_out = sens.readPSData();
  current_height = double(distance_data_out);
  if (current_height > peak_height){
    peak_height = current_height;
  }
  Serial.print("Reading data from distance sensor: ");
  Serial.println(distance_data_out);
  temp_reading = analogRead(ADCPIN);
  current_temperature = ((((temp_reading*330.0)/(1024.0)) - 273.15) * (9.0/5)) + 32;  // Temp in F
  Serial.print("Reading data from temperature sensor: ");
  Serial.println(current_temperature);
  Serial.print("Printing to display: ");
  displaySensorReadings(start_height, current_height, peak_height, current_temperature);
  delay(20000);
}