/*
The code below does the following:

- Read the state of a digital input pin
- Check if the state has changed from the previous loop
- Save the current state to a variable called prevBtnState for the next loop
*/

int btnPin = 2;
int btnState = false;
int prevBtnState = false;

void setup() {
  // Open the serial port
  Serial.begin(9600);
  // set the button pin to be an input
  pinMode(btnPin, INPUT);
}

void loop() {
  // read the button pin
  btnState = digitalRead(btnPin);

  // check if the button state has changed
  if(btnState != prevBtnState){
    // print the changed state
    Serial.print("Button state changed to: ");
    Serial.println(btnState);
  }

  // save the previous button state for the next loop
  prevBtnState = btnState;
}