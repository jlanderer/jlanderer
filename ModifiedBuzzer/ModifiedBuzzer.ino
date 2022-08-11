const int buzzerPin = 10;
void setup() {
 pinMode(buzzerPin, OUTPUT);

}

void loop() {
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
  delay(100);
}
