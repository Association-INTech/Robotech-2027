#include <Arduino.h>

#include <AccelStepper.h>

// Define stepper pins
#define STEP_PIN 3      // Step pin
#define DIR_PIN 2       // Direction pin

// Microstepping control pins
#define M0_PIN 6
#define M1_PIN 5
#define M2_PIN 4

/*
// rail pins
#define STEP_RAIL 9
#define DIR_RAIL 8

#define M0_RAIL 13
#define M1_RAIL 12
#define M2_RAIL 11*/

// Steps per revolution for the motor
const float stepsPerRevolution = 200;
// Microstepping multiplier (1, 2, 4, 8, 16, or 32)
int microstepSetting = 1;

// AccelStepper instance in driver mode
AccelStepper elevator(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);
//AccelStepper rail(AccelStepper::DRIVER, STEP_RAIL, DIR_RAIL);


// Function to calculate steps based on desired rotations
float convert_rotational_position_to_steps(float rotations) {
  return rotations * stepsPerRevolution * microstepSetting;
}

void setup() {

  // Set microstepping pins as outputs
  pinMode(M0_PIN, OUTPUT);
  pinMode(M1_PIN, OUTPUT);
  pinMode(M2_PIN, OUTPUT);

  // Set microstepping mode (adjust as needed: HIGH or LOW)
  digitalWrite(M0_PIN, LOW);  // Adjust microstepping settings as needed
  digitalWrite(M1_PIN, LOW);
  digitalWrite(M2_PIN, LOW);

  // Set microstepping pins as outputs
  /*pinMode(M0_RAIL, OUTPUT);
  pinMode(M1_RAIL, OUTPUT);
  pinMode(M2_RAIL, OUTPUT);*/

  // Set microstepping mode (adjust as needed: HIGH or LOW)
  /*digitalWrite(M0_RAIL, LOW);  // Adjust microstepping settings as needed
  digitalWrite(M1_RAIL, LOW);
  digitalWrite(M2_RAIL, LOW);*/

  // Set the max speed and acceleration
  float MaxRPM = 300; // Set max speed in rpm (revolutions per minute)
  float Max_Speed_StepsPerSec = microstepSetting * stepsPerRevolution * MaxRPM / 60; // Specify max speed in steps/sec (converted from RPM)
  elevator.setMaxSpeed(Max_Speed_StepsPerSec);
  //rail.setMaxSpeed(Max_Speed_StepsPerSec);
  
  float AccelRPMperSec = 3000; // Set acceleration in rpm/sec
  float Accel_StepsPerSec2 = microstepSetting * stepsPerRevolution * AccelRPMperSec / 60;
  elevator.setAcceleration(Accel_StepsPerSec2);
  //rail.setAcceleration(Accel_StepsPerSec2);
  
  // Move to position 0 as the starting point
  elevator.setCurrentPosition(0);
  //rail.setCurrentPosition(0);
}

void loop() {
  elevator.moveTo(convert_rotational_position_to_steps(2));
  while (elevator.distanceToGo() != 0) {
    elevator.run();
  }
  delay(500);


  /*rail.moveTo(convert_rotational_position_to_steps(1));
  while (rail.distanceToGo() != 0) {
    rail.run();
  }
  delay(500);*/


  elevator.moveTo(convert_rotational_position_to_steps(-2));
  while (elevator.distanceToGo() != 0) {
    elevator.run();
  }

  /*rail.moveTo(convert_rotational_position_to_steps(-1));
  while (rail.distanceToGo() != 0) {
    rail.run();
  }*/

  delay(3000);

}