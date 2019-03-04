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

  return voltage1;
}

void loop() {
  // put your main code here, to run repeatedly:
    int voltage;
    int voltage1;
    voltage = readVoltage();
    voltage1 = readVoltage1();
  while (voltage > voltage1) {
    voltage = readVoltage();
    voltage1 = readVoltage1();
    servo.write(pos);
    ++pos;
    delay(5);
  }
  while (voltage1 > voltage) {
    voltage = readVoltage();
    voltage1 = readVoltage1();
    servo.write(pos);
    --pos;
    delay(5);
  }
}
