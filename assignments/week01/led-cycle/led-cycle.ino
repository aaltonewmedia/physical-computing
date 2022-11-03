int ledPin1 = 10;
int ledPin2 = 9;
int btnPin = 2;
int btnState = 0;
int prevBtnState = 0;
int counter = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(btnPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // check the button
  btnState = digitalRead(btnPin);

  // check if the state is different from the previous loop
  if (btnState != prevBtnState) {
    if (btnState == HIGH) {
      // add one to the counter
      counter++;
      // check if the counter is too large
      if(counter>2){
        counter = 0;
      }
      Serial.println(counter);
    }
  }
  // store the current button state for the next loop
  prevBtnState = btnState;

  switch (counter) {
    case 0:
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      break;
    case 1:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      break;
    case 2:
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      break;
  }

  // delay helps to prevent noise from the input signal
  // even better way to do this would be to implement debouncing:
  // https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce
  delay(10);
}