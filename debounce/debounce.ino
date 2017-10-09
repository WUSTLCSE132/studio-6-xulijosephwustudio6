const int buttonPin = 2;
int buttonPress = 0;
bool buttonState;
bool lastButtonState = LOW;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;

void buttonPressed() {
  //Serial.println("test");
  //int reading = digitalRead(buttonPin);
  //Serial.println(reading);
  //if (reading != lastButtonState) {
    //Serial.println("I");
    //lastDebounceTime = millis();
  //}
  unsigned long now = millis();
  if ((now - lastDebounceTime) > debounceDelay) {
    //if (reading != buttonState) {
      //Serial.println("changed");
      //buttonState = reading;
      //if (buttonState == HIGH)
        buttonPress++;
        Serial.println("Interrupt");
        lastDebounceTime = now;
    //}
  }
  //lastButtonState = reading;
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  // Interrupts can happen on "edges" of signals.  
  // Three edge types are supported: CHANGE, RISING, and FALLING 
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, LOW);
  Serial.begin(9600);
}

void loop() {
  /*for(int i=0;i<100;i++) {
    Serial.println(i);
    delay(1000);
  }*/

 // Serial.println(digitalRead(buttonPin));
  // delay(1000);
}
