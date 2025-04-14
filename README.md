# RFID Access Control System 🚪🔒

An Arduino-based smart gate system that uses RFID to allow access only to authorized users.

## 💡 Features
- RFID authentication with MFRC522
- Servo motor to open/close gate
- Logs card UID via serial monitor
- Rejects unauthorized users
- Easy to modify UID and gate settings

## 🔌 Hardware Used
- Arduino Uno
- MFRC522 RFID Module
- Servo Motor
- Jumper Wires
- Breadboard

## 🧠 How It Works
1. RFID reader scans for new cards.
2. When a card is detected, its UID is compared.
3. If matched, gate opens for 5 seconds.
4. If not, an alert can be triggered (buzzer/LED).
5. Gate closes automatically after delay.

-  ![WhatsApp Image 2025-04-14 at 19 44 12_0ecbe636](https://github.com/user-attachments/assets/2f4c4c38-f296-4544-ba9d-ae316b689103)


## 🛠 Setup Instructions
1. Wire the RFID reader (using SPI) and servo to Arduino.
2. Upload `.ino` code using Arduino IDE.
3. Update `authorizedCard[]` array with your RFID tag’s UID.
4. Open Serial Monitor to see logs.
---

### 📘 License
MIT License – feel free to reuse and build on it!
