# Assistive Technology for the Disabled

## 1. Building the Ultrasonic Navigation Aid (For the Visually Impaired)

This project focuses on helping individuals with visual impairments navigate their environment using an ultrasonic sensor to detect obstacles. Feedback is provided through sound or vibration based on the distance to nearby objects.

### **Components Needed:**
- **Arduino Uno or Arduino Nano** (based on size preference) – €10-20
- **HC-SR04 Ultrasonic Sensor** (for distance measurement) – €3-5
- **Buzzer or Vibration Motor** (to provide feedback) – €2-10
- **Breadboard and jumper wires** – €5-10
- **Battery pack** (9V or AA) – €5-15
- **3D Printed Case** (Optional for portability)
  
### **Steps to Build:**

#### **1. Set Up the Hardware:**

1. **Connect the HC-SR04 Ultrasonic Sensor to Your Arduino:**
   - **VCC** to **5V** pin on Arduino.
   - **GND** to **GND**.
   - **Trig** to a digital pin on Arduino (e.g., **Pin 9**).
   - **Echo** to another digital pin (e.g., **Pin 10**).
   
2. **Connect the Buzzer or Vibration Motor:**
   - Connect the buzzer to a digital pin (e.g., **Pin 11**) to give **sound feedback**.
   - Alternatively, connect a **vibration motor** to another digital pin to give **vibration feedback**.

3. **Connect the Power Source:**
   - Attach the **Battery pack** to the Arduino to provide power.

#### **2. Write the Code:**

1. Open the **Arduino IDE** and write the following code to read the distance from the ultrasonic sensor and give feedback based on proximity:

```cpp
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long duration, distance;
  
  // Send a pulse to the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the pulse duration and calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;
  
  // Provide feedback based on distance
  if (distance < 30) {
    tone(buzzerPin, 1000);  // High-pitched sound if too close
  } else if (distance < 100) {
    tone(buzzerPin, 500);   // Medium sound if moderately close
  } else {
    noTone(buzzerPin);     // No sound if far away
  }
  
  delay(100);  // Delay between readings
}
