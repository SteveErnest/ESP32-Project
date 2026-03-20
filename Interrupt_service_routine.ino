
// Define LED and switch connections
const byte ledPin = 5;
const byte ledPin_2 = 23;
const byte buttonPin = 4;

// Boolean to represent toggle state

volatile bool toggleState = false;

void checkSwitch() {
  // Check status of switch
  // Toggle LED if button pressed

  if (digitalRead(buttonPin) == LOW) {
    // Switch was pressed
    // Change state of toggle
    toggleState = !toggleState;
    // Indicate state on LED
    digitalWrite(ledPin, toggleState);
  }
}

void setup() {
  // Set LED pin as output
  pinMode(ledPin, OUTPUT);

  pinMode(ledPin_2, OUTPUT);
  // Set switch pin as INPUT with pullup
  pinMode(buttonPin, INPUT_PULLUP);

  // Attach Interrupt to Interrupt Service Routine
  attachInterrupt(digitalPinToInterrupt(buttonPin),checkSwitch, FALLING); 
}

void loop() {
  digitalWrite(ledPin_2, HIGH);
  delay(200);
  digitalWrite(ledPin_2, LOW);
  delay(200);
}