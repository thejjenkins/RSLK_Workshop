#include "Energia.h"
#include "Romi_Motor_Power.h"
#include "RSLK_MAX_Pins.h"

Romi_Motor_Power left_motor;
Romi_Motor_Power right_motor;

unsigned long myTime;

void setup() {
  Serial.begin(115200);
  left_motor.begin(31, 29, 40);
  right_motor.begin(11, 30, 39);

}
void right_turn() {
  myTime = millis();
  left_motor.enableMotor();
  right_motor.enableMotor();
  while (millis() <= myTime + 1400){
  left_motor.directionForward();
  right_motor.directionBackward();
  left_motor.setSpeed(10);
  right_motor.setSpeed(10);
  }
  left_motor.disableMotor();
  right_motor.disableMotor();
}
void left_turn() {
  myTime = millis();
  left_motor.enableMotor();
  right_motor.enableMotor();
  while (millis() <= myTime + 1400){
  left_motor.directionBackward();
  right_motor.directionForward();
  left_motor.setSpeed(10);
  right_motor.setSpeed(10);
  }
  left_motor.disableMotor();
  right_motor.disableMotor();
}
void drive_straight() {
  myTime = millis();
  left_motor.enableMotor();
  right_motor.enableMotor();
  while (millis() <= myTime + 1400){
  left_motor.directionForward();
  right_motor.directionForward();
  left_motor.setSpeed(10);
  right_motor.setSpeed(10);
  }
  left_motor.disableMotor();
  right_motor.disableMotor();
}
void loop() {
  //s, l, s, r, s, r, s, r, s, r, s, l, s, l, s, l
  drive_straight();
  delay(500);
  left_turn();
  delay(500);

  drive_straight();
  delay(500);
  right_turn();
  delay(500);
  drive_straight();
  delay(500);
  right_turn();
  delay(500);
  drive_straight();
  delay(500);
  right_turn();
  delay(500);
  drive_straight();
  delay(500);
  right_turn();
  delay(500);

  drive_straight();
  delay(500);
  left_turn();
  delay(500);
  drive_straight();
  delay(500);
  left_turn();
  delay(500);
  drive_straight();
  delay(500);
  left_turn();
  delay(500);
}
