/*   
          0   1
      -------------         <---- Example of what braille looks like.
      0|  1   0             <---- This is the letter A
       | ----------         
      1|  0   0
       | ----------
      2|  0   0
*/

// The PWM location values as defined by the grid above
#define G00 3    
#define G01 5   
#define G10 6    
#define G11 9    
#define G20 10  
#define G21 11  

// You can change this for the number of characters in the message
#define MSG_SIZE 1000

// The uppercase letters min and max 
#define A 65
#define Z 90

// The total number of PWM slots we have
#define MAXPWM 6

// A few definitions for on, off and second
#define OFF 0
#define ON 1
#define SEC 1000

// This is for analog write. Change this for the pulse amount
#define PULSE 80

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(G00, OUTPUT);  
  pinMode(G01, OUTPUT);
  pinMode(G10, OUTPUT);
  pinMode(G11, OUTPUT);
  pinMode(G20, OUTPUT);
  pinMode(G21, OUTPUT);
}

// Interpret the message recieved, boolean array representing braille alphabet
void sendPWM(bool PWMloc[]) {
  
  // Array that holds the values of all the PWM values
  int PWMs[MAXPWM] = {G00,G01,
                      G10,G11,
                      G20,G21};
  int i;
  for(i = 0; i < MAXPWM; i++) 
    if(PWMloc[i] == ON)             // If the index has a value of 1 then we match this to the grid that represents the motor
      analogWrite(PWMs[i], PULSE);  // Vibrate
    
  // The pause in between each letter
  delay(SEC);
  
  // Now turn all of the motors off
  for(i = 0; i < MAXPWM; i++) 
    if(PWMloc[i] == ON)             // If the motor is on we need to turn it off for the next letter
      analogWrite(PWMs[i], OFF);    // Turn the motor off
}

// Find out what character we have
void interpretChar(char c) {
  
  // If this isnt a letter in the alphabet a-z quit out
  if(!isalpha(c)) 
    return;
  
  // Essentially this converts an upper case character to a lower case
  if(c >= A && c <= Z) 
    c += 32;             // Increment by this much to reach lower case letters in ascii table
  
  // Find the letter we have
  if(c == 'a') {
    bool PWMloc[MAXPWM] = {1,0,    // This is the format of the Braelle grid
                           0,0,    // A 1 means turn on the motor associated with this position
                           0,0};   // A 0 means do nothing
    sendPWM(PWMloc);
  } 
  
  else if(c == 'b') {
    bool PWMloc[MAXPWM] = {1,0,
                           1,0,
                           0,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'c') {
    bool PWMloc[MAXPWM] = {1,1,
                           0,0,
                           0,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'd') {
    bool PWMloc[MAXPWM] = {1,1,
                           0,1,
                           0,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'e') {
    bool PWMloc[MAXPWM] = {1,0,
                           0,1,
                           0,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'f') {
    bool PWMloc[MAXPWM] = {1,1,
                           1,0,
                           0,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'g') {
    bool PWMloc[MAXPWM] = {1,1,
                           1,1,
                           0,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'h') {
    bool PWMloc[MAXPWM] = {1,0,
                           1,1,
                           0,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'i') {
    bool PWMloc[MAXPWM] = {0,1,
                           1,0,
                           0,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'j') {
    bool PWMloc[MAXPWM] = {0,1,
                           1,1,
                           0,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'k') {
    bool PWMloc[MAXPWM] = {1,0,
                           0,0,
                           1,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'l') {
    bool PWMloc[MAXPWM] = {1,0,
                           1,0,
                           1,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'm') {
    bool PWMloc[MAXPWM] = {1,1,
                           0,0,
                           1,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'n') {
    bool PWMloc[MAXPWM] = {1,1,
                           0,1,
                           1,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'o') {
    bool PWMloc[MAXPWM] = {1,0,
                           0,1,
                           1,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'p') {
    bool PWMloc[MAXPWM] = {1,1,
                           1,0,
                           1,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'q') {
    bool PWMloc[MAXPWM] = {1,1,
                           1,1,
                           1,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'r') {
    bool PWMloc[MAXPWM] = {1,0,
                           1,1,
                           1,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 's') {
    bool PWMloc[MAXPWM] = {0,1,
                           1,0,
                           1,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 't') {
    bool PWMloc[MAXPWM] = {0,1,
                           1,1,
                           1,0};
    sendPWM(PWMloc);
  }
  
  else if(c == 'u') {
    bool PWMloc[MAXPWM] = {1,0,
                           0,0,
                           1,1};
    sendPWM(PWMloc);
  }
  
  else if(c == 'v') {
    bool PWMloc[MAXPWM] = {1,0,
                           1,0,
                           1,1};
    sendPWM(PWMloc);
  }
  
  else if(c == 'w') {
    bool PWMloc[MAXPWM] = {0,1,
                           1,1,
                           0,1};
    sendPWM(PWMloc);
  }
  
  else if(c == 'x') {
    bool PWMloc[MAXPWM] = {1,1,
                           0,0,
                           1,1};
    sendPWM(PWMloc);
  }
  
  else if(c == 'y') {
    bool PWMloc[MAXPWM] = {1,1,
                           0,1,
                           1,1};
    sendPWM(PWMloc);
  }
  
  else if(c == 'z') {
    bool PWMloc[MAXPWM] = {1,0,
                           0,1,
                           1,1};
    sendPWM(PWMloc);
  }
}

// the loop routine runs over and over again forever:
void loop() {

  // As of right now this will only interpret characters. Any punctuation will be ignored
  // If you want to change how big the message is you need to change message size at the top
  char message[MSG_SIZE] = "";
  
  int length = Serial.available();
  Serial.readBytes(message, length);
  
  int i;
  for(i = 0; i < message[i] != NULL; i++) 
    interpretChar(message[i]);            // Reads one character at a time
    
}
