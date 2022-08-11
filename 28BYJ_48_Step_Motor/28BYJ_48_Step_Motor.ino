// This code works on a Step motor

int step_num = 0;
void setup() {
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
}
void loop() {
for (int i = 0; i < 1000; i++){
  Single_Step(0);
  delay(2);
}
for (int j = 0; j < 1000; j++){
  Single_Step(1);
delay(2);
}
}

void Single_Step(boolean dir){
if(dir){
switch (step_num){
   case 0:
     digitalWrite(9,HIGH);
     digitalWrite(10,LOW);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
   break;
   case 1:
     digitalWrite(9,LOW);
     digitalWrite(10,HIGH);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
   break;
   case 2:
     digitalWrite(9,LOW);
     digitalWrite(10,LOW);
     digitalWrite(11,HIGH);
     digitalWrite(12,LOW);
   break;
   case 3:
     digitalWrite(9,LOW);
     digitalWrite(10,LOW);
     digitalWrite(11,LOW);
     digitalWrite(12,HIGH);
   break;
  }
}
else{
  switch (step_num){
   case 3:
     digitalWrite(9,HIGH);
     digitalWrite(10,LOW);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
   break;
   case 2:
     digitalWrite(9,LOW);
     digitalWrite(10,HIGH);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
   break;
   case 1:
     digitalWrite(9,LOW);
     digitalWrite(10,LOW);
     digitalWrite(11,HIGH);
     digitalWrite(12,LOW);
   break;
   case 0:
     digitalWrite(9,LOW);
     digitalWrite(10,LOW);
     digitalWrite(11,LOW);
     digitalWrite(12,HIGH);
   break;
    }
  }
  step_num++;
  if(step_num > 3)
  step_num = 0;
}
