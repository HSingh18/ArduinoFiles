const int ledpin = 13;    //LED pin # on the arduino chip
int num1 = 0;   //first number that the user inputed
int num2 = 0;   //second number that the user inputed
int redlighttime = 0;   //time that the red light will stay on for
int greenlighttime = 0;   //time that the green light will blink for
int i = 0;    //counter variable

void setup() {
  pinMode(ledpin, OUTPUT);    //assign pin to OUTPUT
  Serial.begin(9600);
  Serial.println("Enter the values for Redlight and Greenlight");
  delay(2000);
}

void loop() {
  if(i == 0 || i == 1){   
    if(Serial.available() > 0 && num1 == 0){    //if the user has not inputed a number and the serial is greater than 0
      num1 = Serial.read();   //set the digit inputed from the user to num1
      i++;
    }
    if(Serial.available() > 0 && num2 == 0){    //if the user has not inputed a number and the serial is greater than 0
      num2 = Serial.read();   //set the digit inputed from the user to num2
      i++;
    }
  }
  
  if(i == 2){   //print the values of num1 and num2, Mainly used for debugging
    Serial.println("Values:");
    Serial.print("num1:");
    Serial.println(num1-48);
    Serial.print("num2:");
    Serial.println(num2-48);
    i++;
  }
  
  if(i == 3){   //repeat this loop over and over again
    Red(num1-48);   //keep redlight on for num1 amount of times
    Green(num2-48);   //keep greenlight on for num2 amount of times
  }
}

void Red(int x){    //RedLight function which will keep the LED turned on for x amount of seconds
  Serial.println("RedLight is turned on");
  digitalWrite(ledpin, HIGH);
  delay(x*1000);
  digitalWrite(ledpin, LOW);
}

void Green(int x){    //GreenLight function which will blink LED for x amount of seocnds
  Serial.println("GreenLight is blinking");
  while( x != 0){
    Serial.print("You have "); 
    Serial.print(x);
    Serial.println(" seconds to cross the street");
    digitalWrite(ledpin, HIGH);
    delay(500);
    digitalWrite(ledpin, LOW);
    delay(500);
    x--;
  }
}
