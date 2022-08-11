
int analogPower = A0;
int analogResistor = A3;
int analogGround = A5;
int high;
int mid;
int low;
double voltsHigh;
double voltsMid;
double voltsLow;
void setup() {
  Serial.begin(9600);
}

void loop() {
  high = analogRead(analogPower);
  delay(200);
  mid = analogRead(analogResistor);
  delay(200);
  low = analogRead(analogGround);
  delay(200);
  voltsHigh = 5.0 * high / 1023.0;
  voltsMid = 5.0 * mid / 1023.0;
  voltsLow = 5.0 * low / 1023.0;
  Serial.println("***************************");
  Serial.println("High         Middle       Low");
  Serial.print(voltsHigh);
  Serial.print("         ");
  Serial.print(voltsMid);
  Serial.print("         ");
  Serial.println(voltsLow);
}
