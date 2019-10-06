# Traffic Light
CSC 113 Project 1

Summary
	Traffic lights alternate the right of way accorded to users by illuminating lamps or LEDs of standard colours (red, amber (yellow), and green) following a universal colour code. 
	The green light allows traffic to proceed in the direction denoted, if it is safe to do so and there is room on the other side of the intersection. The red signal prohibits any traffic from proceeding.

Overview
	The mayor has seen an increase in hit and run accidents because of incorrect timing of cross walk indicators. Your task as an embedded system designer is to design and implement a simple traffic pedestrian cross walk indicator.

System Components
	Arduino board

How it Works: 
	A user should be able to input two digits. One will be the length of the red light and the second will be the length of time to allow pedestrians to cross. This loop should continue until the user ends the program.
	The LED should do the following:
		When the pedestrian view traffic light is red (unsafe to walk) the LED should stay steady on.
		When the pedestrian view traffic light is green (safe to walk) the LED should blink very quickly to indicate safe walking.
	
	