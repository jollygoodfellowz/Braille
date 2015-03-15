/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:

#define PWM_3 3
#define PWM_5 5
#define PWM_6 6
#define PWM_9 9
#define PWM_10 10
#define PWM_11 11

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(PWM_3, OUTPUT);  
  pinMode(PWM_5, OUTPUT);
  pinMode(PWM_6, OUTPUT);
  pinMode(PWM_9, OUTPUT);
  pinMode(PWM_10, OUTPUT);
  pinMode(PWM_11, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
