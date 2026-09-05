const int sensor1 = 2;
const int sensor2 = 3;

const int greenLED = 6;
const int redLED = 7;
const int buzzer = 8;

// Distance between the two IR sensors in meters
const float distance = 0.20;

// Speed limit in km/h
const float speedLimit = 0.20;

unsigned long startTime;
unsigned long endTime;

float timeTaken;
float speedMS;
float speedKMH;

void setup() {
  // IR sensors
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

  // Output devices
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Initially everything OFF
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);

  Serial.begin(9600);

  Serial.println("Speed Detection System");
  Serial.println("----------------------");
  Serial.println("Ready...");
}

void loop() {

  // Check Sensor 1
  if (digitalRead(sensor1) == LOW) {

    // Record starting time
    startTime = micros();

    Serial.println("Sensor 1 detected!");

    // Wait until object leaves Sensor 1
    while (digitalRead(sensor1) == LOW) {
    }

    // Wait until object reaches Sensor 2
    while (digitalRead(sensor2) == HIGH) {
    }

    // Record ending time
    endTime = micros();

    // Calculate time in seconds
    timeTaken = (endTime - startTime) / 1000000.0;

    if (timeTaken > 0) {

      // Calculate speed
      speedMS = distance / timeTaken;
      speedKMH = speedMS * 3.6;

      // Display time
      Serial.print("Time: ");
      Serial.print(timeTaken, 3);
      Serial.println(" seconds");

      // Display speed
      Serial.print("Speed: ");
      Serial.print(speedKMH, 2);
      Serial.println(" km/h");

      // NORMAL SPEED CONDITION
      if (speedKMH <= speedLimit) {

        Serial.println("NORMAL SPEED");

        // Green LED ON
        digitalWrite(greenLED, HIGH);

        // Red LED and buzzer OFF
        digitalWrite(redLED, LOW);
        digitalWrite(buzzer, LOW);

        delay(2000);

        // Turn Green LED OFF
        digitalWrite(greenLED, LOW);
      }

      // OVERSPEED CONDITION
      else {

        Serial.println("OVERSPEED!");

        // Green LED OFF
        digitalWrite(greenLED, LOW);

        // Red LED and buzzer ON
        digitalWrite(redLED, HIGH);
        digitalWrite(buzzer, HIGH);

        delay(2000);

        // Turn Red LED and buzzer OFF
        digitalWrite(redLED, LOW);
        digitalWrite(buzzer, LOW);
      }

      Serial.println("----------------------");

      // Wait until object leaves Sensor 2
      while (digitalRead(sensor2) == LOW) {
      }

      // Small delay before next measurement
      delay(500);
    }
  }
}