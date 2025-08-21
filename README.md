# ESP8266 Wi-Fi Connectivity Project

This project shows how to set up an **ESP8266** microcontroller to connect to a Wi-Fi network.  
It is a simple yet powerful starting point for **IoT projects** such as smart home devices, remote monitoring, and sensor data transmission.

---

## Features
- Connects ESP8266 to a Wi-Fi network
- Easy to configure with your own SSID and password
- Lightweight and beginner-friendly
- Can be extended to send/receive data via HTTP, MQTT, or WebSockets

---

## Requirements
- ESP8266 board (e.g., NodeMCU, Wemos D1 Mini)
- Arduino IDE with ESP8266 board support installed
- USB cable for programming
- Wi-Fi network credentials

---

## Getting Started
1. Clone this repository:
   ```bash
   git clone https://github.com/Soniaify/esp8266-wifi-connectivity.git
2. Open the project in Arduino IDE
3. Install the ESP8266 board support in Arduino IDE (via Boards Manager)
4. Open Wifi_ESP8266.ino
5. Update these lines with your Wi-Fi credentials:
  - const char* ssid = "YourWiFiSSID";
  - const char* password = "YourPassword";
6. Upload the code to your ESP8266 board
7. Open Serial Monitor (baud rate: 115200) to confirm connection

## Project Structure
├── Wifi_ESP8266.ino   # Main code file

## Example Output (Serial Monitor)
Connecting to YourWiFiSSID...
WiFi connected
IP address: 192.168.1.45

## Contribution
Feel free to fork this repo and improve the project (e.g., add HTTP requests, APIs, or MQTT).
Feel free to frk this repo and improve the project (e.g., add HTTP requests, APIs, or MQTT).

