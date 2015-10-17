#define OUTPUT_PULSE_DELAY 250
#define DEBOUNCE_DELAY 10

// switch and output pins
int inputSwitch = 3;
int outputPort = 4;

// pin state variables
boolean currentInputSwitchState = LOW;
boolean previousInputSwitchState = LOW;

void setup() {
  // initialise IO
  pinMode(inputSwitch, INPUT);
  pinMode(outputPort, OUTPUT);
}

void loop() {
  // debounce switch
  currentInputSwitchState = debounce(inputSwitch, previousInputSwitchState);

  // if input switch was just released, activate output
  if (currentInputSwitchState == LOW && previousInputSwitchState == HIGH) {
    doOutputPortDownUp();
  }

  // set previous input switch state
  previousInputSwitchState = currentInputSwitchState;
}


/*
 * Output port functions
 */

void doOutputPortDownUp() {
  digitalWrite(outputPort, HIGH);
  delay(OUTPUT_PULSE_DELAY);
  digitalWrite(outputPort, LOW);
}


/*
 * Debounce function
 */

boolean debounce(int pin, boolean previous) {
  boolean current = digitalRead(pin);

  if (current != previous) {
    delay(DEBOUNCE_DELAY);
    current = digitalRead(pin);
  }

  return current;
}
