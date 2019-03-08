#include <Servo.h>

Servo servo;

int pos = 90;
float voltage;
float voltage1;

void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  servo.write(90);
  Serial.begin(9600);
}

float readVoltage() {
   // This line will read the input voltage of the photodiode. 
  int analogIn = analogRead(A0);

  // This line converts the analog input of the arduino to voltage 
  float voltage = ((5.0 * analogIn)/1023.0);

  // Prints voltage input to terminal. Make sure you open the serial by going to Tools > Serial Monitor
  Serial.println ("Photodiode 1");
  Serial.println (voltage);

  return voltage;
}

float readVoltage1() {
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
    voltage = readVoltage();
    voltage1 = readVoltage1();

  /*if( (voltage - voltage1) > 0.03 && voltage < 0.1){
    servo.write(90);
  }*/
  
  if( (voltage - voltage1) > 0.65) {
    if(pos < 189){
     ++pos; 
    }
  }
  if ( (voltage1 - voltage) > 0.65) {
    if(pos > 0){
     --pos; 
    }
  }
  servo.write(pos);
  delay(5);
}
