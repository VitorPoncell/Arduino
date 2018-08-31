#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

const int RANDSEEDPIN = 7;
const int MINSTEPDURATION = 150;
const int MAXSTEPDURATION = 300;
const int ROADLEN = 19;
const int NCARPOSITIONS = 8;
const int MAXROADPOS = 3 * NCARPOSITIONS;


byte car[2][8] = {{

    B10100,
    B11110,
    B11110,
    B10100,
    B00000,
    B00000,
    B00000,
    B00000
  }, {
    B00000,
    B00000,
    B00000,
    B00000,
    B10100,
    B11110,
    B11110,
    B10100
  }
};

byte truck[2][8] = {{

    B11111,
    B11111,
    B11111,
    B11111,
    B00000,
    B00000,
    B00000,
    B00000
  }, {
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
    B11111,
    B11111,
    B11111
  }
};

int inputPin = 3;
int analogCarPos = 0;
int carPos = 0;
bool crash = false;
int road[ROADLEN];
char lineBuff[2 + ROADLEN];
int roadIndex;
int stepDuration;


void setup() {
  Serial.begin(9600);

  roadIndex = 0;
  stepDuration = MAXSTEPDURATION;
  lineBuff[1 + ROADLEN] = '\0';
  randomSeed(analogRead(RANDSEEDPIN));
  for (int i = 0; i < ROADLEN; i++) {
    road[i] = -1;
  }

  lcd.begin (20, 4);
  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);
  lcd.createChar(0, car[0]);
  lcd.createChar(1, car[1]);
  lcd.clear();


}

void loop() {
  if (!crash) {
    getCarPos();
    crash = carPos == road[roadIndex];
  }
  if (!crash) {
    int prevPos = road[(roadIndex - 1) % ROADLEN];
    int thisPos = random(MAXROADPOS);
    while (abs(thisPos - prevPos) < 2) {
      thisPos = random(MAXROADPOS);
    }
    road[roadIndex] = thisPos;
    roadIndex = (roadIndex + 1) % ROADLEN;
    printRoad();
    delay(stepDuration);
    if (stepDuration > MINSTEPDURATION) {
      stepDuration--;
    }

  }


  printCar(carPos);


}

void getCarPos() {
  analogCarPos = analogRead(inputPin);
  Serial.println(analogCarPos);
  if (analogCarPos >= 896) {
    carPos = 0;
  } else if (analogCarPos >= 768) {
    carPos = 1;
  } else if (analogCarPos >= 640) {
    carPos = 2;
  } else if (analogCarPos >= 512) {
    carPos = 3;
  } else if (analogCarPos >= 384) {
    carPos = 4;
  } else if (analogCarPos >= 256) {
    carPos = 5;
  } else if (analogCarPos >= 128) {
    carPos = 6;
  } else {
    carPos = 7;
  }
}

void printRoad(){
  for(int i = 0;i<ROADLEN;i++){
    int pos = road[(i+roadIndex)%ROADLEN];
    lineBuff[i+1] = pos>=0;
  }
}

void printCar(int pos) {
  if (pos == 0) {
    lcd.setCursor(0, 0);
    lcd.print(char(0));
  } else if (pos == 1) {
    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(0, 0);
    lcd.print(char(1));
  } else if (pos == 2) {
    lcd.setCursor(0, 0);
    lcd.print(" ");
    lcd.setCursor(0, 1);
    lcd.print(char(0));
  } else if (pos == 3) {
    lcd.setCursor(0, 2);
    lcd.print(" ");
    lcd.setCursor(0, 1);
    lcd.print(char(1));
  } else if (pos == 4) {
    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(0, 2);
    lcd.print(char(0));
  } else if (pos == 5) {
    lcd.setCursor(0, 3);
    lcd.print(" ");
    lcd.setCursor(0, 2);
    lcd.print(char(1));
  } else if (pos == 6) {
    lcd.setCursor(0, 2);
    lcd.print(" ");
    lcd.setCursor(0, 3);
    lcd.print(char(0));
  } else if (pos == 7) {
    lcd.setCursor(0, 3);
    lcd.print(char(1));
  }

}

