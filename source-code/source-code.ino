#include <Servo.h>
#define MAX_RANGE 5 // define the range you want until the machine opens the door (in CM)

Servo servo;
int pinServo = 9; //adjust to suit your schematics
int pinTrig = 13; //adjust to suit your schematics
int pinEcho = 12; //adjust to suit your schematics
int range;

void setup() {
  servo.attach(pinServo);
}
void loop() {
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10); // adjust pulse to suit the sensor (HC-SR04's pulse reaction is 10 us) 
  digitalWrite(pinTrig, LOW);
  int traveltime = pulseIn (pinEcho, HIGH);
  range =  traveltime * 340 / pow(10,6) / 2; // s = v.t/2 for ultrasonics, v = 340ms^-1, 1m = 100 cm, 1s = 10^6 us
  if (range < MAX_RANGE){
    servo.write(90); // adjust angle to suit your situation
    delay(2000); //wait for 2 sec (2000 ms)
  }
  else servo.write(0); // return to 0 degree if no one is there.
}
