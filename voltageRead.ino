void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // This line will read the input voltage of the photodiode. 
  int analogIn = analogRead(A0);

  // This line converts the analog input of the arduino to voltage 
  float voltage = ((5.0 * analogIn)/1023.0);

  // Prints voltage input to terminal. Make sure you open the serial by going to Tools > Serial Monitor
  Serial.println(voltage);
  delay(500);
}
