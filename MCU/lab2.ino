#define BUTTON1 BT1
#define BUTTON2 BT2
#define BUTTON3 BT3
#define BUTTON4 BT4

#define LATCH_DIO D15
#define CLK_DIO D14
#define DATA_DIO 2        // D2 is OK, too
const byte SEGMENT_MAP[] = {0x3F, 0x06, 0x3C, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0X7F, 0X6F, 0X77, 0X7C, 0X39};
const byte SEGMENT_SELECT[] = {0x0E, 0x0D, 0x0B, 0x07};
const byte DP = 0x40;   // Digit Point

void setup() {
  // put your setup code here, to run once:
  pinMode(LATCH_DIO,  OUTPUT);
  pinMode(CLK_DIO,  OUTPUT);
  pinMode(DATA_DIO, OUTPUT);
}
void WriteNumberToSegment(byte Segment, byte Value)
{
  digitalWrite(LATCH_DIO, LOW);
  // The following order cannot be changed. MAP first and then SELECT.
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
  digitalWrite(LATCH_DIO, HIGH);
}
void rightShift(byte val) {
  for (int i = 0; i < 4; i++) {
     digitalWrite(LATCH_DIO, LOW);
    // The following order cannot be changed. MAP first and then SELECT.
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[val]);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[i] );
    digitalWrite(LATCH_DIO,  HIGH);
    delay(200);
  }
}
void leftShift(byte val) {
  for (int i = 3; i >=0;i--) {
    digitalWrite(LATCH_DIO, LOW);
    // The following order cannot be changed. MAP first and then SELECT.
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[val]);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[i] );
    digitalWrite(LATCH_DIO, HIGH);
    delay(200);
  }
}
void echoAll(auto val) {
  digitalWrite(LATCH_DIO, LOW);
     shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[val[0]]);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[0] );
  digitalWrite(LATCH_DIO,HIGH);
  delay(200);
       shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[val[1]]);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[1] );
  digitalWrite(LATCH_DIO,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int val[4] = {3, 6, 4, 8};
  if (!digitalRead(BT1))
  {
    for (int i = 0; i < 4; i++) {
      rightShift(val[i]);
    }
    echoAll(val);
  }
  if (!digitalRead(BT2))
  {
    for (int i = 3; i >=0; i--) {
      leftShift(val[i]);
    }
    echoAll(val);
  }

  
  if (!digitalRead(BT4)) {
    digitalWrite(LATCH_DIO, LOW);
    digitalWrite(LATCH_DIO, HIGH);
  }

}
