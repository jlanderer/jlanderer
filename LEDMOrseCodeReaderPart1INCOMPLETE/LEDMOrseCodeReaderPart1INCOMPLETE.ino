int threshold;
int photoResistor;
int timeOffStart;
int timeOffEnd;
int timeOnStart;
int timeOnEnd;
int timeBlink;
int timeSpace;
boolean on = false;
void setup() {
  Serial.begin(9600);
  photoResistor = analogRead(A0);
  Serial.println("The ambient light is ");
  Serial.println(photoResistor);
  threshold = photoResistor + 15;
}


void loop() {
  photoResistor = analogRead(A0);
  if (photoResistor > threshold && !on) { // If, the photoresistor reading is
    //lower than the threshold, meaning there is a light on it
    timeOffEnd = millis();
    timeOnStart = millis();
    timeSpace = timeOffEnd - timeOffStart;
    on = true;
    Serial.print("The amount of time off is: ");
    Serial.println(timeSpace);
  }


  else if (photoResistor < threshold && on) { // if the photoresistor reading is
    //greater than the threshold
    timeOnEnd = millis();
    timeOffStart = millis();
    timeBlink = timeOnEnd - timeOnStart;
    timeOffStart = millis();
    on = false;
    Serial.print("The amount of time on is: ");
    Serial.println(timeBlink);
  }
}
