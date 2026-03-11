# 🎯 Arduino Nano Laser Tag System

A simple 2-player laser tag hit detection system built with Arduino Nano, an IR/laser sensor, and a buzzer. When the laser beam hits the sensor, the buzzer sounds for 2 seconds — confirming a valid hit.

---

## 📸 Demo

> Laser gun fires → beam hits sensor → buzzer sounds for 2 seconds ✅

---

## 🛠️ Hardware Required

| Component | Quantity |
|---|---|
| Arduino Nano | 1 |
| MH-Series IR/Laser Sensor | 1 |
| Active Buzzer | 1 |
| Jumper Wires | ~6 |
| USB Cable (Mini-B) | 1 |

---

## 🔌 Pin Connections

### IR Sensor → Arduino Nano
| Sensor Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| DO | D11 |
| AO | A0 *(optional)* |

### Buzzer → Arduino Nano
| Buzzer Pin | Arduino Pin |
|---|---|
| + (positive) | D9 |
| − (negative) | GND |

---

## 💻 Code

```cpp
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

  // Laser beam hit → trigger buzzer
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
```

---

## ⚙️ How It Works

1. The laser gun emits a continuous laser beam aimed at the sensor
2. The MH-series sensor outputs **HIGH** when beam is present
3. When the beam hits the sensor (player is "shot"), DO pin goes **LOW**
4. Arduino detects LOW signal → triggers buzzer for **2 seconds**
5. System resets automatically after buzzer stops

---

## 📦 Libraries

No external libraries required. Uses core Arduino functions only.

---

## 🚀 Getting Started

1. Clone this repo
2. Wire components as per the pin connection table above
3. Open `laser_tag.ino` in Arduino IDE
4. Select **Arduino Nano** as board and correct COM port
5. Upload and test!

---

## 🔮 Future Improvements

- Add OLED display for lives/score tracking
- Multiple hit detection (3 lives system)
- LED indicator for hit feedback
- 2-player full duplex system

---

## 📄 License

MIT License — free to use and modify.