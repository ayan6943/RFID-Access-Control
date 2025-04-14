#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo gateServo;

byte authorizedCard[5] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE}; // Replace with your card UID
int openAngle = 90; // Gate open angle
int closeAngle = 0; // Gate close angle
unsigned long gateOpenDuration = 5000; // Time in ms to keep gate open

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  gateServo.attach(3); // Servo on pin 3
  gateServo.write(closeAngle); // Start closed
  Serial.println("Security Gate Project Initialized");
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.print("Found Card with UID: ");
    printCardID(mfrc522.uid.uidByte, mfrc522.uid.size);

    if (compareCardID(mfrc522.uid.uidByte, mfrc522.uid.size, authorizedCard)) {
      Serial.println("Access Granted - Opening Gate");
      gateServo.write(openAngle);
      delay(gateOpenDuration);
      gateServo.write(closeAngle);
    } else {
      Serial.println("Unauthorized Card - Access Denied");
      // Optional: Add buzzer or LED alert here
    }

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }
}

void printCardID(byte* cardID, byte cardSize) {
  for (byte i = 0; i < cardSize; i++) {
    Serial.print(cardID[i], HEX);
    Serial.print(",");
  }
  Serial.println();
}

bool compareCardID(byte* cardID1, byte cardSize, byte* cardID2) {
  for (byte i = 0; i < cardSize; i++) {
    if (cardID1[i] != cardID2[i]) {
      return false;
    }
  }
  return true;
}
