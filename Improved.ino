// Better because toggles bulb once per detection (distance <= 10 cm)

#define trigPin 6
#define echoPin 5
#define bulb 9

const int distThreshold = 10;
bool bulbState = false;
bool prevDetected = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(bulb, OUTPUT);
}

void loop() {
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  bool objectDetected = (distance > 0 && distance <= distThreshold);

  if (objectDetected && !prevDetected) {
    // Object just detected — toggle the bulbState
    bulbState = !bulbState;
    digitalWrite(bulb, bulbState ? HIGH : LOW);
  }

  // Update detection state for next loop
  prevDetected = objectDetected;

  delay(100);  // Lower delay = faster loop
}
