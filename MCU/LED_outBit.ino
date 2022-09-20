
#define MS 5
#define NUM 20 // 首先定義LED的數目
//D0, D1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, D14, D15, A0, A1, A2, A3    , LED1, LED2, LED3,LED4

int LEDS[5][4] = {{D0, D1, 2, 0}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, D14, D15}, { A3, A2, A1, A0}};

// 將每個腳位模式設為OUTPUT
void setup() {

  for (int i = 0; i < MS; i++)
  {
    for (int j = 0; j < 4; j++) {
      pinMode(LEDS[i][j], OUTPUT);
    }
  }

}
void light(int n) {
  for (int i = 0; i < MS; i++) {
    if (i == 0 && n == 3)continue;
    digitalWrite(LEDS[i][n], 0);
  }
}

void setallDown() {
  for (int i = 0; i < MS; i++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(LEDS[i][j], 1);
    }
  }
}

void lightBit(int num) {
  for (int i = 0; i < 4; i++) {
    if (num & 1) {
      light(i);
    }
    num >>= 1;
  }
}

void loop() {
  for (int i = 0; i < 16; i++ ) {
    setallDown();
    lightBit(i);
    delay(300);
  }


}
