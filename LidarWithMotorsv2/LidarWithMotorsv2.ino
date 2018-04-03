#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <LIDARLite.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

#define UP 1
#define DOWN 0

LIDARLite myLidarLite;
Adafruit_MotorShield shield1 = Adafruit_MotorShield(0x60);
Adafruit_StepperMotor *ramp1 = shield1.getStepper(200,1);
Servo myservo;

int rampRotations[3] = {100,100,100};
int pos = 0; 
int stepval = 0;

void rampMove(int r, int d, bool full, int amount = 0);

void setup() {
  
  Serial.begin(115200); 
  myLidarLite.begin(0, true); 
  myLidarLite.configure(0);
  shield1.begin();
  ramp1->setSpeed(50);
  myservo.attach(9);
  
}



void loop() {

  // ---------- RUNNING CODE ---------- //
  /*
  if ( stepval <= 100 ) {    
    ramp1->step(10, FORWARD, DOUBLE);
    stepval += 10;    
  }  
  else {    
    delay( 100000 );  
  }
  
  for (pos = 0; pos <= 90; pos += 1) { 

    Serial.println( myLidarLite.distance(false) );
    delay( 10 );

    myservo.write( pos );              
    delay( 50 );
    
  }
  */

  
  // ---------- TESTING CODE ---------- //
  
  /*
  // Stepper TEST
  //ramp1->step(150, FORWARD, DOUBLE);
  delay(100);
  //ramp1->step(150, BACKWARD, DOUBLE);
  delay(100);
 */

  /*
  // LIDAR TEST
  for(int i = 0; i < 99; i++) {
    Serial.println(myLidarLite.distance(false));
    delay(10);
  }
  */

  
  // Servo TEST
  for (pos = 0; pos <= 90; pos += 1) { 
    myservo.write(pos);              
    //delay(50);   
  }
   for (pos = 0; pos >= 90; pos -= 1) { 
    myservo.write(pos);              
    //delay(50);   
  }
  
  
}
