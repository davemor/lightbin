/*
/* Grove - Light Sensor demo v1.0
* 
* signal wire to A0.
* By: http://www.seeedstudio.com
*/
#include <math.h>
const int thresholdvalue=10;         //The threshold for which the LED should turn on. 
 //Resistance of sensor in K

float lastRes = 0;
 
void setup() {
  Serial.begin(9600);                //Start the Serial connection
}
void loop() {
  int sensorValue = analogRead(5);
  Serial.println(sensorValue);
  
  float newRes = convertToRes(sensorValue);

  float delta = newRes - lastRes;
  float abs_delta = abs(delta);
  // if ( abs_delta > 1.0f ) {
    //Serial.println(delta);
  // }
  
  lastRes = newRes;
  delay(500);
}

float convertToRes(int sensorValue) {
  return (float)(1023-sensorValue)*10/sensorValue;
}

