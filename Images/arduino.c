// Pin configuration
const int greenLightPin = 2;    // Green light pin
const int yellowLightPin = 3;   // Yellow light pin
const int redLightPin = 4;      // Red light pin
const int emergencyButtonPin = 7; // Emergency vehicle detection button

// Timing intervals in milliseconds
const int greenLightDuration = 5000;    // Duration for green light (5 seconds)
const int yellowLightDuration = 2000;   // Duration for yellow light (2 seconds)
const int redLightDuration = 5000;      // Duration for red light (5 seconds)

// State variables
bool emergencyDetected = false;

void setup() {
  // Set up the pins
  pinMode(greenLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(redLightPin, OUTPUT);
  pinMode(emergencyButtonPin, INPUT_PULLUP);  // Button for emergency detection

  // Initialize traffic lights
  digitalWrite(greenLightPin, LOW);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(redLightPin, LOW);

  Serial.begin(9600);
}

void loop() {
  // Check for emergency vehicle detection
  emergencyDetected = digitalRead(emergencyButtonPin) == LOW;

  if (emergencyDetected) {
    Serial.println("Emergency vehicle detected! Giving priority...");
    giveEmergencyPriority();
  } else {
    // Normal traffic light cycle
    normalTrafficCycle();
  }

  delay(100);  // Short delay to avoid debounce issues
}

void normalTrafficCycle() {
  // Green Light
  Serial.println("Green Light - Cars can go");
  digitalWrite(greenLightPin, HIGH);
  delay(greenLightDuration);
  digitalWrite(greenLightPin, LOW);

  // Yellow Light
  Serial.println("Yellow Light - Prepare to stop");
  digitalWrite(yellowLightPin, HIGH);
  delay(yellowLightDuration);
  digitalWrite(yellowLightPin, LOW);

  // Red Light
  Serial.println("Red Light - Cars must stop");
  digitalWrite(redLightPin, HIGH);
  delay(redLightDuration);
  digitalWrite(redLightPin, LOW);
}

void giveEmergencyPriority() {
  // Turn all lights red to stop regular traffic
  digitalWrite(greenLightPin, LOW);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(redLightPin, HIGH);
  
  // Wait while emergency vehicle passes
  Serial.println("All traffic stopped for emergency vehicle.");
  delay(10000); // Time given for emergency vehicle to pass

  // Resume normal operation
  digitalWrite(redLightPin, LOW);
  Serial.println("Emergency vehicle passed, resuming normal operation.");
}
