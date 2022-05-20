int buttonPin_fire = 9, buttonPin_retry = 8;
int buttonPin_up = 7, buttonPin_down = 4, buttonPin_left = 6, buttonPin_right = 5;

int direction = 0;
int rValue = 0;  // value of the button ReTry/Next
int fValue = 0;  // value of the button
int wValue = 0, sValue = 0, aValue = 0, dValue = 0;

void setup() {
    Serial.begin(9600);  // Open the serial port
    // button inputs
    pinMode(buttonPin_fire, INPUT);
    pinMode(buttonPin_retry, INPUT);
    digitalWrite(buttonPin_fire, HIGH);
    digitalWrite(buttonPin_retry, HIGH);
    // WASD inputs
    pinMode(buttonPin_up, INPUT);
    pinMode(buttonPin_down, INPUT);
    pinMode(buttonPin_left, INPUT);
    pinMode(buttonPin_right, INPUT);
}

void loop() {
    // Read the logic value of buttons
    rValue = digitalRead(buttonPin_retry);
    fValue = digitalRead(buttonPin_fire);

    wValue = digitalRead(buttonPin_up);
    aValue = digitalRead(buttonPin_left);
    sValue = digitalRead(buttonPin_down);
    dValue = digitalRead(buttonPin_right);

    // set all 8 direction
    if (wValue == 1 && sValue == 0 && aValue == 0 && dValue == 0) {
        direction = 1;
    } else if (wValue == 1 && sValue == 0 && aValue == 0 && dValue == 1) {
        direction = 2;
    } else if (wValue == 0 && sValue == 0 && aValue == 0 && dValue == 1) {
        direction = 3;
    } else if (wValue == 0 && sValue == 1 && aValue == 0 && dValue == 1) {
        direction = 4;
    } else if (wValue == 0 && sValue == 1 && aValue == 0 && dValue == 0) {
        direction = 5;
    } else if (wValue == 0 && sValue == 1 && aValue == 1 && dValue == 0) {
        direction = 6;
    } else if (wValue == 0 && sValue == 0 && aValue == 1 && dValue == 0) {
        direction = 7;
    } else if (wValue == 1 && sValue == 0 && aValue == 1 && dValue == 0) {
        direction = 8;
    } else {
        direction = 0;
    }
    // println(direction, rValue, fValue);
    Serial.print(direction);
    Serial.print(",");

    Serial.print(!rValue);
    Serial.print(",");
    Serial.print(!fValue);
    Serial.print("\n");

    // Small delay before the next measurement
    delay(10);
}
