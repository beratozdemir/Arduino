#include "SevenSegmentTM1637.h"
#include "SevenSegmentExtended.h"

int pos = 9;    // variable to store the servo position 

const byte PIN_CLK = 12;   // define CLK pin (any digital pin)
const byte PIN_DIO = 11;   // define DIO pin (any digital pin)
SevenSegmentExtended      display(PIN_CLK, PIN_DIO);

const unsigned int clockSpeed = 150;    // speed up clock for demo

void setup() {
  Serial.begin(9600);         // initializes the Serial connection @ 9600 baud
  display.begin();            // initializes the display
  display.setBacklight(100);  // set the brightness to 100 %
  delay(1000);                // wait 1000 ms 
  pinMode(7, OUTPUT);
  }

void loop() {
  byte hours    = 2;                           // initialize hours
  byte minutes  = 59;                           // initialize minutes
  
  for ( ; hours < 3; hours-- ) {                // count hours   up to 24
    for (; minutes < 60; minutes--) {          // count minutes up to 59
      display.printTime(hours, minutes, true);  // display time
      delay(60000 / clockSpeed);  

if (hours < 3) 
digitalWrite(7, HIGH);
delay (370);
digitalWrite(7, LOW);
  
if (hours < 2)
digitalWrite(2, HIGH);
delay (1000);
digitalWrite(2, LOW);

if (hours < 1)
digitalWrite(2, HIGH);
delay (200); 
digitalWrite(2, LOW);
      
if (hours < 0){      // bail out on sensor detect
hours = 0;
minutes = 0;
break;
delay(50);
              }
delay(100);             // clock delay ms
    }
    minutes = 59;       // reset minutes
  }
}

