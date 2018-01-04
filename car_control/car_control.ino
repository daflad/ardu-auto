// Set distance threshold to stop car in cm
int DISTANCE_THRESHOLD = 5;

void setup() {
  // Ultrasound setup
  Serial.begin(9600);
  ultrasoundSetup();
}

void loop() {
  if ObjectAhead() {
    Serial.println("STOP CAR AND REVERSE!")
  }
}
