#include <Wire.h>
#include <LIDARLite.h>
#include <Servo.h>

LIDARLite myLidarLite; // variable to store Lidar information
Servo myservo;
int pos = 0;    // variable to store the servo position 

void setup()
{
  // Begin and configure LIDAR
  Serial.begin(115200);
  myLidarLite.begin(0, true);
  myLidarLite.configure(0);
  
  myservo.attach(12);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  /*
   * Initial Lidar code
  // Take a measurement with receiver bias correction and print to serial terminal
  Serial.println(myLidarLite.distance());

  // Take 99 measurements without receiver bias correction and print to serial terminal
  for(int i = 0; i < 99; i++)
    {
      Serial.println(myLidarLite.distance(false));
      delay(10);
    }
  */  
    
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);
    Serial.println(myLidarLite.distance());
    delay(50);
  }

  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);
    Serial.println(myLidarLite.distance());
    delay(50);
  }
  
}
