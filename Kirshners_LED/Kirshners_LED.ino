// This program is an unfinished version of my final morse code reader

int threshold;
int photoResistor;
int timeOffStart;
int timeOffEnd;
int timeOnStart;
int timeOnEnd;
int unit = 100;
int timeBlink;
int timeSpace;
int char1 = 0;
int char2 = 0;
int char3 = 0;
int char4 = 0;
int char5 = 0;
int char6 = 0;
boolean on = false;
int turn = 0;
void setup() {
  Serial.begin(9600); // This is the rate at which the arduino communicates with the computer and sends serial comms
  photoResistor = analogRead(A0);
  Serial.print("The ambient light is ");
  Serial.println(photoResistor);
  threshold = photoResistor - 10;
}
void loop() {
  photoResistor = analogRead(A0); // Every time the program loops, it reads the photoresistor value to know whether or not there is a change from on to off or vise versa
  if (photoResistor < threshold && !on) { // If, the photoresistor reading is
    //lower than the threshold, meaning there is a light on it
    timeOffEnd = millis();
    timeOnStart = millis();
    timeSpace = timeOffEnd - timeOffStart;
    on = true;
    Serial.print("The amount of time off is: ");
    Serial.println(timeSpace);
   
    if (timeSpace != timeOffEnd) { // This condition is true every time except for the first time the program runs through this loop
/**
 * 
      if (turn == 2 && timeSpace == unit)                // This if block determines what type of space was just detected
        char2 = 3;                                      // And which space character to assign the detected space to
      else if (turn == 2 && timeSpace == 3 * unit){
        Serial.print(" ");
        turn = 0;
        char1 = 0;
        char2 = 0;
        char3 = 0;
        char4 = 0;
        char5 = 0;
        char6 = 0; 
      }
      else if (turn == 2 && timeSpace == 7 * unit){                                        // The DetermineChar() function should be called whenever a space between letters or words is detected
        Serial.print(" ");                                                                 // Because that is the end a of a letter. The DetermineChar() function resets char values to 0 so 
        turn = 0;
        char1 = 0;
        char2 = 0;
        char3 = 0;
        char4 = 0;
        char5 = 0;
        char6 = 0;  
      }
      else if (turn == 3 && timeSpace == unit)                                             // this loop does not enter the remaining if statements and instead repeats back to the beginning to take in the next letter
        char3 = 3;
      else if (turn == 3 && timeSpace == 3 * unit){
        char3 = 4;
        turn = 0;
        char1 = 0;
        char2 = 0;
        char3 = 0;
        char4 = 0;
        char5 = 0;
        char6 = 0; 
      }
      else if (turn == 3 && timeSpace == 7 * unit){
        Serial.print(" ");
        turn = 0;
        char1 = 0;
        char2 = 0;
        char3 = 0;
        char4 = 0;
        char5 = 0;
        char6 = 0; 
      }
      else if (turn == 4 && timeSpace == unit)
        char4 = 3;
      else if (turn == 4 && timeSpace == 3 * unit){
        char4 = 4;
        turn = 0;
        char1 = 0;
        char2 = 0;
        char3 = 0;
        char4 = 0;
        char5 = 0;
        char6 = 0; 
      }
      else if (turn == 4 && timeSpace == 7 * unit){
        Serial.print(" ");
        turn = 0;
        char1 = 0;
        char2 = 0;
        char3 = 0;
        char4 = 0;
        char5 = 0;
        char6 = 0; 
      }
      else if (turn == 5 && timeSpace == unit)
        char5 = 3;
      else if (turn == 5 && timeSpace == 3 * unit){
        Serial.print(" ");
        turn = 0;
        char1 = 0;
        char2 = 0;
        char3 = 0;
        char4 = 0;
        char5 = 0;
        char6 = 0; 
      }
      else if (turn == 5 && timeSpace == 7 * unit){
        Serial.print(" ");
        turn = 0;
        char1 = 0;
        char2 = 0;
        char3 = 0;
        char4 = 0;
        char5 = 0;
        char6 = 0; 
      }
      else if (turn == 6 && timeSpace == 7 * unit)
        Serial.print(" ");
**/
    Serial.print("The time off is: ");
    Serial.println(timeSpace); // '+' concatenates strings with ints
    Serial.print("and the turn is: " + turn);
  }

  else if (photoResistor >= threshold && on) { // if the photoresistor reading is
    //greater than the threshold
    timeOnEnd = millis();
    timeOffStart = millis();
    timeBlink = timeOnEnd - timeOnStart;
    timeOffStart = millis();
    on = false;
    Serial.print("The amount of time on is: ");
    Serial.println(timeBlink);

/**
    if (turn == 1 && timeBlink == unit)               // This if block determines which chars are dits and which are dahs.
      char1 = 1;                                     
    else if (turn == 1 && timeBlink == 3 * unit)
      char1 = 2;
    else if (turn == 2 && timeBlink == unit)
      char2 = 1;
    else if (turn == 2 && timeBlink == 3 * unit)
      char2 = 2;
    else if (turn == 3 && timeBlink == unit)
      char3 = 1;
    else if (turn == 3 && timeBlink == 3 * unit)
      char3 = 2;
    else if (turn == 4 && timeBlink == unit)
      char4 = 1;
    else if (turn == 4 && timeBlink == 3 * unit)
      char4 = 2;
    else if (turn == 5 && timeBlink == unit)
      char5 = 1;
    else if (turn == 5 && timeBlink == 3 * unit)
      char5 = 2;
      **/
    Serial.print("The time blink is: ");
    Serial.println(timeBlink);
    Serial.print("and the turn is: " + turn);
  }
  //DetermineChar(char1, char2, char3, char4, char5, char6);
}
}/**
void DetermineChar(int char1, int char2, int char3, int char4, int char5, int char6) {
  // I do not know whether to use nested for loops or switch cases for determining which characters to print
  Serial.println(char1 & char2 & char3 & char4 & char5 & char6); // '&' concatenates ints with each other

char1 = 0;
char2 = 0;
char3 = 0;
char4 = 0;
char5 = 0;
char6 = 0; 
}
**/
