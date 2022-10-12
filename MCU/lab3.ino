#include <LiquidCrystal.h>

#define DELAY_TIME 300
#define BTN1 BT1
#define BTN2 BT2
#define BTN3 BT3
#define BTN4 BT4

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(BT4, INPUT);

  //read
  pinMode(10, INPUT); //R1: S1,S2,S3,S4 (1,2,3,A)
  pinMode(11, INPUT_PULLUP); //R2: S5,S6,S7,S8 (4,5,6,B)
  pinMode(13, INPUT_PULLUP); //R4: (*,0,#,D)
  pinMode(A0, OUTPUT); //A1, C1: S1,S5,S9 (1,4,7,*)
  pinMode(A3, OUTPUT); //A4, C4, S4,S8,S12 (A,B,C,D)

  lcd.begin(40, 2);
  lcd.noCursor();
  lcd.setCursor(0, 1);
  lcd.print("Init done");
}

int buttonState1, buttonState2, buttonState3, buttonState4 = 0;
int shiftArr = 0, shiftStat = 0;
int cursorStat = 0;
int keyIn = -1;
String str1 = "_123456789_223456789_323456789_423456789";
String str2 = "@123456789@223456789@323456789@423456789";

void loop() {
  buttonState1 = digitalRead(BT1);
  buttonState2 = digitalRead(BT2);
  buttonState3 = digitalRead(BT3);
  buttonState4 = digitalRead(BT4);
  if (scanKey() == 1) {
    if (keyIn == 0x01) {
      lcd.setCursor(0, 0);
      lcd.print(str1);
    }
    if (keyIn == 0x0a) {
      lcd.setCursor(0, 1);
      lcd.print(str2);
    }
    if (keyIn == 0x04) {
      shiftStr(1);
    }
    if (keyIn == 0x0d) {
      shiftStr(0);
    }
    delay(DELAY_TIME);
  }
  if (buttonState1 == 0) {
    lcd.clear();
  }
  if (buttonState2 == 0) {
    lcd.home();
  }
  if (buttonState4 == 0) {
    cursorStat ^= 1;
    if (cursorStat) {
      lcd.cursor();
    } else {
      lcd.noCursor();
    }
  }
  delay(DELAY_TIME);
}

void shiftStr(bool shiftArr) {
  for (int i = 0; i < 40; i++) {
    if (shiftArr == 1)
      lcd.scrollDisplayLeft();
    else
      lcd.scrollDisplayRight();
    delay(DELAY_TIME);

  }


}

bool scanKey() {
  keyIn = -1;
  digitalWrite(A0, LOW);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);
  if (digitalRead(10) == LOW) {
    keyIn = 0x01;
    return 1;
  }
  if (digitalRead(11) == LOW) {
    keyIn = 0x04;
    return 1;
  }
  digitalWrite(A0, HIGH);
  digitalWrite(A3, LOW);
  delayMicroseconds(100);
  if (digitalRead(10) == LOW) {
    keyIn = 0x0a;
    return 1;
  }
  if (digitalRead(13) == LOW) {
    keyIn = 0x0d;
    return 1;
  }
  return 0;
}


/*

   if (buttonState1 == LOW) {
    lcd.clear();
    lcd.print(str1);
    lcd.setCursor(0, 1);
    lcd.print(str2);
  }
  if (buttonState2 == LOW) {
    shiftStat = 1 ^ shiftStat;
    delay(1000);
  }
  if (buttonState3 == LOW) {
    shiftArr = 0;
  }
  if (buttonState4 == LOW) {
    shiftArr = 1;
  }
  if (shiftStat == 1) {
    if (shiftArr == 1)
      lcd.scrollDisplayLeft();
    else
      lcd.scrollDisplayRight();
    delay(DELAY_TIME);
  }

 */
