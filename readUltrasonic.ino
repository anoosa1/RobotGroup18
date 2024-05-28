int readUltrasonic() {
  // clear the trigger pin
  digitalWrite(US_TRIG, LOW);
  delayMicroseconds(2);

  // set the trigger pin to high for 10 microseconds
  digitalWrite(US_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIG, LOW);

  // read the echo pin, returns the sound wave travel time in microseconds
  long duration = pulseIn(US_ECHO, HIGH);

  // calculate distance
  int distance = duration * 0.034 / 2;
  currentDistance = distance;

  // print the distance
  Serial.println("Distance: " + distance);
}