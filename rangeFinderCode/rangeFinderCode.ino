#include <EYW.h>

// this names the RangeFinder as proximity
EYW::RangeFinder proximity;
// declare an integer var named distance and set to zero
// do before setup() becuase it will be used throughout the program
// this is a global var in C/C++
int distance = 0;



void setup() {
  // this is the setup code which will run once
  Serial.begin(9600);
  // this calibrates the sensor with an object 10cm away
  // it will then sound an alarm when it has been calibrated
  proximity.begin();
  proximity.alarm();
  proximity.calibrate(10);
}

void loop() {
  // this is the code that will run over and over again
  // here it will take a distance measurement, set it equal to distance var
  // then it will print the distance
  distance = proximity.getDistance();
  Serial.print ("Current Distance: ");
  Serial.println(distance);

  if (distance < 10)
  {
    proximity.alarm(2,2000,100);
  }
}
