int x = 0;

void setup() {
  Serial.begin(9600);
 pinMode(13, OUTPUT);
}

void loop() {
  delay(3500);
    if Serial.Read("A"){
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(13, HIGH);
    delay(1500);
    digitalWrite(13, LOW);
    }
    else if Serial.Read("B"){
    
    }
    else if Serial.Read("C"){
    
    }
    else if Serial.Read("D"){
    
    }
    else if Serial.Read("E"){
    
    }
    else if Serial.Read("F"){
    
    }
    else if Serial.Read("G"){
    
    }
    else if Serial.Read("H"){
    
    }
    else if Serial.Read("I"){
    
    }
    else if Serial.Read("J"){
    
    }
    else if Serial.Read("K"){
    
    }
    else if Serial.Read("L"){
    
    }
    else if Serial.Read("M"){
    
    }
    else if Serial.Read("N"){
    
    }
    else if Serial.Read("O"){
    
    }
    else if Serial.Read("P"){
    
    }
    else if Serial.Read("Q"){
    
    }
    else if Serial.Read("R"){
    
    }
    else if Serial.Read("S"){
    
    }
    else if Serial.Read("T"){
    
    }
    else if Serial.Read("U"){
    
    }
    else if Serial.Read("V"){
    
    }
    else if Serial.Read("W"){
    
    }
    else if Serial.Read("X"){
    
    }
    else if Serial.Read("Y"){
    
    }
    else if Serial.Read("Z"){
    
    }
    else if Serial.Read(" "){
      delay(3500);
      }
    delay(1500);
}
