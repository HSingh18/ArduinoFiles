#define LED1  7
#define LED2  8
#define LED3  9   //Skipped 10 because pin does not work
#define LED4  11
#define BUTTON1 2   //Skipped 0,1 because pins do not work
#define BUTTON2 3
#define BUTTON3 5   //Skiped 4 because pin does not work
#define BUTTON4 6

int counter = 0;  //counter so code doesnt run in a loop forever
int userarr[4];   //sequence of numbers that user inputted
int correct = 1;  //variable to see if both arr sequences match
int numarr[4];    //array in which the random number is stored
int sizeofarr = 4;    //max size of the array
int startdelay = 500;   //how long each LED stays on for

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
  Serial.begin(9600);
  Serial.println("Program Will Start:");
}

void randomLED(){
  for(int i = 0; i < sizeofarr; i++){
    numarr[i] = random(1, sizeofarr); //creating a random sequence of numbers
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
  }
}

void wrong1(){    //Function which will display LED's in a way to represent that your answer is incorrect
  for(int i = 0; i < 4; i++){   //this loop will run 4 times
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    delay(startdelay);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    delay(startdelay);
  }
}

void compare(){   //Function which will compare if the two arrays are the same
  for(int i = 0; i < 4; i++){ //this loop will see if the two sequences are the same
    if(numarr[i] == userarr[i]){
      correct++;
    }
    else{                     //if any one of the number are not equal to each other then counter gets reset to 0
      correct = 0;
    }
  }
  if(correct == 5){         //counter is first 1, and there are max 4 random numbers in array so 4+1=5
    Serial.println("Correct Sequence");
    correct1();   //Print out the LED sequence for correct
  }
  else{
    Serial.println("Wrong Sequence");
    wrong1();   //Print out the LED sequence for incorrect
  }
}

void loop() {
  if(counter == 0){
    randomLED();          //code to generate a random number
    counter++;
  }
  
  if(counter == 1){   //Getting the first input from the user/ the first button press
//    delay(startdelay);
    Serial.println("Your Turn");
    if(digitalRead(BUTTON1) == LOW){    //If BUTTON1 is pressed turn on LED1 and write 1 into the array at spot 0
      digitalWrite(LED1, HIGH);
      userarr[0] = 1;
      delay(500);   //delay is used to keep LED on for a certain amount of time
      digitalWrite(LED1, LOW);
      Serial.print("ARR1 = ");
      Serial.println(userarr[0]);
      counter++;
    }
    else if(digitalRead(BUTTON2) == LOW){   //If BUTTON2 is pressed turn on LED2 and write 2 into the array at spot 0
      digitalWrite(LED2, HIGH);
      userarr[0] = 2;
      delay(500);
      digitalWrite(LED2, LOW);
      Serial.print("ARR1 = ");
      Serial.println(userarr[0]);
      counter++;
    }
    else if(digitalRead(BUTTON3) == LOW){   //If BUTTON3 is pressed turn on LED3 and write 3 into the array at spot 0
      digitalWrite(LED3, HIGH);
      userarr[0] = 3;
      delay(500);
      digitalWrite(LED3, LOW);
      Serial.print("ARR1 = ");
      Serial.println(userarr[0]);
      counter++;
    }
    else if(digitalRead(BUTTON4) == LOW){   //If BUTTON4 is pressed turn on LED4 and write 4 into the array at spot 0
      digitalWrite(LED4, HIGH);
      userarr[0] = 4;
      delay(500);
      digitalWrite(LED4, LOW);
      Serial.print("ARR1 = ");
      Serial.println(userarr[0]);
      counter++;
    }
  }
  
  if(counter == 2){   //Getting the second input from the user/ the second button press
//    delay(startdelay);
    if(digitalRead(BUTTON1) == LOW){   //If BUTTON1 is pressed turn on LED1 and write 1 into the array at spot 1
      digitalWrite(LED1, HIGH);
      userarr[1] = 1;
      delay(500);
      digitalWrite(LED1, LOW);
      Serial.print("ARR2 = ");
      Serial.println(userarr[1]);
      counter++;
    }
    else if(digitalRead(BUTTON2) == LOW){   //If BUTTON2 is pressed turn on LED2 and write 2 into the array at spot 1
      digitalWrite(LED2, HIGH);
      userarr[1] = 2;
      delay(500);
      digitalWrite(LED2, LOW);
      Serial.print("ARR2 = ");
      Serial.println(userarr[1]);
      counter++;
    }
    else if(digitalRead(BUTTON3) == LOW){   //If BUTTON3 is pressed turn on LED3 and write 3 into the array at spot 1
      digitalWrite(LED3, HIGH);
      userarr[1] = 3;
      delay(500);
      digitalWrite(LED3, LOW);
      Serial.print("ARR2 = ");
      Serial.println(userarr[1]);
      counter++;
    }
    else if(digitalRead(BUTTON4) == LOW){   //If BUTTON4 is pressed turn on LED4 and write 4 into the array at spot 1
      digitalWrite(LED4, HIGH);
      userarr[1] = 4;
      delay(500);
      digitalWrite(LED4, LOW);
      Serial.print("ARR2 = ");
      Serial.println(userarr[1]);
      counter++;
    }
  }
  
  if(counter == 3){   //Getting the third input from the user/ the third button press
//    delay(startdelay);
    if(digitalRead(BUTTON1) == LOW){   //If BUTTON1 is pressed turn on LED1 and write 1 into the array at spot 2
      digitalWrite(LED1, HIGH);
      userarr[2] = 1;
      delay(500);
      digitalWrite(LED1, LOW);
      Serial.print("ARR3 = ");
      Serial.println(userarr[2]);
      counter++;
    }
    else if(digitalRead(BUTTON2) == LOW){   //If BUTTON2 is pressed turn on LED2 and write 2 into the array at spot 2
      digitalWrite(LED2, HIGH);
      userarr[2] = 2;
      delay(500);
      digitalWrite(LED2, LOW);
      Serial.print("ARR3 = ");
      Serial.println(userarr[2]);
      counter++;
    }
    else if(digitalRead(BUTTON3) == LOW){   //If BUTTON3 is pressed turn on LED3 and write 3 into the array at spot 2
      digitalWrite(LED3, HIGH);
      userarr[2] = 3;
      delay(500);
      digitalWrite(LED3, LOW);
      Serial.print("ARR3 = ");
      Serial.println(userarr[2]);
      counter++;
    }
    else if(digitalRead(BUTTON4) == LOW){   //If BUTTON4 is pressed turn on LED4 and write 4 into the array at spot 2
      digitalWrite(LED4, HIGH);
      userarr[2] = 4;
      delay(500);
      digitalWrite(LED4, LOW);
      Serial.print("ARR3 = ");
      Serial.println(userarr[2]);
      counter++;
    }
  }
  
  if(counter == 4){   //Getting the fourth input from the user/ the fourth button press
//    delay(startdelay);
    if(digitalRead(BUTTON1) == LOW){   //If BUTTON1 is pressed turn on LED1 and write 1 into the array at spot 4
      digitalWrite(LED1, HIGH);
      userarr[3] = 1;
      delay(500);
      digitalWrite(LED1, LOW);
      Serial.print("ARR4 = ");
      Serial.println(userarr[3]);
      counter++;
    }
    else if(digitalRead(BUTTON2) == LOW){   //If BUTTON2 is pressed turn on LED2 and write 2 into the array at spot 4
      digitalWrite(LED2, HIGH);
      userarr[3] = 2;
      delay(500);
      digitalWrite(LED2, LOW);
      Serial.print("ARR4 = ");
      Serial.println(userarr[3]);
      counter++;
    }
    else if(digitalRead(BUTTON3) == LOW){   //If BUTTON3 is pressed turn on LED3 and write 3 into the array at spot 4
      digitalWrite(LED3, HIGH);
      userarr[3] = 3;
      delay(500);
      digitalWrite(LED3, LOW);
      Serial.print("ARR4 = ");
      Serial.println(userarr[3]);
      counter++;
    }
    else if(digitalRead(BUTTON4) == LOW){   //If BUTTON4 is pressed turn on LED4 and write 4 into the array at spot 4
      digitalWrite(LED4, HIGH);
      userarr[3] = 4;
      delay(500);
      digitalWrite(LED4, LOW);
      Serial.print("ARR4 = ");
      Serial.println(userarr[3]);
      counter++;
    }
  }
  if(counter == 5){   //Once four inputs from the user are receieved, compare the two arrays
    for(int i = 0; i < sizeofarr; i++){ //this loop will output the sequence of numbers that you inputted. This is only for debugging
      Serial.println(userarr[i]);
    }
    compare();    //code to compare the two sequences of numbers
    counter++;    //END
  } 
}
