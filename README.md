# 🚗 Arduino Speed Detection System

An Arduino-based speed detection system that measures the speed of a moving object using two IR sensors. The system calculates the time taken for the object to travel between the sensors and determines its speed.

If the detected speed exceeds the predefined speed limit, the system activates a red LED and buzzer as an overspeed warning. For normal speed, a green LED indicates safe operation.

## 📌 Features

- Measures object speed using two IR sensors
- Calculates speed based on distance and time
- Displays speed in km/h using the Arduino Serial Monitor
- Green LED indicates normal speed
- Red LED indicates overspeed condition
- Buzzer provides an overspeed alert
- Adjustable speed limit
- No LCD required

## 🛠 Components Required

- Arduino UNO
- 2 × IR Sensors
- Red LED
- Green LED
- Buzzer
- 2 × 220 Ω resistors
- Breadboard
- Jumper wires
- USB cable

## 🔌 Connections

### IR Sensor 1

| IR Sensor Pin | Arduino UNO |
|---|---|
| VCC | 5V |
| GND | GND |
| OUT | Digital Pin 2 |

### IR Sensor 2

| IR Sensor Pin | Arduino UNO |
|---|---|
| VCC | 5V |
| GND | GND |
| OUT | Digital Pin 3 |

### LEDs

| Component | Arduino Pin |
|---|---|
| Green LED | Digital Pin 6 |
| Red LED | Digital Pin 7 |
| Buzzer | Digital Pin 8 |

All LED negative terminals are connected to GND through current-limiting resistors.

## ⚙️ Working Principle

1. The object first passes in front of IR Sensor 1.
2. Arduino records the start time using `millis()`.
3. The object then reaches IR Sensor 2.
4. Arduino records the end time.
5. The time taken between the two sensors is calculated.
6. The speed of the object is calculated.
7. If the speed exceeds the predefined limit:
   - Red LED turns ON
   - Green LED turns OFF
   - Buzzer activates
8. If the speed is within the limit:
   - Green LED turns ON
   - Red LED remains OFF
   - Buzzer remains OFF

## 📐 Speed Calculation

The speed is calculated using:
Speed = Distance / Time

🚦 Output Indications
| Condition    | Green LED | Red LED | Buzzer |
| ------------ | --------- | ------- | ------ |
| Normal Speed | ON        | OFF     | OFF    |
| Overspeed    | OFF       | ON      | ON     |

💻 Software Used
Arduino IDE
Arduino Serial Monitor






```text
Speed = Distance / Time
