int sensorPin = 11;  // IR Sensor DO → D11
int buzzerPin = 9;   // Buzzer (+)  → D9

bool triggered = false;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  int sensorState = digitalRead(sensorPin);

  // Laser beam broken → trigger buzzer
  if (sensorState == LOW && !triggered) {
    triggered = true;
    digitalWrite(buzzerPin, HIGH);
    delay(2000);               // Buzz for 2 seconds
    digitalWrite(buzzerPin, LOW);
  }

  // Reset when laser is restored
  if (sensorState == HIGH) {
    triggered = false;
  }
}