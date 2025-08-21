#include <SPI.h>
#include <MFRC522.h>
#include <ESP8266WiFi.h>

// WiFi Credentials
const char* ssid = "Infinix HOT 30i";
const char* password = "Stephbaby24";

// RFID Pins
#define SS_PIN D8
#define RST_PIN D1

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(115200);
  SPI.begin(); 
  mfrc522.PCD_Init();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
    
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    
  Serial.println("\nWiFi connected!");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  Serial.print("RFID UID: ");
  String tagID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    tagID += String(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println(tagID);

  // Send UID to a server (Replace with your server)
  sendToServer(tagID);

  delay(1000);
}

void sendToServer(String tagID) {
  WiFiClient client;
  const char* server = "192.168.236.202"; // Replace with your PC's IP

  if (!client.connect(server, 3000)) { // Ensure port 3000 is used
    Serial.println("Connection failed!");
    return;
  }

  // Correct HTTP Request
  String httpRequest = String("GET /attendance?tag=") + tagID + " HTTP/1.1\r\n" +
    "Host: 192.168.236.202\r\n" +  // Use your IP 
    "Connection: close\r\n\r\n";

    client.print(httpRequest);
    Serial.println("Data sent to server: " + tagID);
}
