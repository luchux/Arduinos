/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// Morse Constants and Mapping
int S[] = {1, 1, 1};
int O[] = {2, 2, 2};
// the setup routine runs once when you press reset:


int* morse(char letter){
   switch (letter) {
    case 's':
      return S;
    case 'o':
      return O;
    default:
      return O;
  }
}

void setup() {
    Serial.begin(9600);
    Serial.println("Serial conection started, waiting for instructions...");
    pinMode(led, OUTPUT);
    digitalWrite(led,LOW);
}

void display_led(int a){
  switch(a){
    case 0: {
      digitalWrite(led, LOW);
      delay(1200);
    }
    break;
    case 1:{
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(2);
    }
    break;
    case 2:{
      digitalWrite(led, HIGH);
      delay(700);
      digitalWrite(led, LOW);
      delay(2);
    }
    break;
    case 4:{
      digitalWrite(led, LOW);
      delay(1000);
    }
  }  
}

void loop() {
    while (Serial.available() > 0)
    {
        char recieved = Serial.read();
        // Process message when new line character is recieved
        if (recieved != '\n')
        Serial.print("Arduino Received: ");
        Serial.print(recieved);
        {
            int* arr_received = morse(recieved);
            for(int i=0; i<3; i++){
              display_led(arr_received[i]);
              digitalWrite(led, LOW);
              delay(100);
            }
            
        }
        display_led(4);
    }
}
