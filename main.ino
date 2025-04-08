const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 11;

const int closeThreshold = 30;
const int mediumThreshold = 100;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.0344 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= closeThreshold) {
    tone(buzzerPin, 1000);
    delay(100);
    noTone(buzzerPin);
    delay(100);
  }
  else if (distance <= mediumThreshold) {
    tone(buzzerPin, 500);
    delay(300);
    noTone(buzzerPin);
    delay(300);
  }
  else {
    noTone(buzzerPin);
  }

  delay(100);
}
