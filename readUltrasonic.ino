// global variables for distance and duration
long duration = 0.0;
int distance = 0;

void readUltrasonic() {
  // clear the trigger pin
  digitalWrite(US_TRIG, LOW);
  delayMicroseconds(2);

  // set the trigger pin to high for 10 microseconds
  digitalWrite(US_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIG, LOW);

  // read the echo pin, returns the sound wave travel time in microseconds
  duration = pulseIn(US_ECHO, HIGH);

  // calculate distance
  distance = duration * 0.034 / 2;

  // print the distance
  Serial.println("Distance: " + distance);
}