/*
These are two different ways of doing the same code. From lines 6-66 you can use the pin names defined in the RSLK_MAX_Pins header file. 
From lines 68-126 you can use the pin numbers directly without naming them.
*/

#include "Energia.h" // enables communication between Arduino IDE and the MSP432 board
#include "Bump_Switch.h" // defines the Energia pin numbers of the bump switches and defines their functions
#include "RSLK_MAX_Pins.h" // defines the Energia pin numbers of all pins but not the functions of each pin
#include "Romi_Motor_Power.h" // defines functions of motors using the motor pins from RSLK_MAX_Pins.h

Romi_Motor_Power left_motor; // create an object left_motor of class Romi_Motor_Power
Romi_Motor_Power right_motor; // create an object right_motor of class Romi_Motor_Power

#define LEFT_BTN  73
#define RIGHT_BTN 74

void setup() {
  Serial.begin(115200);
  delay(500); // 500 milliseconds
  left_motor.begin(MOTOR_L_SLP_PIN, MOTOR_L_DIR_PIN, MOTOR_L_PWM_PIN); // 31, 29, 40
  right_motor.begin(MOTOR_R_SLP_PIN, MOTOR_R_DIR_PIN, MOTOR_R_PWM_PIN); // 11, 30, 39
  pinMode(BP_SW_PIN_0,INPUT_PULLUP); // 24
	pinMode(BP_SW_PIN_1,INPUT_PULLUP); // 25
	pinMode(BP_SW_PIN_2,INPUT_PULLUP); // 6
	pinMode(BP_SW_PIN_3,INPUT_PULLUP); // 27
	pinMode(BP_SW_PIN_4,INPUT_PULLUP); // 8
	pinMode(BP_SW_PIN_5,INPUT_PULLUP); // 28
  pinMode(LEFT_BTN, INPUT_PULLUP);   // 73
  pinMode(RIGHT_BTN, INPUT_PULLUP);  // 74
}

void loop() {
  left_motor.enableMotor();
  right_motor.enableMotor();
  
  while(digitalRead(BP_SW_PIN_0) == 0){
    left_motor.directionForward();
    left_motor.setSpeed(20);
  }
  while(digitalRead(BP_SW_PIN_1) == 0){
    left_motor.directionBackward();
    left_motor.setSpeed(20);
  }
  while(digitalRead(BP_SW_PIN_2) == 0){
    left_motor.directionForward();
    right_motor.directionBackward();
    left_motor.setSpeed(20);
    right_motor.setSpeed(20);
  }
  while(digitalRead(BP_SW_PIN_3) == 0){
    right_motor.directionForward();
    left_motor.directionBackward();
    right_motor.setSpeed(20);
    left_motor.setSpeed(20);
  }
  while(digitalRead(BP_SW_PIN_4) == 0){
    right_motor.directionBackward();
    right_motor.setSpeed(20);
  }
  while(digitalRead(BP_SW_PIN_5) == 0){
    right_motor.directionForward();
    right_motor.setSpeed(20);
  }
  left_motor.disableMotor();
  right_motor.disableMotor();
}

// #include "Energia.h" // enables communication between Arduino IDE and the MSP432 board
// #include "Bump_Switch.h" // defines the Energia pin numbers of the bump switches and defines their functions
// #include "RSLK_MAX_Pins.h" // defines the Energia pin numbers of all pins but not the functions of each pin
// #include "Romi_Motor_Power.h" // defines functions of motors using the motor pins from RSLK_MAX_Pins.h

// Romi_Motor_Power left_motor; // create an object left_motor of class Romi_Motor_Power
// Romi_Motor_Power right_motor; // create an object right_motor of class Romi_Motor_Power

// void setup() {
//   Serial.begin(115200);
//   delay(500); // 500 milliseconds
//   left_motor.begin(31, 29, 40); // 31, 29, 40
//   right_motor.begin(11, 30, 39); // 11, 30, 39
//   pinMode(24,INPUT_PULLUP); // 24, active low
// 	pinMode(25,INPUT_PULLUP); // 25
// 	pinMode(6,INPUT_PULLUP); // 6
// 	pinMode(27,INPUT_PULLUP); // 27
// 	pinMode(8,INPUT_PULLUP); // 8
// 	pinMode(28,INPUT_PULLUP); // 28
//   pinMode(73, INPUT_PULLUP);   // 73
//   pinMode(74, INPUT_PULLUP);  // 74
  
// }

// void loop() {
//   left_motor.enableMotor();
//   right_motor.enableMotor();
  
//   while(digitalRead(24) == 0){
//     left_motor.directionForward();
//     left_motor.setSpeed(20);
//   }
//   while(digitalRead(25) == 0){
//     left_motor.directionBackward();
//     left_motor.setSpeed(20);
//   }
//   while(digitalRead(6) == 0){
//     left_motor.directionForward();
//     right_motor.directionBackward();
//     left_motor.setSpeed(20);
//     right_motor.setSpeed(20);
//   }
//   while(digitalRead(27) == 0){
//     right_motor.directionForward();
//     left_motor.directionBackward();
//     right_motor.setSpeed(20);
//     left_motor.setSpeed(20);
//   }
//   while(digitalRead(8) == 0){
//     right_motor.directionBackward();
//     right_motor.setSpeed(20);
//   }
//   while(digitalRead(28) == 0){
//     right_motor.directionForward();
//     right_motor.setSpeed(20);
//   }
//   left_motor.disableMotor();
//   right_motor.disableMotor();
// }