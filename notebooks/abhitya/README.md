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
* Analog Communication

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

Got my first introduction to the CUBE IDE, and tested out simluating with the actual STM32F103 MCU that we would be using in the final prodct. Set up the internal clock, 

Week 6 Mar 18 - 24 | 
======================================================================

Week 7 Mar 25 - 31 | 
=============================================================

Week 8 Apr 1 - 7 | Work on getting Readings from the Distance Sensor
=============================================================

Week 9 Apr 8 - 14 | Mappings for the Distance Sensor
====================================================

Week 10 Apr 15 - 21 | Mock Demo and Final Demo Prep
===================================================

Week 11 Apr 22 - 28 | Final Demo and Mock Presentation
======================================================

Week 12 Apr 29 - May 3 | Final Presentation and Final Paper
===========================================================
