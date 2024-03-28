const int tmpPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float tmp_reading = analogRead(tmpPin);
  float voltage = tmp_reading/1024.0 * 5000;
  float celsius = voltage / 10;
  float fahrenheit = (celsius * 9)/5 + 32;
  
  Serial.print(celsius);
  Serial.print(" C   ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  delay(1000);
}