int greenLedPin = 9;
int blueLedPin = 11;

bool patternState = true;

int buttonPin = 5;
int debounceDelay = 10;

bool greenLedState = true;
bool blueLedState = false;

unsigned long lastBlinkTime = 0;


void setup() {

  Serial.begin(9600);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  int oldButtonState = 0;
  int newButtonState = 0;

  oldButtonState = digitalRead(buttonPin);
  delay(debounceDelay);
  newButtonState = digitalRead(buttonPin);

  if (oldButtonState != newButtonState) {

    if (newButtonState == LOW) {
      patternState = !patternState;
    }
  }


  if (patternState) {
    int waitTime = 100;
    unsigned long currentTime = millis();

      if (currentTime - lastBlinkTime > waitTime) {
        greenLedState = !greenLedState;
        blueLedState = !blueLedState;
        lastBlinkTime = millis();
        }

          if (greenLedState) {
            digitalWrite(greenLedPin, HIGH);
            } else {
            digitalWrite(greenLedPin, LOW);
            }

          if (blueLedState) {
            digitalWrite(blueLedPin, HIGH);
            } else {
            digitalWrite(blueLedPin, LOW);
            }

        } else {
    
    int waitTime = 500;
    unsigned long currentTime = millis();

      if (currentTime - lastBlinkTime > waitTime) {
         greenLedState = !greenLedState;
         blueLedState = !blueLedState;
         lastBlinkTime = millis();
         }

          if (greenLedState) {
             digitalWrite(greenLedPin, HIGH);
             } else {
             digitalWrite(greenLedPin, LOW);
             }

          if (blueLedState) {
            digitalWrite(blueLedPin, HIGH);
            } else {
            digitalWrite(blueLedPin, LOW);
            }
      }
 
  Serial.println(patternState);
}
