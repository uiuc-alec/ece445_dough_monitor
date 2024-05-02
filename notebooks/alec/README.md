# Alec's Notebook

2024-01-23 - Preliminary parts research
=======================================

Jake started looking into a lot of the parts for the project, and I found a display and battery that would likely work too. 

Display: [4x16 Character LCD](https://newhavendisplay.com/4x16-character-lcd-stn-blue-display-with-white-side-backlight/)  
Battery: [Adafruit Li-ion battery - 3.7V 2000mAh](https://www.microcenter.com/product/503621/Lithium_Ion_Battery_-_37v_2000mAh)

This display would be simpler than some others that might have more customizable (just a 4x16 character LCD compared to being able to write each pixel), but we are still exploring options and if this is really what we should go with.

2024-02-08 - Proposal
=======================================

I worked on the block diagram, tolerance analysis, subsystem requirements (with Jake), and document formatting for the Project proposal. 
The tolerance analysis uses ESP32-S3 as the MCU because with some of the software stretch goals we have, the ESP32 would allow us to connect to the wifi and let us potentially connect to AWS and a mobile app. However, with the experience Jake has with the STM32 and some of the extra resources the STM32 has (IDE and documentation), we will likely be using that instead and offloading any of the connectivity and AWS connections to a Raspberry Pi Zero communicating with our MCU. We think this will allow Abhitya to work on some of the software functionality without needing the hardware side mostly done and keep the main focus of the project on our more hardware focused goals.

2024-02-10 - Display research/design
====================================

Jake did some more research on the displays and potentially using a more customizable display communicating with the MCU. I thought this seemed like a fine idea because it brings some embedded software components to the main functionality of the project, which is good for Abhitya and me. I did a bit more research into the [Pervasive Displays brand E-ink display](https://www.digikey.com/en/products/detail/pervasive-displays/E2266JS0C1/13572401) and found the [actual datasheet](https://www.pervasivedisplays.com/wp-content/uploads/2021/12/1P257-00_04_E2266CS0C1-E2266CS0C2_20211129.pdf) and found out all the communciation with the MCU would be via SPI, which should be a doable challenge since we have some experience on the team with SPI. I also found a [development kit for the displays](https://www.pervasivedisplays.com/product/epd-extension-kit-gen-3-ext3/) that might be useful whenever we are usign development boards at first. 

2024-02-13 - Questions for TA and other considerations
====================================

I have been thinking about how we should be finalizing our components. Something I would like to ask the TA is about our current choices for sensors because some of them don't have exposed leads, which seemed like something they pushed us to try to find in lecture. So, getting feedback on these components and if we need to find others with exposed leads that are similar instead would be helpful. 

Our team has discussed how the boards will be configured since we probably need two, one main board with the MCU, display, buttons, etc on top and a smaller board with the sensors to be attached to the underside of a lid. The thought is that power and data cables could easily be run to this board while still keeping the container relatively closed and at a good temperature. If not, we may have to explore two boards and wireless communication. 

We are wondering when we should be starting and really finishing a lot of the development board work. It seems like we should be starting this week to me, but I am not sure if I am skipping over some steps. 

Something I need to ask the team about is the power module and how that system is really supposed to work. I made the block diagram according to some other systems I had seen with similar setups, but I don't quite understand what the whole module would look like in hardware.

I have been looking into different distance sensors, but I have not been able to find anything with exposed leads that really fits for our application yet. There are quite a few modules that already have a PCB and communicate via I2C with the MCU, but the search for just a sensor with exposed leads has been less fruitful. Is something like [this](https://4donline.ihs.com/images/VipMasterIC/IC/VISH/VISH-S-A0011791776/VISH-S-A0011791776-1.pdf?hkey=CECEF36DEECDED6468708AAF2E19C0C6) better? Or is something like [this](https://www.mouser.com/ProductDetail/KEMET/SS-430?qs=vLWxofP3U2z%2FzgQsnF8qAg%3D%3D) better than a solderable component if we can't find one with exposed leads?


2024-02-16 - Project Proposal
====================================
We ended up getting an 18/21 on our project proposal, which is good relative to the other groups (average < 15), but we would like to get more feedback on what was lacking or wrong to improve our Design document and how we might be able to regain some of those points through the regrade. The only element of our proposal that I thought may have been lacking compared to some groups is that we hadn't locked down exactly what components we are going to use, but I also didn't think having specific components picked out was a requirement of that assignment. 

I also was looking into the difference between the Design Document and the Proposal and saw two main differences between the example Design Doc and their Proposal
1. Their requirements and verifications were significantly improved and "beefed up"
2. There are a lot more details worked out for implementation, exact parts needed, and how the project more completely works.

We had some of our verifications already done (and removed) from the Proposal, so that is not the biggest concern with the Design Doc. Locking down exact details and parts will be very important for this assignment, though, and where I anticipate most of our work will be. 

2024-02-18 - Design Doc Progress
====================================
I worked on the Design Doc and research for a few hours, locking down some much needed details on the power subsystem and improving some of the Verifications (although I think worsened some of the Requirements {in regards to the rubric} to make them more user behavior driven than criteria driven). This is something we need to ask the TA about this week. We also need to ask the TA if the Design Document is intended for us only to think more about our project details or if we will lose points if we need to change components or even a RV that ended up being impossible or unneeded. I also updated the sensor subsystem information and filled out most of the cost analysis table. There is still a fair bit of needed research and updates to the doc to be done before the deadline, and I know things will pick up once Jake is done with his exams and Abhitya starts working on the Design Doc too.

2024-02-22 - Finishing Design Doc
====================================
Our team finished the Design Doc and made corrections to our Project Proposal. I probably worked on the Design Doc for 4+ hours throughout the day, finishing all the requirements and verifications, making the state machine, the example UI button interface, doing a lot of research to add more details and the "why" behind some of our hardware choices (mainly the sensors and why we chose certain kinds over others). Overall, we are pretty satisfied with how everything turned out, and I know Jake did a lot of work on the actual design too, so we have a much better idea of implementation now too. 


2024-02-26 - Design Review Prep
====================================
I researched I2C and how our distance (VCSEL) sensor implements I2C. I also found the libraries we can use to help program the distance sensor and some example STM32F code for the sensor. Since our display is no longer just a character display and uses SPI, I researched that as well and found some libraries we can use to help us program the display and all of the documentation and examples with an Uno and some development boards. Doing some intial testing with the displays and the STM32 development board are two of the tasks I plan on working on in the next two weeks, starting with ordering some of the parts tomorrow morning. 


2024-03-1 - First Attempt in Displays Programming
====================================
Our display, the display development kit, and our distance sensors came in the mail, and I started playing around with the display and development kit. The documentation is slightly worse than I expected, and I was not able to get either the Pi Pico I had or the Arduino Uno I had working with the display. I ran into memory issues with the Uno, and I ran into setup issues with the Pi Pico that wouldn't allow me to program it with the code I had. I am fairly sure the Pervasive Displays libraries for the displays are fine, and if I can get around the memory issues by using a better Arduino board, I can start doing our actual text display development. 

2024-03-6 - Second Attempt in Displays Programming
====================================
Take two was not much better than take one. I managed to get rid of the memory error I had with the Uno by storing the bitmap files in flash memory instead of SRAM. However, it seems like I am still probably getting memory issues with the Uno not being able to load everything correctly into SRAM because it simply doesn't fit, but we shal see once I get a better MCU with more SRAM. Abhitya and I spent a few hours working on our stuff in that. It seemed like he found a lot of what needed to be done on the programming side of things once we have the STM32 to program and some of our other sensors, and I am more confident that the display will work well once we get an MCU with more memory. 

2024-03-12 - Third Attempt in Displays Programming
====================================
Success! I managed to get the display to output all four of its colors over break once I got an Arduino with more memory (ESP32 version). I found some nice libraries to use in the Arduino IDE for the display I had since the other libraries online didn't work correctly, and this is going to be very helpful once we switch over to the STM32. 

The only downside that I noticed is that the display takes a very long time to update since updating is not really its intended use. That should be fine since we don't update it but once every few minutes, but we were thinking about being able to display a seperate screen during the setup, and we do not know how long that will take, so we may have to opt for some status LEDs instead. 
![IMG_9037](https://github.com/uiuc-alec/ece445_dough_monitor/assets/144295293/dd8cd608-49d2-4cb8-963d-d8bc8d9b6f2e)

2024-03-24 - Developing with the Dev Board
====================================
I got the dev board out today (STM32 Nucleo-F103RB), connected it to our sensor module (see below), and got the temperature to output to the debug console and verified it at least reads temperature increases when the hot soldering iron is close. There is still a bit more work to do on the distance sensor end since that deals with I2C, and we need to read through more documentation to get the conversions from the data it sends us and distance. The steps to getting this set up are below.
![IMG_9070](https://github.com/uiuc-alec/ece445_dough_monitor/assets/144295293/012603e4-753c-4d1d-902c-479e13d38f80)

* Connect the [header](https://github.com/uiuc-alec/ece445_dough_monitor/assets/144295293/1f3ef5ef-3162-434d-9186-b3988bf72ae7) as so:
  - Pin 1 to 3V3
  - Pin 2 to SDA/D14
  - Pin 3 to SCL/D15
  - Pin 4 to A0
  - Pin 5 to GND
* Start CubeIDE. LOG IN to MY ST FIRST. You will get an error on download if you don't. Select STM32 Project. Click the tab with "Board Selector". Type in "Nucleo-F103RB" in the "Commercial Part Number" field. The board should be listed on the right side. Click it then click "Next"
* Give it a name and feel free to change the location. Everyting else can stay default. Click "Finish". "Yes" to all the default windows that pop up. 
* You should now see the chip outline on the right hand side. Find PB8 and PB9, click on each to change to "I2C1_SCL" and "I2C1_SDA", respectively. Similarly, change PA0 to "ADC1_IN0".
* On the left hand "Categories" menu, expand "Connectivity" click I2C1. Then select "I2C" from the dropdown.
* There is some issue with the clock now. Click "Clock Configuration" on the top menu and "Yes" to automatic clock solver. Click "Resolve Clock Issues". Now, Save the project and click "Yes" and  "Yes" to generate Code.
* The updated main.c file will be in the [code directory](https://github.com/uiuc-alec/ece445_dough_monitor/tree/main/code), along with the project file if you would like to just use that instead. In case you have to go through setup again, this guide will help. 

2024-03-26 - Developing with the Dev Board v2
====================================
Today consisted of a lot of playing around with the display with both the Arduino Nano ESP32 and the STM32 Nucleo Dev board, learning how the libraries and examples work and getting both to work in Arduino IDE. Getting the display to work in Cube IDE is still a work in progress, but that is the next step. Once I know how to get the display working in Cube IDE, I will start on the actual displays programming portion and output at least the temperature sensor data to the display (and the distance sensor data is Abhitya finishes the programming for that component as well). Good call by Jake on using the STM32. I don't know how using the ESP32 would have gone, but a lot of the work I have done in getting outputs to the display have been with some great documentation available online for the STM32 and some decent documentation from Pervasive Displays too.
![IMG_9075](https://github.com/uiuc-alec/ece445_dough_monitor/assets/144295293/f6e62438-c51b-4def-a516-3e60a24a5ee5)

2024-04-08 - Finding out Arduino IDE was the one all along
====================================
It has been a bit since I have updated my lab notebook, but I have been working on this class during that gap. Specifically, I figured out using STM32 Cube IDE essentially won't be feasible for our project because the whole displays library is only compatible with Arduino. This is great news because our project doesn't need most of the stuff that Cube offers, and Cube was a bit complex to set up with the display, outside of the libraries not working. So, now that we are moving everything over to Arduino IDE (and since we should be able to program our custom board form Arduino IDE too), we have a fairly working project (first try). Take a look at [this video](https://drive.google.com/file/d/1r-k32tJ0C0dS603PVmvIE38z30WdJD5y/view?usp=drive_link) for an example.
The sensors read every 20 seconds and update the values for the display from the readings. The temperature reading has been set to be correct, but I am still waiting on Abhitya to finish the distance sensor conversions (since there is no nice way to map distance with our sensor... we found out a bit too late to make any changes to the design). 
The final implementation will be much better than this current one, getting averged readings, integrating the UI buttons, and expanding what the display can show. Once our PCB order arrives (2 week turnaround time is awful), we will test our board and hope we have a decent prototype for the mock demo.

2024-04-19 - Finding out Arduino IDE was NOT the one all along
====================================
This entry is for the last ten days where Jake finished the main PCB, and I started testing it and trying to get it to work. The great news is that I can use the ST-Link portion of the development board to program our PCB. The bad news is that the programming does not seem to work quite right in Arduino IDE, and the pin assignments don't seem to be working the way we expecting either. Essentially, we ran into some big issues with Arduino IDE. It is unfortunate because we know that everything works individually, but we have not been able to integrate them because of these issues, and using Cube IDE for our custom board is not simple because our display requires Arduino libraries to function. Modifying these to work in a C++ cube project or finding another library to work would be time consuming and difficult, but we would like to get the main PCB fully working before the demo, so this is high on our list to test prior to next week's demo. Otherwise, I fixed the code I wrote for the development board, mapped the distance sensor values to distances, and figured out how to integrate the buttons nicely, so the software side is completely done for the development board. We are in the final stretch, and I really hope I can figure out how to get the custom PCB working with everything.

2024-04-24 - Finding out Arduino IDE and CubeIDE were NOT the ones all along
====================================
This message is sponsored by PlatformIO, the IDE built into VS Code that saved our project. PlatformIO was "Our Gateway to Embedded Software Development Excellence," as they would put it. Realistically, what we did in PlatformIO likely would have worked in Arduino IDE as well, but we kept gaining progress in PlatformIO after we switched (unrelated to Arduino IDE not working), and we had no reason to look back. 

There is a lot that happened in the last few days before the final demo: getting the enclosures 3D printed, trying to make a cover for the sensor module, getting other parts for the final assembly, and getting the actual device to function. I was doing quite a bit of debugging and decided to see if we would have any more luck with Platform IO than on Ardunino IDE, and after realizing the reason why our serial output was not displaying was from the Rx and Tx connectors not being connected, we kept going on a roll in PlatformIO. We ran into some memory issues with our font libraries, but I managed to fix those issues, and everything was working outside of the display at this point. We knew the display code was running, but the display was not being recognized for some reason. After working with Jake on some of the pin mappings, we realized the pin mappings he used for the display were not only not standard, but also wrong. Fortunately, the pins we did need were connected to the button inputs on the PCB, so we were able to switch those around and make some modifications to the variant_generic.h pin mapping file to get everything to work.

Once it was all functional, we assembled it and tested everything to get our finished product.

There was a lot of work that went into the week of the 24th and the tail end of the prior week to get this device to work (I don't feel like including all of the details now since it was just a lot of documentation reading and debugging). Jake and I are very proud of the completed device, and this class was very interesting (and challenging). 

The rest of the entries will be photos of our device. The [video of our project](https://www.youtube.com/watch?v=4N0sI_6v96w) is something I made as well, and we hope to make a funnier version of this video that the course staff can use in the future as well. 
