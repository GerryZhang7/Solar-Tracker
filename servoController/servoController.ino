#include <Servo.h>

//Create a class called servo in order to control the motor through built-in methods
Servo servo;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  servo.write(90);
  Serial.begin(9600);
}

void loop() {
   // put your main code here, to run repeatedly:
   // This line will read the input voltage of the photodiode. 
   // Photodiode 1
  int analogIn = analogRead(A0);

   // This line converts the analog input of the arduino to voltage 
  float voltage = ((5.0 * analogIn)/1023.0);

   // Prints voltage input to terminal. Make sure you open the serial by going to Tools > Serial Monitor
  Serial.println(voltage);

   // Now we repeat this process 3 more times in order to find voltages across all 3 photodiodes. 
   // Photodiode 2
  int analogIn1 = analogRead(A1);

  float voltage1 = ((5.0 * analogIn1)/1023.0);

  Serial.println(voltage1);

   // Photodiode 3
  int analogIn2 = analogRead(A2);

  float voltage2 = ((5.0 * analogIn2)/1023.0);

  Serial.println(voltage2);

   //Photodiode 4
  int analogIn3 = analogRead(A3);

  float voltage3 = ((5.0 * analogIn3)/1023.0);

  Serial.println(voltage3);

  
   // Compare photodiode voltages to control movement of servo. 
  if (voltage > voltage1 && voltage > voltage2 && voltage > voltage3) {
    servo.write(pos);
    ++pos;
    delay(5);
  }
    if (voltage1 > voltage && voltage1 > voltage2 && voltage1 > voltage3) {
    servo.write(pos);
    ++pos;
    delay(5);
  }
    if (voltage2 > voltage && voltage2 > voltage1 && voltage2 > voltage3) {
    servo.write(pos);
    --pos;
    delay(5);
  }
    if (voltage3 > voltage && voltage3 > voltage1 && voltage3 > voltage2) {
    servo.write(pos);
    --pos;
    delay(5);
  }
  
  /*
  for (pos = 0; pos <= 180; ++pos) {
    servo.write(pos);
    delay(5); // Delay in milliseconds. Not quite too sure about the actual speed we want. Previously set to 20 
  }
  for (pos = 180; pos >= 0; --pos){
    servo.write(pos);
    delay(5);
  }*/
} 
