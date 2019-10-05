#define LED 7
int counter = 0;  //counter so code doesnt run in a loop forever
int userarr[4];   //sequence of numbers that user inputted
int correct = 1;  //variable to see if both arr sequences match
int numarr[4];    //array in which the random number is stored

void setup() {
  randomSeed(analogRead(0));  //generate a random number
  //add code to assign LED pin to output
  Serial.begin(9600);
  Serial.println("Program Will Start:");
}

void randomLED(){
  for(int i = 0; i < 4; i++){
    numarr[i] = random(1, 4); //creating a random sequence of numbers
  }
  for(int i = 0; i < 4; i++){ //this loop with print the sequence with LED's, i am using serial.print statement to stim this
    if(numarr[i] == 1){       //if the arr[i] is 1, then turn LED on, in this case print 1
      digitalWrite(LED, HIGH);
      Serial.println("1");
    }
    if(numarr[i] == 2){
      digitalWrite(LED, HIGH);
      Serial.println("2");
    }
    if(numarr[i] == 3){
      digitalWrite(LED, HIGH);
      Serial.println("3");
    }
    if(numarr[i] == 4){
      digitalWrite(LED, HIGH);
      Serial.println("4");
    }
  }
}

void compare(){
  for(int i = 0; i < 4; i++){ //this loop will see if the two sequences are the same
    if(numarr[i] == userarr[i]-48){
      correct++;
    }
    else{                     //if any one of the number are not equal to each other then counter gets reset to 0
      correct = 0;
    }
  }
  if(correct == 5){         //counter is first 1, and there are max 4 random numbers in array so 4+1=5
    Serial.println("Correct Sequence");
  }
  else{
    Serial.println("Wrong Sequence");
  }
}

void loop() {
  if(counter == 0){
    randomLED();          //code to generate a random number
    counter++;
  }
  if(counter == 1 && Serial.available() > 0){
    delay(5000);
    Serial.println("Your Turn");
    userarr[0] = Serial.read();
    counter++;
  }
  if(counter == 2 && Serial.available() > 0){
    userarr[1] = Serial.read();
    counter++;
  }
  if(counter == 3 && Serial.available()){
    userarr[2] = Serial.read();
    counter++;
  }
  if(counter == 4 && Serial.available()){
    userarr[3] = Serial.read();
    delay(2000);
    counter++;
  }
  if(counter == 5){
    for(int i = 0; i < 4; i++){ //this loop will output the sequence of numbers that you inputted. This is only for debugging
      Serial.println(userarr[i]-48);
    }
    compare();    //code to compare the two sequences of numbers
    counter++;    //END
  }
}
