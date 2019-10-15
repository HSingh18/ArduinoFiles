#define LED1  7
#define LED2  8
#define LED3  9
#define LED4  10
#define LED5  11
#define BUTTON1 2   //Skipped 0,1 because pins do not work
#define BUTTON2 3
#define BUTTON3 4
#define BUTTON4 5
#define BUTTON5 6

int counter = 0;  //counter so code doesnt run in a loop forever
int correct = 1;  //variable to see if both arr sequences match
int sizeofarr = 5;    //max size of the array
int startdelay = 500;   //how long each LED stays on for
int numarr[10];    //array in which the random number is stored
int userarr[10];   //sequence of numbers that user inputted
int counterforsizeofarr = 0;    //counter for adding user inputs into an array

void setup() {
  randomSeed(analogRead(0));  //generate a random number
  pinMode(LED1, OUTPUT);    //assign pin to OUTPUT
  pinMode(BUTTON1, INPUT_PULLUP);   //assign pin to INPUT, PULLUP is used as a virtual resistor for the switch
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(LED3, OUTPUT);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(LED4, OUTPUT);
  pinMode(BUTTON4, INPUT_PULLUP);
  pinMode(LED5, OUTPUT);
  pinMode(BUTTON5, INPUT_PULLUP);
  sizeofarr = random(1, 6);   //assign a random number from 1 to 5 to be the max siz of the random array
  Serial.begin(9600);
  Serial.println("Program Will Start:");
}

void randomLED(){
  for(int i = 0; i < sizeofarr; i++){
    numarr[i] = random(1, 6); //creating a random sequence of numbers
  }
  for(int i = 0; i < sizeofarr; i++){ //this loop with print the sequence with LED's, i am using serial.print statement to stim this
    if(numarr[i] == 1){       //if the arr[i] is 1, then turn LED1 on for "startdelay" amount of time, also print 1
      digitalWrite(LED1, HIGH);
      Serial.println("1");
      delay(startdelay);
      digitalWrite(LED1, LOW);
      delay(startdelay);
    }
    if(numarr[i] == 2){   //if the arr[i] is 2, then turn LED2 on for "startdelay" amount of time, also print 2
      digitalWrite(LED2, HIGH);
      Serial.println("2");
      delay(startdelay);
      digitalWrite(LED2, LOW);
      delay(startdelay);
    }
    if(numarr[i] == 3){   //if the arr[i] is 3, then turn LED3 on for "startdelay" amount of time, also print 3
      digitalWrite(LED3, HIGH);
      Serial.println("3");
      delay(startdelay);
      digitalWrite(LED3, LOW);
      delay(startdelay);
    }
    if(numarr[i] == 4){   //if the arr[i] is 4, then turn LED4 on for "startdelay" amount of time, also print 4
      digitalWrite(LED4, HIGH);
      Serial.println("4");
      delay(startdelay);
      digitalWrite(LED4, LOW);
      delay(startdelay);
    }
    if(numarr[i] == 5){   //if the arr[i] is 5, then turn LED4 on for "startdelay" amount of time, also print 5
      digitalWrite(LED5, HIGH);
      Serial.println("5");
      delay(startdelay);
      digitalWrite(LED5, LOW);
      delay(startdelay);
    }
  }
}

void correct1(){    //Function which will display LED's is a way to represent that your answer is correct
  for(int i = 0; i < 10; i++){    //this loop will run for 10 times
    digitalWrite(LED1, HIGH);
    delay(startdelay/8);
    digitalWrite(LED1, LOW);
    delay(startdelay/8);
    digitalWrite(LED2, HIGH);
    delay(startdelay/8);
    digitalWrite(LED2, LOW);
    delay(startdelay/8);
    digitalWrite(LED3, HIGH);
    delay(startdelay/8);
    digitalWrite(LED3, LOW);
    delay(startdelay/8);
    digitalWrite(LED4, HIGH);
    delay(startdelay/8);
    digitalWrite(LED4, LOW);
    delay(startdelay/8);
    digitalWrite(LED5, HIGH);
    delay(startdelay/8);
    digitalWrite(LED5, LOW);
    delay(startdelay/8);
  }
}

void wrong1(){    //Function which will display LED's in a way to represent that your answer is incorrect
  for(int i = 0; i < 4; i++){   //this loop will run 4 times
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    delay(startdelay);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    delay(startdelay);
  }
}

void compare(){   //Function which will compare if the two arrays are the same
  for(int i = 0; i < sizeofarr; i++){ //this loop will see if the two sequences are the same
    if(numarr[i] == userarr[i]){
      correct++;
    }
    else{                     //if any one of the number are not equal to each other then counter gets reset to 0
      correct = 0;
    }
  }
  if(correct == sizeofarr+1){         //counter is first 1, and the max size of the array is defined by sizeofarr
    Serial.println();   //printing "Correct Sequence" on a new line
    Serial.println("Correct Sequence");
    correct1();   //Print out the LED sequence for correct
  }
  else{
    Serial.println();   //printing "Correct Sequence" on a new line
    Serial.println("Wrong Sequence");
    wrong1();   //Print out the LED sequence for incorrect
  }
}

void buttonclick(){   //function that will check which button the user clicked
  for(int i = 2; i <= 6; i++){    //loop will trverse thru all the buttons checking to see which one gets clicked first
    if(digitalRead(i) == LOW){    //if a button does get clicked
      digitalWrite(i+5, HIGH);    //turn on the respective led which happens to be +5 the assigned button pin
      userarr[counterforsizeofarr] = i-1;   //set the user arr to the number represented by the led
      delay(500);
      digitalWrite(i+5, LOW);   //turn off the led
      Serial.print("ARR");Serial.print(counterforsizeofarr);Serial.print(" = ");
      Serial.println(userarr[counterforsizeofarr]);
      counterforsizeofarr++;
    }
  }
}

void loop() {
  if(counter == 0){
    randomLED();          //code to generate a random number
    counter++;
    Serial.println("Your Turn");
  }
  while(counterforsizeofarr != sizeofarr){    //run the function buttonclick() until the userarr is filled with as many elements as in the numarr
    buttonclick();    //function to check which button the user clicked
  }
  if(counterforsizeofarr == sizeofarr && counter == 1){   //as soon as the array is filled, print out the array and see if the two arrays are matching
    Serial.print("Your Answer: ");
    for(int i = 0; i < sizeofarr; i++){ //this loop will output the sequence of numbers that you inputted. This is only for debugging
      Serial.print(userarr[i]);
    }
    compare();    //code to compare the two sequences of numbers
    counter++;    //increment counter so that the code doesnt stay in this loop
  } 
}
