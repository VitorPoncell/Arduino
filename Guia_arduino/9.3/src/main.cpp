//se clicar muito rapido contador contam mais cliques
#include <Arduino.h>

int button = 2;
int ledPin = 13;

int buttonCounter = 0;
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  Serial.begin(9600);

  pinMode(button, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  buttonState = digitalRead(button);

  if(buttonState != lastButtonState){
    if(buttonState == HIGH){
      buttonCounter++;
      Serial.print("numero de pulsos: ");
      Serial.println(buttonCounter);
    }
  }

  lastButtonState = buttonState;
  if(buttonCounter % 4 == 0){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
}
