#include <Arduino.h>

char input= 0;
int rele=2;
int led=13;
bool y=true;

void setup() {
  pinMode(rele,OUTPUT);
  pinMode(led,OUTPUT);

   Serial.begin(9600);
   Serial.println();
   Serial.print("**Codigo para acionar rele conectado ao pino 2 do Arduino ");
   Serial.println("atraves do monitor serial**");
   Serial.println("");
   Serial.println("Pressione 1 e depois ENTER para inverter o estado do rele novamente");
   Serial.println("Aguardando comando :");
}

void loop() {
  if (Serial.available() > 0){
    input= Serial.read();
    if (input =='1'){
      Serial.print("O rele agora esta ");

      if(y){
        digitalWrite(rele, HIGH);
        digitalWrite(led, HIGH);
        Serial.println("ligado");
      }
      else {
        digitalWrite(rele, LOW);
        digitalWrite(led, LOW);
        Serial.println("desligado");
      }
      y=!y;
    }
    else {
      Serial.println("Comando invalido");
    } 
  }
}
