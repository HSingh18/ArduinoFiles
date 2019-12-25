Autonomous SUV
CSC 113 Final Project

Summary
	A number of today’s new motor vehicles have technology that helps drivers avoid drifting into adjacent lanes or making unsafe lane changes, or that warns drivers of other vehicles behind them when they are backing up, 
	or that brakes automatically if a vehicle ahead of them stops or slows suddenly, among other things. 
	These and other safety technologies use a combination of hardware (sensors, cameras, and radar) and software to help vehicles identify certain safety risks so they can warn the driver to act to avoid a crash.

Overview
	The First mode controls the SUV by using a joystick on an application which was connected to the Arduino using a Bluetooth module. 
	The directions of travel such as forward and backward are defined as functions that are compatible with the application. 
	The second mode is a fully autonomous mode where the SUV will drive on its own using an ultrasonic sensor scanning the area around it. 
	The program involves scanning the surrounding area, and looking for the greatest distance by using an ultrasonic sensor. 
	Once the largest distance is found after scanning, the vehicle should move in that direction until the value the ultrasonic sensor being read is less than 20 to prevent collision.

Improvements
	Improvements can be made to efficieny of the code and the hardware on the vehicle. 
	In the future we expect to use applications such as tensorflow and its AI capabilities along with OpenCV and its image processing capabilities to further improve vehicles. 

System Components
	Arduino UNO
	Breadboard
	Servo Arm
	Ultrasonic Sensor [HC-SR04]
	Wireless Controller [Bluetooth Module]
	Various Wires
	Photoresistors
	Power Bank
	LED's
	DC Motors
	Large Vehicle
		

How it Works: 
	The user will push buttons on an app which will correspond to the directions of travel for the Arduino UNO Vehicle. There will be a separate button which will activate the ultrasonic sensor. 
	Once activated the car will take over and scan a 180-degree area in 3 increments (90 degrees left and 90 right and straight) and find at which degree was the main/largest distance to travel is at. Once found, the system should travel in that direction.
	If the systems find an obstacle in its course, it will stop initiate a rescan, move backward and travel in the direction of least obstacles.  

References:
	
	
