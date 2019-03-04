#include <Servo.h>

//Create a class called servo in order to control the motor through built-in methods
Servo servo;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  servo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (pos = 0; pos <= 180; ++pos) {
    servo.write(pos);
    delay(5); //Test delay later. Delay in milliseconds. Not quite too sure about the actual speed we want. Previously set to 20 
  }
  for (pos = 180; pos >= 0; --pos){
    servo.write(pos);
    delay(5);
  }
} 
