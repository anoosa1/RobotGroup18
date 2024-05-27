#include <tcs3200.h>

#define COLOR_0 A0
#define COLOR_1 A1
#define COLOR_2 A2
#define COLOR_3 A3
#define COLOR_OUT A4

#define IR_1 4
#define IR_2 7
#define IR_3 8
#define IR_4 12

void setup() {
  // put your setup code here, to run once:

  // setup infrared pins
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);
}

unsigned long irSensorMillis = 0; // timer to track the last report of the IR sensors
unsigned long colorSensorMillis = 0; // timer to track the last report of the color sensors

void loop() {
  // put your main code here, to run repeatedly:
  
  // get the current run time in milliseconds
  unsigned long currentMillis = millis();

  // check the states of the IR sensors every 500ms
  if (currentMillis - irSensorMillis >= 500) {
    irSensorMillis = currentMillis;
    readInfrared();
  }

  // read the color sensor
  if (currentMillis - colorSensorMillis >= 250) {
    colorSensorMillis = currentMillis;
    readColorSensor();
  }
}
