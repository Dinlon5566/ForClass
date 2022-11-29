#include <LiquidCrystal.h>
#include <RTC.h>

#define BUTTON1 BT1
#define BUTTON2 BT2
#define BUTTON3 BT3
#define BUTTON4 BT4

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int M, d, h, m, s;


int C_seconds = 0;
int C_minutes = 0;
int C_hours = 0;
int CF = 1;
bool timeMode = 0;
bool cont = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  lcd.begin(16, 2);
  M = 11;
  d = 30;
  h = 13;
  m = 40;
  s = 0;
  RTC.settime(d, h, m, s);
  RTC.startcounting();
}

// the loop function runs over and over again forever
void loop() {
  lcd.setCursor(0, 0);
  twoP(M);
  lcd.print("/");
  twoP(RTC.getday());
  lcd.print("   ");
  twoP(RTC.gethours());
  lcd.print(":");
  twoP(RTC.getminutes());
  lcd.print(":");
  twoP(RTC.getseconds());

  if (!digitalRead(BUTTON1))
  {
    C_seconds = 0;
    C_minutes = 0;
    C_hours = 0;
    CF = 1;
    timeMode = 1;
    cont = 0;

    printTime(C_hours, C_minutes, C_seconds);
    lcd.setCursor(7, 1);
    lcd.print("StopWatch");
    delay(500);
  }
  if (!digitalRead(BUTTON4) && timeMode)
  {
    int mscounter = 0;
    while (timeMode) {

      if (cont) {
        lcd.setCursor(8, 1);
        lcd.print("Counting");
        delay(10);
        mscounter += 13;
      } else if (CF) {
        C_seconds = 0;
        C_minutes = 0;
        C_hours = 0;
        mscounter = 0;
        lcd.setCursor(7, 1);
        lcd.print("StopWatch");
      } else {
        lcd.setCursor(8, 1);
        lcd.print("    Stop");
      }
     C_seconds=mscounter/1000;
     C_minutes= C_seconds/60;
     C_hours=C_minutes/60;
     C_seconds%=60;
     C_minutes%=60;
      
      printTime(C_hours, C_minutes, C_seconds);
      if (!digitalRead(BUTTON4)) {
        CF = 0;
        cont ^= 1;
        delay(300);
      }
      if (!digitalRead(BUTTON2)) {
        CF = 1;
        cont = 0;
        delay(300);
      }
    }
    if (!digitalRead(BUTTON3)){
        timeMode=0;
      }

  }


}
void printTime(int h, int m, int s) {
  lcd.setCursor(0, 1);
  twoP(h);
  lcd.print(":");
  twoP(m);
  lcd.print(":");
  twoP(s);

}
void twoP(int n) {
  if (n < 10) {
    lcd.print("0");
  }
  lcd.print(n);
}
