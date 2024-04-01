// The repos and library in Arduino IDE needed are below. 
// https://github.com/JenertsA/VCNL3040_Proximity_Sensor_Library/tree/master
// https://www.arduino.cc/reference/en/libraries/vcnl3040-proximity-sensor-library/

#include <VCNL3040.h>
#include <Wire.h>

VCNL3040 sens;

void setup() {
  // put your setup code here, to run once:
  delay(2000);
  Serial.begin(9600);
  Serial.print("Setup is starting!");
  Wire.begin();
  sens.begin();
  sens.setPSResolution(1);    // Sets to 16 bit resolution for readings further away
  sens.startReading();
  Serial.print("Setup is done!");
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t data_out = sens.readPSData();
  Serial.print("Reading data from sensor: ");
  Serial.println(data_out);
  delay(2000);
}
