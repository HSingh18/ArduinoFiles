#include <SoftwareSerial.h>   //including bluetooth libaries

#define MotorBack 7   
#define MotorForward 8   
#define MotorLeft 9   
#define MotorRight 11
#define FrontLights 12
#define Photoresistor A5   

//global variables
SoftwareSerial mySerial(0, 1); // RX | TX
int val;    //variable to hold Serial.reads value

void setup() {
  pinMode(MotorBack, OUTPUT);
  pinMode(MotorLeft, OUTPUT);
  pinMode(MotorRight, OUTPUT);
  pinMode(MotorForward, OUTPUT);
  pinMode(FrontLights, OUTPUT);
  
  //setting all PINS to LOW
  digitalWrite(MotorBack, LOW);
  digitalWrite(MotorForward, LOW);
  digitalWrite(MotorLeft, LOW);
  digitalWrite(MotorRight, LOW);
  digitalWrite(FrontLights, LOW);
  
  Serial.begin(9600);
  mySerial.begin(9600);   //starting bluetooth controller
  Serial.println("Starting Code in 5 Seconds");
  delay(5000);
}

void Forward(){   //control motors to go forward
  digitalWrite(MotorBack, LOW);
  Serial.println("Going Forward");
  digitalWrite(MotorForward, HIGH);
}

void Backward(){    //control motors to go backwards
  digitalWrite(MotorForward, LOW);
  Serial.println("Going Backwark");
  digitalWrite(MotorBack, HIGH);
}

void Left(){    //control motors to go left
  digitalWrite(MotorRight, LOW);
  Serial.println("Turning Left");
  digitalWrite(MotorLeft, HIGH);
}

void Right(){   //control motors to go right
  digitalWrite(MotorLeft, LOW);
  Serial.println("Turning Right");
  digitalWrite(MotorRight, HIGH);
}

void Stop(){    //stop all motors
  digitalWrite(MotorForward, LOW);
  digitalWrite(MotorBack, LOW);
  digitalWrite(MotorLeft, LOW);
  digitalWrite(MotorRight, LOW);
}

void NoTurn(){    //reset the left and right motors to go striaght
  digitalWrite(MotorLeft, LOW);
  digitalWrite(MotorRight, LOW);
}

void loop() {
  if(mySerial.available()){   //if bluetooth connection is available
    val = mySerial.read();    //read the values being recieved by Bluetooth controller
    
    //code for automatic headlights
    if(analogRead(Photoresistor)< sensitofPhotoresistor){
      digitalWrite(FrontLights, HIGH);
    }
    if(analogRead(Photoresistor) >= sensitofPhotoresistor){
      digitalWrite(FrontLights, LOW);
    }
    
    //code to check which button was pressed by the user on the smartphone app
    if(val == 'F'){   //Forward
      Forward();
    }
    if(val == 'B'){   //Backward
      Backward();
    }
    if(val == 'L'){   //Left
      Left();
    }
    if(val == 'R'){   //Right
      Right();
    }
    if(val == 'W'){   //Turn front wheels straight
      NoTurn();
    }
    if(val == 'U'){   //Set all motor pins to LOW
      Stop();
    }
}
