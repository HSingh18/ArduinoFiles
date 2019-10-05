#define sizeofarr 10    //Max size of the array
char n1 = 0;    //The character that the user inputted
int arr[sizeofarr];   //Array in which the numbers are stored
int i = 0;    //Variable to increment thru the array
int j = 0;    //Variable to check which digit is stored in the array
const int ledpin = 13;    //pin # of the LED

void sleep(){   //Sleep function with a delay of 4 seconds
  delay(4000);
}

void dot(){   //Dot Function which keeps LED on for 200 ms and then turns LED off and wait 1 second
  digitalWrite(ledpin, HIGH);
  delay(200);
  digitalWrite(ledpin, LOW);
  delay(1000);
}

void dash(){    //Dash Function which keeps LED on for 600 ms and then turns LED off and waits 1 second
  digitalWrite(ledpin, HIGH);
  delay(600);
  digitalWrite(ledpin, LOW);
  delay(1000);
}
void setup() {
  //setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter A String of Numbers : ");
}

void loop() {
  //main code here, to run repeatedly:
   if (Serial.available()){
    n1 = Serial.read();   //Read the input from the user
    arr[i] = n1;    //Put the input from the user into the array 
    Serial.print("Array[");   //print statments
    Serial.print(i);   //print statments
    Serial.print("] = ");   //print statments
    Serial.println(arr[i]-48);   //print statments
    i++;    //Increment i so the next number is stored into the next element of the array
    if(i == sizeofarr){   //If the number that the user entered is larger than the array, then Terminate
      Serial.println("Your Number is larger than the size of the array. END");
      while(1);   //Infinite Loop
      }
   }
   if(arr[j] == '1'){   //Check if the digit stored in the array is the character 1
    One();
    j++;
   }
   if(arr[j] == '2'){   //Check if the digit stored in the array is the character 2
    Two();
    j++;
   }
   if(arr[j] == '3'){   //Check if the digit stored in the array is the character 3
    Three();
    j++;
   }
   if(arr[j] == '4'){   //Check if the digit stored in the array is the character 4
    Four();
    j++;
   }
   if(arr[j] == '5'){   //Check if the digit stored in the array is the character 5
    Five();
    j++;
   }
   if(arr[j] == '6'){   //Check if the digit stored in the array is the character 6
    Six();
    j++;
   }
   if(arr[j] == '7'){   //Check if the digit stored in the array is the character 7
    Seven();
    j++;
   }
   if(arr[j] == '8'){   //Check if the digit stored in the array is the character 8
    Eight();
    j++;
   }
   if(arr[j] == '9'){   //Check if the digit stored in the array is the character 9
    Nine();
    j++;
   }
   if(arr[j] == '0'){   //Check if the digit stored in the array is the character 0
    Zero();
    j++;
   }
}

void One(){   //Morse Code for the number 1
  dot();dash();dash();dash();dash();
  sleep();
}

void Two(){   //Morse Code for the number 2
  dot();dot();dash();dash();dash();
  sleep();
}

void Three(){   //Morse Code for the number 3
  dot();dot();dot();dash();dash();
  sleep();
}

void Four(){   //Morse Code for the number 4
  dot();dot();dot();dot();dash();
  sleep();
}

void Five(){   //Morse Code for the number 5
  dot();dot();dot();dot();dot();
  sleep();
}

void Six(){   //Morse Code for the number 6
  dash();dot();dot();dot();dot();
  sleep();
}

void Seven(){   //Morse Code for the number 7
  dash();dash();dot();dot();dot();
  sleep();
}

void Eight(){   //Morse Code for the number 8
  dash();dash();dash();dot();dot();
  sleep();
}

void Nine(){   //Morse Code for the number 9
  dash();dash();dash();dash();dot();
  sleep();
}

void Zero(){   //Morse Code for the number 0
  dash();dash();dash();dash();dash();
  sleep();
}
