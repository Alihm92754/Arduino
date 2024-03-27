const int pot_pin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(pot_pin, INPUT);
}

void loop() {
  // read the input on analog pin 0
  int sensorValue = analogRead(pot_pin);
  // convert the analog reading 
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read
  Serial.println(voltage);
  
}  