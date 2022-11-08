#include <LiquidCrystal.h>

#define LATCH_DIO D15
#define CLK_DIO D14
#define DATA_DIO 2        // D2 is OK, too
#define BUTTON1 BT1
#define BUTTON2 BT2
#define BUTTON3 BT3
#define BUTTON4 BT4
#define BUTTON_A0 A0
#define BUTTON_A1 A1
#define BUTTON_A2 A2
#define BUTTON_A3 A3

const byte DP = 0x40; // Digit Point
int count = 0;
int voice = 2;
int speakerPin = D3;

int BPM = 158*2;
int tempo = 1 / ((float)BPM / 60) * 1000;

bool record = 0;
int rec[255];

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
char KeyValue[] = {'1', '2', '3', 'A', '4', '5', '6', 'B', '7', '8', '9', 'C', '*', '0', '#', 'D'};
byte Row = 0, Col = 0;


String sheet = "ccggaag-ffeeddc-";



void setup() {
  // put your setup code here, to run once:
  pinMode(LATCH_DIO,  OUTPUT);
  pinMode(CLK_DIO,  OUTPUT);
  pinMode(DATA_DIO, OUTPUT);
  pinMode(speakerPin, OUTPUT);

  pinMode(10, INPUT); //R1: S1,S2,S3,S4 (1,2,3,A)
  pinMode(11, INPUT_PULLUP); //R2: S5,S6,S7,S8 (4,5,6,B)
  pinMode(12, INPUT_PULLUP); //R3: S9, S10, S11,S12 (7,8,9,C)
  pinMode(13, INPUT_PULLUP); //R4: (*,0,#,D)
  pinMode(A0, OUTPUT); //A1, C1: S1,S5,S9 (1,4,7,*)
  pinMode(A1, OUTPUT); //A2, C2: S2,S6,S10 (2,5,8,0)
  pinMode(A2, OUTPUT); //A3, C3: S3,S7,S11 (3,6,9,#)
  pinMode(A3, OUTPUT); //A4, C4, S4,S8,S12 (A,B,C,D)
  //Pin left to right :R1 R2 R3 R4 C1 C2 C3 C4
  /*
   * c d e H
   * f g a M
   * b - - L
   */
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  lcd.begin(16, 2);              // start the library
  lcd.setCursor(0, 0);
  lcd.print(tempo);
}

void loop() {
  keyscan();
  if(!digitalRead(BUTTON1))    
    {
      lcd.setCursor(1,0);
      lcd.print("Recording");
      record=true;
    }
    if(!digitalRead(BUTTON2))    
    {
      lcd.setCursor(1,0);
      lcd.print("No Recording");
      record=false;
    }
    if(!digitalRead(BUTTON3))    
    {
      lcd.setCursor(1,0);
      lcd.print("Playing");
      for(int i=0; i<count; i++)
      {
        playNote(speakerPin,rec[i], tempo, voice);
      }
      count=0;
    }
    if(!digitalRead(BUTTON4))
    {
      lcd.setCursor(0,0);
      lcd.print("little Star");
      playSong();
    }
    
}

bool keyscan( )
{
  Row = Col = 0;
  //scan col1
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);

  //Read keys in row.1
  if (digitalRead(10) == LOW)
  {
    digitalWrite(A0, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Do");
    playNote(speakerPin, 'c', tempo, voice);
    if (record)
    {
      addNote('c');
    }

    Col = 1; Row = 1;
    return (1);
  }
  //Read keys in row.2
  if (digitalRead(11) == LOW)
  {
    digitalWrite(A0, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Fa");
    playNote(speakerPin, 'f', tempo, voice);
    if (record)
    {
      addNote('f');
    }

    Col = 1; Row = 2;
    return (1);
  }
  //Read keys in row.3
  if (digitalRead(12) == LOW)
  {
    digitalWrite(A0, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Si");
    playNote(speakerPin, 'b', tempo, voice);
    if (record)
    {
      addNote('b');
    }
    Col = 1; Row = 3;

    return (1);
  }
  //Read keys in row.4
  if (digitalRead(13) == LOW)
  {
    digitalWrite(A0, HIGH);

    //nothing

    Col = 1; Row = 4;
    return (1);
  }

  //scan col 2
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);

  //Read keys in row.1
  if (digitalRead(10) == LOW)
  {
    digitalWrite(A1, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Re");
    playNote(speakerPin, 'd', tempo, voice);
    if (record)
    {
      addNote('d');
    }

    Col = 2; Row = 1;
    return (1);
  }
  //Read keys in row.2
  if (digitalRead(11) == LOW)
  {
    digitalWrite(A1, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("So");
    playNote(speakerPin, 'g', tempo, voice);
    if (record)
    {
      addNote('g');
    }

    Col = 2; Row = 2;
    return (1);
  }
  //Read keys in row.3
  if (digitalRead(12) == LOW)
  {
    digitalWrite(A1, HIGH);

    //nothing

    Col = 2; Row = 3;
    return (1);
  }
  //Read keys in row.4
  if (digitalRead(13) == LOW)
  {
    digitalWrite(A1, HIGH);

    //nothing

    Col = 2; Row = 4;
    return (1);
  }

  //scan col 3
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);
  //Read keys in row.1
  if (digitalRead(10) == LOW)
  {
    digitalWrite(A2, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mi");
    playNote(speakerPin, 'e', tempo, voice);
    if (record)
    {
      rec[count] = 'e';
      count++;
    }
    Col = 3; Row = 1;

    return (1);
  }
  //Read keys in row.2
  if (digitalRead(11) == LOW)
  {
    digitalWrite(A2, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("La");
    playNote(speakerPin, 'a', tempo, voice);
    if (record)
    {
      rec[count] = 'a';
      count++;
    }
    Col = 3; Row = 2;

    return (1);
  }
  //Read keys in row.3
  if (digitalRead(12) == LOW)
  {
    digitalWrite(A2, HIGH);
    Col = 3; Row = 3;

    return (1);
  }
  //Read keys in row.4
  if (digitalRead(13) == LOW)
  {
    digitalWrite(A2, HIGH);

    //nothing

    Col = 3; Row = 4;
    return (1);
  }

  //scan col 4
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
  delayMicroseconds(100);
  //Read keys in row.1
  if (digitalRead(10) == LOW)
  {
    digitalWrite(A3, HIGH);
    voice = 3; //H
    lcd.setCursor(0, 12);
    lcd.print("HIGH");
    Col = 4; Row = 1;

    return (1);
  }
  //Read keys in row.2
  if (digitalRead(11) == LOW)
  {
    digitalWrite(A3, HIGH);
    voice = 2; //M

    lcd.setCursor(0, 10);
    lcd.print("MIDDLE");
    Col = 4; Row = 2;

    return (1);
  }
  //Read keys in row.3
  if (digitalRead(12) == LOW)
  {
    digitalWrite(A3, HIGH);
    voice = 1; //L
    lcd.setCursor(0, 13);
    lcd.print("LOW");
    Col = 4; Row = 3;

    return (1);
  }
  //Read keys in row.4
  if (digitalRead(13) == LOW)
  {
    digitalWrite(A3, HIGH);

    voice = 0; //Z
    lcd.setCursor(0, 13);
    lcd.print("MUTE");

    Col = 4; Row = 4;
    return (1);
  }
  return (false);
}

void playSong() {
    lcd.setCursor(0, 1);
lcd.print("Playing a Song.");
  for (int i = 0; i < 15; i++) {
    playNote(speakerPin, sheet[i], tempo, voice);
  }
}
void addNote(char c) {
  rec[count++] = c;
}

void playNote(int OutputPin, char note, unsigned long duration, int select) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 261, 294, 330, 349, 392, 440, 494, 523 };
  if (note == '-') {
    delay(duration);
  }
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      tone(OutputPin, tones[i]*select, duration);
      delay(duration);
      noTone(OutputPin);
      delay(max(duration * 0.01,20));
    }
  }
}
