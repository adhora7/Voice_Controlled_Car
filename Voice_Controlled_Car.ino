#include <AFMotor.h>  // Motor shield library

#define MAX_SPEED 160           // Maximum motor speed
#define MAX_SPEED_OFFSET 40     // Offset for motor speed balance

// Motor shield pins (L293D) configuration
AF_DCMotor leftMotor1(1, MOTOR12_1KHZ);
AF_DCMotor leftMotor2(2, MOTOR12_1KHZ);
AF_DCMotor rightMotor1(3, MOTOR34_1KHZ);
AF_DCMotor rightMotor2(4, MOTOR34_1KHZ);

String motorSet = "";   // To track current motor direction
char state;             // To store the received Bluetooth command
int speedSet = 0;       // Speed variable for gradual motor speed increase

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  // Check if Bluetooth has sent any command
  while (Serial.available() > 0) {
    state = Serial.read();  // Read the command from Bluetooth
    Serial.println(state);   // Optionally, print the received command for debugging
  }

  // -------- MOVE FORWARD --------
  if (state == 'f') {
    motorSet = "FORWARD";
    moveForward();
  }
  
  // -------- MOVE BACKWARD --------
  else if (state == 'b') {
    motorSet = "BACKWARD";
    moveBackward();
  }
  
  // -------- TURN RIGHT --------
  else if (state == 'r') {
    motorSet = "RIGHT";
    turnRight();
  }
  
  // -------- TURN LEFT --------
  else if (state == 'l') {  // Changed '1' to 'l' for clarity
    motorSet = "LEFT";
    turnLeft();
  }
  
  // -------- STOP --------
  else if (state == 's') {
    motorSet = "STOP";
    stopMotors();
  }
}

// Function to move the rover forward
void moveForward() {
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);

  // Gradually increase speed for smooth motion
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
    leftMotor1.setSpeed(speedSet);
    leftMotor2.setSpeed(speedSet);
    rightMotor1.setSpeed(speedSet);
    rightMotor2.setSpeed(speedSet);
    delay(5);  // Delay to allow motors to ramp up
  }
}

// Function to move the rover backward
void moveBackward() {
  leftMotor1.run(BACKWARD);
  leftMotor2.run(BACKWARD);
  rightMotor1.run(BACKWARD);
  rightMotor2.run(BACKWARD);

  // Gradually increase speed for smooth motion
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
    leftMotor1.setSpeed(speedSet);
    leftMotor2.setSpeed(speedSet);
    rightMotor1.setSpeed(speedSet);
    rightMotor2.setSpeed(speedSet);
    delay(5);  // Delay to allow motors to ramp up
  }
}

// Function to turn the rover right
void turnRight() {
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(BACKWARD);
  rightMotor2.run(BACKWARD);

  // Increase speed of right motors for a sharper turn
  rightMotor1.setSpeed(speedSet + MAX_SPEED_OFFSET);
  rightMotor2.setSpeed(speedSet + MAX_SPEED_OFFSET);
  delay(1500);  // Turn for 1.5 seconds

  // Move forward after turning
  motorSet = "FORWARD";
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);
}

// Function to turn the rover left
void turnLeft() {
  leftMotor1.run(BACKWARD);
  leftMotor2.run(BACKWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);

  // Increase speed of left motors for a sharper turn
  leftMotor1.setSpeed(speedSet + MAX_SPEED_OFFSET);
  leftMotor2.setSpeed(speedSet + MAX_SPEED_OFFSET);
  delay(1500);  // Turn for 1.5 seconds

  // Move forward after turning
  motorSet = "FORWARD";
  leftMotor1.run(FORWARD);
  leftMotor2.run(FORWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);
}

// Function to stop all motors
void stopMotors() {
  leftMotor1.run(RELEASE);
  leftMotor2.run(RELEASE);
  rightMotor1.run(RELEASE);
  rightMotor2.run(RELEASE);
}
