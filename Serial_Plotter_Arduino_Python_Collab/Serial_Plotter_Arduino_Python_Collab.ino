void setup() {
Serial.begin(9600);
pinMode(4, OUTPUT); // Double check ports & baud rate please!!!!!!
}

void loop() {
digitalWrite(4, HIGH);
int volts = analogRead(4);
Serial.println(volts);
delay(200);
}
/*
int x = 1; int y = 2; int z = 3;
int Delay = 1000; //ms
void setup(){
  Serial.begin(9600);
  }
  void loop(){
    x = x + 2;
    y = y + 5;
    z = z + 4;
    Serial.print(x);
    Serial.print(",");
    Serial.print(y);
    Serial.print(",");
    Serial.println(z);
    delay(Delay);
    }*/
