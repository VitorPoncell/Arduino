#include <Arduino.h>

int ledPin = 12;

char* letters[] = {
  ".-", "-...", "-.-.,", "-..", ".", "..-.", "--.", "....", "..", //A-I
  ".---", "-.-", ".-...", "--", "-.", "---", ".--.", "--.-", ".-.", //J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." //S-Z
};

char* numbers[] = {
  "-----", ".----", "..---", "...--", "....-", "....", //0-5
  "-....", "--...", "---..", "----" // 6-9
};

int dotDelay = 200;

void flashDotOrDash(char dotOrDash);
void flashSequence(char* sequence);

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    char ch;
    if (Serial.available()) {
      ch = Serial.read();
      if(ch >= 'a' && ch <= 'z'){
        flashSequence(letters[ch - 'a']);
      }else if(ch >= 'A' && ch <= 'Z'){
        flashSequence(letters[ch - 'A']);
      }else if(ch >= '0' && ch <= '9'){
        flashSequence(numbers[ch - '0']);
      }else if(ch == ' '){
        delay(dotDelay*4);
      }
    }
}

void flashSequence(char* sequence){
  int i = 0;
  while (sequence[i] != NULL) {
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(dotDelay*3);
}

void flashDotOrDash(char dotOrDash){
  digitalWrite(ledPin, HIGH);
  if(dotOrDash == '.'){
    delay(dotDelay);
  }else{
    delay(dotDelay*3);
  }
  digitalWrite(ledPin, LOW);
  delay(dotDelay);
}
