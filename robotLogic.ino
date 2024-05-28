void robotLogic() {

  motorLogic();  // process motor logic based on IR sensor values
}

void motorLogic() {
  int* IRvalues;
  IRvalues = readInfrared();  // This will point to the array of sensor values


  // Apply robot logic based on sensor readings and turning flags
  if (!isTurning && !wallDetected) {
    if (IRValues[1] == 1 && IRValues[2] == 1) {
      motorControl(200, 200); // move the robot forward
      currentState = "Forward";
    } else if (IRvalues[1] == 0 && IRvalues == 1) {
      motorControl(150, 200); // turn left slightly
      currentState = "Left";
    } else if (IRvalues[1] == 1 && IRvalues[2] == 0) {
      motorControl(200, 150); // turn right slightly
      currentState = "Right";
    } else if (IRvalues[0] == 1 && IRvalues[1] == 1 && IRvalues[2] == 1 && IRvalues[3] == 1) {
      // if none of the IR sensors detect a line, continue the last state decided by the center IR sensors
      if (currentState == "Forward") {
        motorControl(200, 200); // move the robot forward
      } else if (currentState == "Left") {
        motorControl(150, 200); // turn left slightly
      } else if (currentState == "Right") {
        motorControl(200, 150); // turn right slightly
      }
    }
  } else if (isTurning && !wallDetected) {
    // handle the turning based on the direction determined

    if (initialForwardMotion) {
      motorControl(200, 200);  // continue moving forward for the initial duration
      currentState = "Bumping Out...";
      delay(initialMotionDuration);
      initialForwardMotion = false;  // end initial forward motion after duration

    } else {


      if (turnDirection == "left") {


        if (currentMillis - turnStartTime >= initialTurnDuration && IRvalues[2] == 1) {
          Serial.println("Detected Center IR Sensor after initial turn duration");
          isTurning = false;   // Stop turning if IR2 detects the line again
          motorControl(0, 0);  // Adjust to move forward or stop
          currentState = "Turning Left - Next Line Detected";
          motorControl(turnSpeed, -turnSpeed);  // Counterbalance
          delay(50);
          motorControl(0, 0);
          delay(50);
          currentState = "Forward";
        } else {
          motorControl(-turnSpeed, turnSpeed);  // Continue turning left
          currentState = "Turning Left - No Line Yet Detected";
        }


      } else if (turnDirection == "right") {


        if (currentMillis - turnStartTime >= initialTurnDuration && IRvalues[1] == 1) {
          Serial.println("Detected Center IR Sensor");
          isTurning = false;  // Stop turning if IR3 detects the line again
          currentState = "Turning Right - Next Line Detected";
          motorControl(-turnSpeed, turnSpeed);  // Counterbalance
          delay(50);
          motorControl(0, 0);
          delay(50);
          currentState = "Forward";


        } else {


          motorControl(turnSpeed, -turnSpeed);  // Continue turning right
          currentState = "Turning Right - No Line Yet Detected";
        }
      }
    }


    // Turn that is triggered by detecting a wall


  } else if (isTurning && wallDetected) {


    if (initialForwardMotion) {
      motorControl(-200, -200);  // Continue moving forward for the initial duration
      currentState = "Stopping...";
      delay(100);
      initialForwardMotion = false;  // End initial forward motion after duration
    } else {
      // Turn left
      if (currentMillis - turnStartTime >= initialTurnDuration && IRvalues[2] == 1) {
        Serial.println("Detected Center IR Sensor after initial turn duration");
        isTurning = false;  // Stop turning if IR2 detects the line again
        currentState = "Turning Left - Next Line Detected";
        motorControl(turnSpeed, -turnSpeed);  // Counterbalance
        delay(50);
        motorControl(0, 0);
        delay(50);
        wallDetected = false;
        currentState = "Forward";
      } else {
        motorControl(-turnSpeed, turnSpeed);  // Continue turning left
        currentState = "Turning Left - No Line Yet Detected";
      }
    }
  }
}