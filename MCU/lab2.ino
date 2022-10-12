#define BUTTON1 BT1
#define BUTTON2 BT2
#define BUTTON3 BT3
#define BUTTON4 BT4

#define LATCH_DIO D15
#define CLK_DIO D14
#define DATA_DIO 2        // D2 is OK, too

//對應顯示號碼代碼
const byte SEGMENT_MAP[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0X7F, 0X6F, 0X77, 0X7C, 0X39};
//對應面板位置
const byte SEGMENT_SELECT[] = {0x0E, 0x0D, 0x0B, 0x07};


const byte DP = 0x40;   // Digit Point
// 按鍵位置
byte Row = 0, Col = 0;
// 初始顯示號碼
unsigned int val[4] = {0, 0, 0, 0};
unsigned int loc = 0;

void setup() {
  //設定按鍵輸入模式
  pinMode(10, INPUT); //R1: S1,S2,S3,S4 (1,2,3,A)
  pinMode(11, INPUT_PULLUP); //R2: S5,S6,S7,S8 (4,5,6,B)
  pinMode(12, INPUT_PULLUP); //R3: S9, S10, S11,S12 (7,8,9,C)
  pinMode(13, INPUT_PULLUP); //R4: (*,0,#,D)
  //設定輸出以適合負向觸發
  pinMode(A0, OUTPUT); //A1, C1: S1,S5,S9 (1,4,7,*)
  pinMode(A1, OUTPUT); //A2, C2: S2,S6,S10 (2,5,8,0)
  pinMode(A2, OUTPUT); //A3, C3: S3,S7,S11 (3,6,9,#)
  pinMode(A3, OUTPUT); //A4, C4, S4,S8,S12 (*,0, #,D)
  // put your setup code here, to run once:
  pinMode(LATCH_DIO,  OUTPUT);
  pinMode(CLK_DIO,  OUTPUT);
  pinMode(DATA_DIO, OUTPUT);
}
void WriteNumberToSegment(byte Segment, byte Value)
{
  //設定 arg1 為面板位置 PIN:DIO，arg2為顯示號碼 PIN:P；需要依序輸入。
  digitalWrite(LATCH_DIO, LOW);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
  digitalWrite(LATCH_DIO, HIGH);
}

void rightShift(byte val) {
  //每200ms向右移一次(面板位置+1)
  for (int i = 0; i < 4; i++) {
    digitalWrite(LATCH_DIO, LOW);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[val]);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[i] );
    digitalWrite(LATCH_DIO,  HIGH);
    delay(200);
  }
}
void leftShift(byte val) {
  for (int i = 3; i >= 0; i--) {
    digitalWrite(LATCH_DIO, LOW);
    // The following order cannot be changed. MAP first and then SELECT.
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[val]);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[i] );
    digitalWrite(LATCH_DIO, HIGH);
    delay(200);
  }
} 


bool keyscan( )
{
  Row = 0; Col = 0;
  bool keypressed = false;
  //將A0設定為低電位，使目標按鍵按下時也會變成按鍵中僅有的低電位。
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);
  //若是該位置為低電位，即為按下按鈕。
  if (digitalRead(10) == LOW)
  {
    digitalWrite(A0, HIGH);
    Col = 1; Row = 1;
    keypressed = true;
    return (keypressed);
  }
  //Read keys in row.2
  if (digitalRead(11) == LOW)
  {
    digitalWrite(A0, HIGH);
    Col = 1; Row = 2;
    keypressed = true;
    return (keypressed);
  }
  //Read keys in row.3
  if (digitalRead(12) == LOW)
  {
    digitalWrite(A0, HIGH);
    Col = 1; Row = 3;
    keypressed = true;
    return (keypressed);
  }
  //Read keys in row.4
  if (digitalRead(13) == LOW)
  {
    digitalWrite(A0, HIGH);
    Col = 1; Row = 4;
    keypressed = true;
    return (keypressed);
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
    Col = 2; Row = 1;
    keypressed = true;
    return (keypressed);
  }
  //Read keys in row.2
  if (digitalRead(11) == LOW)
  {
    digitalWrite(A1, HIGH);
    Col = 2; Row = 2;
    keypressed = true;
    return (keypressed);
  }
  //Read keys in row.3
  if (digitalRead(12) == LOW)
  {
    digitalWrite(A1, HIGH);
    Col = 2; Row = 3;
    keypressed = true;
    return (keypressed);
  }
  //Read keys in row.4
  if (digitalRead(13) == LOW)
  {
    digitalWrite(A1, HIGH);
    Col = 2; Row = 4;
    keypressed = true;
    return (keypressed);
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
    Col = 3; Row = 1;
    keypressed = true;
    return (keypressed);
  }
  //Read keys in row.2
  if (digitalRead(11) == LOW)
  {
    digitalWrite(A2, HIGH);
    Col = 3; Row = 2;
    keypressed = true;
    return (keypressed);
  }
  //Read keys in row.3
  if (digitalRead(12) == LOW)
  {
    digitalWrite(A2, HIGH);
    Col = 3; Row = 3;
    keypressed = true;
    return (keypressed);
  }
  //Read keys in row.4
  if (digitalRead(13) == LOW)
  {
    digitalWrite(A2, HIGH);
    Col = 3; Row = 4;
    keypressed = true;
    return (keypressed);
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
    Col = 4; Row = 1;
    keypressed = true;
    return (keypressed);
  }
  //Read keys in row.2
  if (digitalRead(11) == LOW)
  {
    digitalWrite(A3, HIGH);
    Col = 4; Row = 2;
    keypressed = true;
    return (keypressed);
  }
  //Read keys in row.3
  if (digitalRead(12) == LOW)
  {
    digitalWrite(A3, HIGH);
    Col = 4; Row = 3;
    keypressed = true;
    return (keypressed);
  }
  //Read keys in row.4
  if (digitalRead(13) == LOW)
  {
    digitalWrite(A3, HIGH);
    Col = 4; Row = 4;
    keypressed = true;
    return (keypressed);
  }
  return (false);
}


void loop() {
  
  if (!digitalRead(BT1))
  {
    //依序將4個數字顯示出來
    for (int i = 0; i < 4; i++) {
      rightShift(val[i]);
    }

  }
  else if (!digitalRead(BT2))
  {
    //依序將4個數字顯示出來
    for (int i = 3; i >= 0; i--) {
      leftShift(val[i]);
    }
    
  } else if (keyscan() == true) {
    //輸入數字後放到顯示陣列中，依序為0~3
    digitalWrite(LATCH_DIO, LOW);
    int keyindex = (Row - 1) * 4 + Col;
    val[loc] = keyindex;
    loc = (loc + 1) % 4;
    delay(500);
  }

  //將四個數字顯示出來
  for (int i = 0; i < 4; i++) {
    digitalWrite(LATCH_DIO, LOW);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[val[i]]);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[i] );
    digitalWrite(LATCH_DIO, HIGH);
  }

  //設定為不顯示使面板不會有特定位置特別亮
  digitalWrite(LATCH_DIO, LOW);  
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, 0x00);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[0] );
  digitalWrite(LATCH_DIO, HIGH);
}
