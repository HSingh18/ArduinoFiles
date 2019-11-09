# Solar Light Tracker
CSC 113 Project 3

Summary
	Solar trackers are devices used to orient photovoltaic panels, reflectors, lenses or other optical devices toward the sun. 
	Since the sun's position in the sky changes with the seasons and the time of day, trackers are used to align the collection system to maximize energy production.

Overview
	You are in charge of creating a prototype embedded system that can help pinpoint the maximum source of light. 
	This system will later be used in future planned products such as adjustable solar panels. 
	Design and implement an embedded system that can find and follow the maximum light source position using a photoresistor, servo and the Arduino board.

System Components
	Arduino board
	Photoresistor
	Servo
	Breadboard
	Wires
	Push Button
	LED

How it Works: 
	The system will scan an area to find the most intense light source using the photo resistor and the servo. 
	Once the strongest light source is found the servo will move its arm to the strongest light source position 
	The system will initiate a scan for the strongest light source in order to find the maximum using the following conditions/parameters: 
		a.	A set period that can be adjustable by user (example: scan every 5 sec) 
		b.	A change in light level triggers a rescan (sensitivity should be adjusted by user) 
		c.	A user request to rescan (examples: a button was pressed) 

	
	