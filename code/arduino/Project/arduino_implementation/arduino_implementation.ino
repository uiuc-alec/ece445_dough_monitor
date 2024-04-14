// Includes for the Display
#include "PDLS_EXT3_Basic_BWRY.h"
#include "hV_HAL_Peripherals.h"
#include "hV_Configuration.h"

// Includes for the Distance Sensor
#include <VCNL3040.h>
#include <Wire.h>

// Other includes
#include <StateMachine.h>

// Defines for the Display
#define DISPLAY_COLOURS_BWRY 1
#define DISPLAY_CONTRASTS_BWRY 0
#define DISPLAY_PALETTE_BWRY 0

// Defines for the Sensors
#define TEMPPIN 1
#define CONTAINERPIN 2
#define DOUGHPIN 3
#define CONFIRMPIN 4
#define CANCELPIN 5

// Variables
uint32_t temp_reading;
double current_temperature, start_height, current_height, peak_height, container_height;
uint16_t distance_data_out;
bool container_button, dough_button, confirm_button, cancel_button;
int display_count;
const int STATE_DELAY = 500; // Set this
const int DISPLAY_REFRESH_LIMIT = 30000; // 30 Seconds
/*******
  Order of precedence for the buttons is as follows
  1. Cancel
  2. Confirm
  3. ContainerPin
  4. DoughPin 
******/
VCNL3040 sens;
Screen_EPD_EXT3 myScreen(eScreen_EPD_266_QS_0F, boardNucleo64);
StateMachine machine = StateMachine();

// Functions

double getDistance(uint16_t input_reading){
  // TODO for Abhitya
  return double(input_reading);
}

/*convertReading(double reading)
        Returns: String that is a shortened version of reading passed in
        Args: reading- double value from one of the sensors
        Notes: This function might not be necessary the was Arduino does
              the double to String conversion
*/
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

/* initStateMachine()
        Returns: nothing
        Args: none
        Notes: initializes state machine with states and transitions.
                See Design Doc for state machine
                https://github.com/jrullan/StateMachine 
*/
void initStateMachine(){
  State* S0 = machine.addState(&baseState);
  State* S1 = machine.addState(&doughStageState);
  State* S2 = machine.addState(&containerStageState);
  State* S3 = machine.addState(&modifyDoughState);
  State* S4 = machine.addState(&modifyContainerState);
  State* S5 = machine.addState(&initializeDeviceContainer);
  State* S6 = machine.addState(&initializeDeviceDough);

  S0->addTransition(&transitionS0S5,S5);  // Base to initializeContainer
  S5->addTransition(&transitionS5S4,S4);  // Initializecontainer to modifyContainer
  S4->addTransition(&transitionS4S6,S6);  // mod container to initializeDough
  S6->addTransition(&transitionS6S3,S3);  // Initializedough to modifyDough 
  S0->addTransition(&transitionS0S1,S1);  // Base to dough
  S0->addTransition(&transitionS0S2,S2);  // Base to Container
  S1->addTransition(&transitionS1S3,S3);  // Dough to modify dough
  S1->addTransition(&transitionS1S0,S0);  // Dough to base
  S1->addTransition(&transitionS1S2,S2);  // Dough to container
  S2->addTransition(&transitionS2S4,S4);  // container to modify container
  S2->addTransition(&transitionS2S0,S0);  // container to base
  S2->addTransition(&transitionS2S1,S1);  // container to dough
  S3->addTransition(&transitionS3S0,S0);  //mod dough to base
  S4->addTransition(&transitionS4S0,S0);  //mod container to base
}

void baseState(){
  Serial.println("baseState");
  if(start_height != 0 && container_height != 0){
    // Only run if we have actually set the heights
    // This should run once every half second or so
    distance_data_out = sens.readPSData();  // Get current distance
    current_height = container_height - getDistance(distance_data_out); // convert from int to double. TODO: need abhitya's conversion for this

    if (current_height > peak_height){
      peak_height = current_height;     
    }

    Serial.print("Reading data from distance sensor: ");
    Serial.println(distance_data_out);

    temp_reading = analogRead(TEMPPIN);   // Read temperature value
    dough_button = ~analogRead(DOUGHPIN);   // Read dough button. active low
    container_button = ~analogRead(CONTAINERPIN); // Read container button. active low
    confirm_button = ~analogRead(CONFIRMPIN); // Read confirm button. active low
    cancel_button = ~analogRead(CANCELPIN); // Read cancel button. active low
    
    current_temperature = ((((temp_reading*330.0)/(1024.0)) - 273.15) * (9.0/5)) + 32;  // Temp in F. 330 because 3.3v. 1024 because 10 bit value return

    Serial.print("Reading data from temperature sensor: ");
    Serial.println(current_temperature);

    if(display_count == 0){
      // Display the output 
      Serial.print("Printing to display: ");
      displaySensorReadings(start_height, current_height, peak_height, current_temperature);
      Serial.print("Display print done!");
    }

    display_count+= STATE_DELAY;
    if(display_count >= 30000){
      display_count = 0;
    }
  }
}

void doughStageState(){
  Serial.println("doughStageState");
  stringToDisplay("Dough Staging Options", "1. Press confirm to change dough height","2. Press cancel to go back", "3. Press container to go to container staging");
}

void containerStageState(){
  Serial.println("containerStageState");
  stringToDisplay("Container Staging Options", "1. Press confirm to change container height","2. Press cancel to go back", "3. Press dough to go to dough staging");
}

void modifyDoughState(){
  Serial.println("modifyDoughState");
  distance_data_out = sens.readPSData();  // Get current distance
  start_height = container_height - getDistance(distance_data_out);
}

void modifyContainerState(){
  Serial.println("modifyContainerState");
  distance_data_out = sens.readPSData();  // Get current distance
  container_height = getDistance(distance_data_out);
}

void initializeDeviceContainer(){
  // Print screen out for initialization (acttually do this in the setup code)
  stringToDisplay("Please set the container height", "1. Press confirm when ready","", "");
}

void initializeDeviceDough(){
  // Print screen out for initialization (acttually do this in the setup code)
  stringToDisplay("Please set the dough height", "1. Press confirm when ready", "", "");
}

bool transitionS0S5(){
  if(start_height == 0 && container_height == 0){
    return true;
  }
  return false;
}

bool transitionS5S4(){
  if(confirm_button){
    return true;
  }
  return false;
}

bool transitionS4S6(){
  if(start_height == 0){
    return true;
  }
  return false;
}

bool transitionS6S3(){
  if(confirm_button){
    return true;
  }
  return false;
}

bool transitionS0S1(){
  if(cancel_button || confirm_button || container_button){
    return false;
  }
  else if(dough_button){
    return true;
  }
  return false;
}

bool transitionS0S2(){
  if(cancel_button || confirm_button){
    return false;
  }
  else if(container_button){
    return true;
  }
  return false;
}

bool transitionS1S3(){
  if(cancel_button){
    return false;
  }
  else if(confirm_button){
    return true;
  }
  return false;
}

bool transitionS1S0(){
  if(cancel_button){
    display_count = 0;  // reset display_count so that old display writes
    return true;
  }
  return false;
}

bool transitionS1S2(){
  if(cancel_button || confirm_button){
    return false;
  }
  else if(container_button){
    return true;
  }
  return false;
}

bool transitionS2S4(){
  if(cancel_button){
    return false;
  }
  else if(confirm_button){
    return true;
  }
  return false;
}

bool transitionS2S0(){
  if(cancel_button){
    display_count = 0;  // reset display_count so that old display writes
    return true;
  }
  return false;
}

bool transitionS2S1(){
  if(cancel_button || confirm_button || container_button){
    return false;
  }
  else if(dough_button){
    return true;
  }
  return false;
}

bool transitionS3S0(){
  display_count = 0;  // reset display_count so that old display writes
  return true;
}

bool transitionS4S0(){
  display_count = 0;  // reset display_count so that old display writes
  return true;
}

/* void displaySensorReadings(double start_height, double current_height, double peak_height, double current_temperature)
        Returns: nothing
        Args: stored values from the sensors
        Use: takes the values and updates the screen with the new values
*/
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

void stringToDisplay(String s1, String s2, String s3, String s4)
{
    myScreen.setOrientation(ORIENTATION_LANDSCAPE);
    myScreen.setPenSolid(false);
    myScreen.selectFont(Font_Terminal12x16);

    uint16_t x, y, dx, dy;

    const uint8_t grid = 4; // 4 or 5

    x = myScreen.screenSizeX();
    y = myScreen.screenSizeY();
    dx = x / 1;
    dy = y / 4;

    myScreen.setPenSolid(true);
    myScreen.dRectangle(dx * 0, dy * 0, dx, dy, myColours.black);
    myScreen.dRectangle(dx * 0, dy * 1, dx, dy, myColours.white);
    myScreen.dRectangle(dx * 0, dy * 2, dx, dy, myColours.black);
    myScreen.dRectangle(dx * 0, dy * 3, dx, dy, myColours.white);

    myScreen.setFontSolid(false);
    myScreen.gText(dx * 0 + 4, dy * 0 + 4, s1, myColours.white);
    myScreen.gText(dx * 0 + 4, dy * 1 + 4, s2, myColours.black);
    myScreen.gText(dx * 0 + 4, dy * 2 + 4, s3, myColours.white);
    myScreen.gText(dx * 0 + 4, dy * 3 + 4, s4, myColours.black);

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
  initStateMachine();

  pinMode(CONTAINERPIN,INPUT_PULLUP);
  pinMode(DOUGHPIN,INPUT_PULLUP);
  pinMode(CONFIRMPIN,INPUT_PULLUP);
  pinMode(CANCELPIN,INPUT_PULLUP);

  display_count = 0;
  peak_height = 0;
  start_height = 0;
  current_height = 0;
  current_temperature = 0;
  container_height = 0;

  Serial.print("Setup is done!");
  stringToDisplay("Welcome to DigiDough!", "Startup will begin shortly", "", "");
}

void loop() {
  // put your main code here, to run repeatedly:
  machine.run();
  delay(STATE_DELAY); // Delay for half a second
}