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

void loop() {
  // put your main code here, to run repeatedly:
  
  // get the current run time in milliseconds
  unsigned long currentMillis millis();

  // check the states of the IR sensors every 500ms
  if (currentMillis — irSensorMillis >= 500) {
    irSensorMillis = currentMillis;
    readInfrared();
  }
}
