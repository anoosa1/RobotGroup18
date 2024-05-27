void readInfrared() {
  // read analog values from infra red sensors
  int IRvalue1 = digitalRead(IR_1);
  int IRvalue2 = digitalRead(IR_2);
  int IRvalue3 = digitalRead(IR_3);
  int IRvalue4 = digitalRead(IR_4);

  // print the read values to the serial monitor
  Serial.println("IR_1:" + IRvalue1);
  Serial.println("IR_2:" + IRvalue2);
  Serial.println("IR_3:" + IRvalue3);
  Serial.println("IR_4:" + IRvalue4);
}