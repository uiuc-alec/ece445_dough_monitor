# Abhitya's Notebook

Week 1 Feb 5 - 11 | General Research and Proposal Writing
=========================================================

Did some work prior to this date, helping look for for parts that would work with project and conducting general research that was required for the subsystems.

First TA Meeting
----------------
That overviewed the scope of the project and how we visualized the entire project going, Tianxing gave very helpful reccomendations for sensors and how to properly write the proposal for the rest of the project.

Proposal
--------

Worked with teammates on the project proposal, helped define and flesh out some of the subsystem requirements. Researched and wrote the ethics and safety portion of the proposal. Also helped out with general edits and provided feedback wherever necessary throughout the document. Helped out with some research regarding the MCU as we needed to decide between the STM32 and ESP32 as I would be taking the lead on the application if we were to end up using the ESP.
Created the models seen below as temporary visuals for the modules.

![Top PCB](https://github.com/uiuc-alec/ece445_dough_monitor/assets/55109224/ad3204f6-59ab-44f4-a45a-3fe985892794)
![Bottom PCB](https://github.com/uiuc-alec/ece445_dough_monitor/assets/55109224/e7ec2914-2398-45fb-a8d2-3b4adff1ef80)

Team Contract
-------------

Additionally wrote the entire team contract for the project and shared with the team members in order to get their names and signatures on their versions and submit it individually. Followed the template provided and adjusted for the speific roles of the team members.

Week 2 Feb 12 - 18 | Parts research and Intial Design Document Work
===================================================================

Helped Jake and Alec out with research the sensors, displays and other parts that are required for the project to help put together the materials list and get a better understanding of how the project will look.

Second TA Meeting
-----------------

Reviewed the proposal and got better reccomendations on how to improve it and resumbit it for a better grade. 

Week 3 Feb 19 - 25 | Work on the Design Document
================================================

Created the models seen below that were used to demonstrate what the final product will likely look like around a lid. Helped out in the rest of the document for more robust requirements and verifications and giving more details throughout the presentation. Added more to the ethics and safety portion from the initial draft in the proposal. Specifically worked on the sensor and microcontroller subsystems as those are the parts of the project I will be working on in the future. Additionally created the schedule for the team for the semester and edited the document to maintain IEEE standards of writing.

![Top Lid Visual](https://github.com/uiuc-alec/ece445_dough_monitor/assets/55109224/8506251f-a6cd-445b-afbe-9b4f29a18c45)
![Bottom Lid Visual](https://github.com/uiuc-alec/ece445_dough_monitor/assets/55109224/a9552c51-e945-449a-b35c-952f2d380bde)


Week 4 Feb 26 - Mar 3 | Research on the Temperature and Distance Sensors
========================================================================

This week the main priority was to do more research on the temperature and distance sensors while Jake was creating the initial draft for the sensor board PCB.

Temperature Sensor
------------------
Initial thought LM335AZ
* Cheap
* Decent accuracy
* Fast measurement rate
* IC Sensor
* Analog Communication - extremely simple to implement in CUBE

Discovered that the LM235AH was available in the machine shop for free. Has the same exact capabilities as the LM335AZ with same communication and outputs. So we switched over to it.

Distance Sensor
---------------
VCNL3040 Sensor
* Utilizes proximity sensor (PS)
* Along with an infared emitting diode (IRED)
* I2C communication protocols
* Low power requirement
* Narrow beam to focus on exactly whats in front of it

Design Review
-------------
Presented the project to the TAs and Professor Fliflet, got good feedback on adjusting the high-leve requirements and what needs to be changed with the project itself based on the design doc. Jake showed off the progress on the PCBs and what the overall idea for the project looked like.

Week 5 Mar 4 - 10 | Start work with CUBE IDE and Temperature Sensor
===================================================================

Temperature Sensor and exploring CUBE
-------------------------------------

Got my first introduction to the CUBE IDE, and tested out simluating with the actual STM32F103 MCU that we would be using in the final prodct. Set up the internal clock, analog connections and the other main things required for the microcontroller to be functional. Learned about the proper pin assignments for the microcontroller. Learned more about HAL and the different ways to read in the information from the sensors within the libraries found on the CUBE IDE and on the microcontroller itself. Explored a bit of the SPI protocols that are in place and just got a better understanding of what working in CUBE would look like (things like what got updated if you changed the physical IOC, added any connections, or changed around pins). The initial attempt and random playing around in the IDE is seen in the picture right below.

<img width="322" alt="Screenshot 2024-05-02 at 9 23 53 PM" src="https://github.com/uiuc-alec/ece445_dough_monitor/assets/55109224/50b37c89-e994-4e31-8e13-da240f7b7011">

Unfortunately we did not have the dev board as we did not pick it up early enough and they ran out so we could not start actually testing the results of the code with it and instead had to rely on just using the debugger in the IDE to ensure the code was correct and ran perfectly. Found a few useful links and pieces of code for the temperature sensor that was implemented along with the perfect conversion rate for it from Voltage to Celsius. At the end of the week had the theoritical side of the coding done for the temperature sensor.

CUBE with I2C
-------------
Started doing some research on how to actually use the I2C protocol that the distance sensor required. I had the responsibility for getting both sensors to work so I started learning more about how it worked and how I could use HAL to receive the data from the sensor there were some very specifc quirks that I found about the VCNL 3040 that I was surprised by, including the fact that you could only use HAL_I2C_MEM_READ/WRITE with it and none of the other HAL_I2C methods were available for use.

Week 6 Mar 18 - 24 | Sick Week Not Much Work Done
=================================================

Come back extremely sick after spring break and was pretty much bedridden for most of it so got no work done for the project this week, other some more general research that I did regarding the I2C protocols.

Week 7 Mar 25 - 31 | Individual Report, Part Orders, Some Distance Sensor Research
==================================================================================

Continued research from the past few weeks about the distance sensor and actually accessing data from it. Found out about the 7 different modes and the 13 different command codes that all had different purposes. Heard that the sensor board got soldered earlier this week but was unable to get my hands on the dev board in order to work with both together.

Part Order
----------
Placed the order for 3 different parts that were required as extras for the project
* [Distance Sensor](https://www.digikey.com/en/products/detail/vishay-semiconductor-opto-division/VCNL3040/10414263?s=N4IgTCBcDaIGoGEByAZAzABgCwZAXQF8g)
* [Schottky Diodes](https://www.digikey.com/en/products/detail/toshiba-semiconductor-and-storage/CUS08F30-H3F/5114298)
* [Voltage Regulators]( https://www.digikey.com/en/products/detail/texas-instruments/TPS63001DRCR/1016476)

Individual Report
-----------------
Started and finished writing the individual report, detailing work I had already done in the CUBE IDE and with the tempmerature sensor, included information about plans for future work regarding the distance sensor and incorporation with the rest of the project.

Week 8 Apr 1 - 7 | Testing with Dev Board and Sensor Board
==========================================================

Working with Dev Board
----------------------
Finally got my hands on the dev board and the sensor board at the same time. Started off by just testing the code that I already had from before for the temperature sensor and did my own testing and specific calibration for the temperature I was at based off the intial results that were getting output to serial console. Finally got the correct conversion for it and managed to output the temeprature in both Celcius and Farenheit.

Working on Distance Sensor
--------------------------
Once the temperature sensor was working properly I moved over to the distance sensor. Initially found out that the address for the distance sensor needed to be shifted over in order to account for the 7 bit address that the I2C BUS used. Then tried to figure out how each of the read and write commands worked with each other and what I needed to use in order to get a reading. Utilized HAL_I2C_MEM_WRITE to write 0x00 to command code 0x03 in order to turn on the sensor and start actually reading in the PS data, learned about the different outputs for each current value of the IRED by writing 0x00 - 0x07 into the 0x04 command code, and read the data form the most and least significant bits from the command code at 0x08. This finally provided me with an output form the distance sensor as seen in the image below (slightly hidden in the top left corner, seen in the debugging console). This gave me the PS outputs I was looking for and I realized that I just had to map them now.

![IMG_0352](https://github.com/uiuc-alec/ece445_dough_monitor/assets/55109224/cc5e5a42-25ce-460c-bfdf-d33376c9709c)

Week 9 Apr 8 - 14 | Mappings for the Distance Sensor
====================================================
This week my main task was to map the PS output from the distance sensor into real life measurements in cm or inches. I chose to do it in cm and tested both the 0x00 mode (50mA) and the 0x07 mode (200mA) to determine which extreme provided the msot accurate results that matched what we were looking for in our high level requirements, an accuracy of ±1 cm below 10 cm and ±10% between 10-20 cm. I performed the mappings by marking a piece of paper at 0.2 cm intervals placing the distance sensor at a static location on one end and moving a box from interval to interval in order to get the PS output on the debugger console and map that over to the actual cm measurement. The way I set up this mapping and the specific mappings I got can be seen in the pictures below. These mappings were not perfect and did need to be revised a few times but I utilized the same method every time I had to do the distance mappings.

![IMG_0351](https://github.com/uiuc-alec/ece445_dough_monitor/assets/55109224/6a3b92ce-6912-4aed-a893-340f8d76963c)
![IMG_0353](https://github.com/uiuc-alec/ece445_dough_monitor/assets/55109224/bfc18e51-fcf4-4e2e-8b09-9d3570be0964)

Week 10 Apr 15 - 21 | Wire Crimipint, Mock Demo, and Final Demo Prep
====================================================================
Wire Crimping
-------------
Jake asked me to help out by crimping some wire to connect the sensor board to the main PCB, I tried my best since it was my first time cirmping wires. I think the crimps on the ends turned out ok but the wire lengths were all over the place and not perfect.

Mock Demo
---------

This week mainly consisted of general debugging and trying to get to a point in the project that was feasible for presentation. Most of my assigned work in the project was done (figuring out how to recieve and translate the information from the sensors into their readable formats), so I just assisted Jake and Alec in any way I possibly could. Alec realized that there was no way the display could be hosted on CUBE IDE and that it was impossible for the sensors and STM32 to utilize the ArduinoIDE and we scraped together a piece of the final device for the mock demo with Tianxiang.

Final Demo Prep
---------------

Started theorizing how we would be able to actually demo the device to the professor and other onlookers. I thought we could have a video of the device doing its actual job monitoring dough and seeing that whole process through in a timelapse but unfortunately the device was not complete in time for that to work. We also theorized using differnt blocks and just moving something towards the distance sensor to show off how it would adjsut its readings and calculate the dough height while the object moved in front of it (similar to how I tested the sensor in the first place).

Week 11 Apr 22 - 28 | Final Demo and Mock Presentation
======================================================

Final Demo
----------
In the final demo, Jake and Alec used their idea for the demo to show to the professor, TAs, and students. I think it went well and that we and the device answered any questions that were brought up. Demo went well and I think everyone liked the project we had.

Mock Presentation
-----------------

Even though the mock presentation only needed to be a few slides long, we wanted to have the whole presentation done by the 26th just to get a practice run for the presentation in before the final one.

I pretty much completed the entire presentation, did all of the design elements that are seen, and converted most of the text that was in the design document into a presentable format. This was finally presented at the mock presentation where we did not receive too much negative feedback but we could definitely cut down on the wordiness of the slides.


Week 12 Apr 29 - May 3 | Final Presentation, Final Paper, Awards Show
=====================================================================

Final Presentation
------------------
Did all of the edits that were needed for the final presentation based on the comments made by the TAs and communications majors who attended the mock presentation. Assigned each team member their slides to present based on the information that the knew and their presentation ability. 

Final presentation went well and I think everyone enjoyed both looking at our slides and the overall presentation of the information itself. There were no major questions after the presentation so that is always a good thing. 

Final Paper
-----------
Wrote most of the final paper
* All the formatting, correct font, correct sizing, correct headings
* All of the Figure/Table labelling and in text citations for sources and figures/tables
* Ensuring the spacing was correct throughout the paper
* Maintaing proper sizing of the images included to make sure there are no major blank spaces
* General Outlining and implementing template
* Abstract
* Table of Contents
* Entire 1. Introduction section
* Most of the 2.1 Power and 2.2 Sensor subsystems
* All of 2.3.2 User Experience and 2.4 Microcontroller subsystem
* All of 3.2 Sensor Subsystem Verification and 3.4 Microcontroller Subsystem Verification
* All of 4. Costs and 5. Conclusion
* Added all the relevant references
* Created a new edited parts table and requirements and verifications table
