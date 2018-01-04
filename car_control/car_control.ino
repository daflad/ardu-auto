// Global Vars
// ultrasound object detection
// Trigger ultasound & Listen for responce
int TRIGGER_PIN = 2;
int ECHO_PIN = 3;
// Set distance threshold to stop car in cm
int DISTANCE_THRESHOLD = 5;

void setup() {
  // Ultrasound setup
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  if ObjectAhead() {

  }
}

// ObjectAhead
// Trigger Ultrasound & Listen for reponce
// pulseIn will return integer
// larger values are further away
bool ObjectAhead() {
  // Clear signal with LOW
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  // Send signal for 10 microseconds HIGH
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  // Clear signal with LOW
  digitalWrite(TRIGGER_PIN, LOW);
  long microseconds = pulseIn(ECHO_PIN, HIGH);
  long distance = microsecondsToCentimeters(microseconds);
  logObjectAhead(distance);
  return distance < DISTANCE_THRESHOLD;
}

// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the object we
// take half of the distance travelled.
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

// Print the distanct if it is less than DISTANCE_THRESHOLD
void logObjectAhead(long distance) {
  if (distance < DISTANCE_THRESHOLD) {
    Serial.print("Object Ahead");
    Serial.println(distance);
  }
}
