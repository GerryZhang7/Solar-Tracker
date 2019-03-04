#include <Servo.h>

Servo servo;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  servo.write(90);
  Serial.begin(9600);
}

int readVoltage() {
   // This line will read the input voltage of the photodiode. 
  int analogIn = analogRead(A0);

  // This line converts the analog input of the arduino to voltage 
  float voltage = ((5.0 * analogIn)/1023.0);

  // Prints voltage input to terminal. Make sure you open the serial by going to Tools > Serial Monitor
  Serial.println ("Photodiode 1");
  Serial.println (voltage);
  delay(500);

  return voltage;
}

int readVoltage1() {
    // This line will read the input voltage of the photodiode. 
  int analogIn1 = analogRead(A1);

  // This line converts the analog input of the arduino to voltage 
  float voltage1 = ((5.0 * analogIn1)/1023.0);

  // Prints voltage input to terminal. Make sure you open the serial by going to Tools > Serial Monitor
  Serial.println ("Photodiode 2");
  Serial.println(voltage1);
  delay(500);

  return voltage1;
}

void loop() {
  // put your main code here, to run repeatedly:
    int voltage;
    int voltage1;
    voltage = readVoltage();
    voltage1 = readVoltage1();
  for (pos = 0; voltage > voltage1; ++pos) {
    voltage = readVoltage();
    voltage1 = readVoltage1();
    servo.write(pos);
    delay(5);
  }
  for (pos = 180; voltage1 > voltage; --pos) {
    voltage = readVoltage();
    voltage1 = readVoltage1();
    servo.write(pos);
    delay(5);
  }
  /*
  if (voltage > voltage1) {
    servo.write(pos);
    ++pos;
    delay(5);      
  }
  else if (voltage1 > voltage) {
    servo.write(pos);
    --pos;
    delay(5);
  }*/
}
