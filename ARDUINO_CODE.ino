// Define sensor and relay pin numbers  
#define LDR_PIN 2                // Digital pin for LDR (light sensor)
#define THERMISTOR_PIN A3        // Analog pin for temperature sensor (e.g., LM35)
#define PIR_PIN 4                // Digital pin for motion sensor (PIR)

#define LED_RELAY_PIN 8          // Relay pin to control LED
#define FAN_RELAY_PIN 9          // Relay pin to control Fan
#define ALARM_RELAY_PIN 10       // Relay pin to control Alarm

#include <SoftwareSerial.h>
SoftwareSerial BT(6, 7);         // Bluetooth on digital pins 6 (RX) and 7 (TX)

// Variable to track whether we are in manual mode
bool manualControl = false;

void setup() {
  // Set sensor pins as INPUT
  pinMode(LDR_PIN, INPUT);
  pinMode(THERMISTOR_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);

  // Set relay pins as OUTPUT
  pinMode(LED_RELAY_PIN, OUTPUT);
  pinMode(FAN_RELAY_PIN, OUTPUT);
  pinMode(ALARM_RELAY_PIN, OUTPUT);

  // Set all relays to OFF (HIGH = off for active-low relays)
  digitalWrite(LED_RELAY_PIN, HIGH);
  digitalWrite(FAN_RELAY_PIN, HIGH);
  digitalWrite(ALARM_RELAY_PIN, HIGH);

  // Start Bluetooth communication
  BT.begin(9600);
}

void loop() {
  // Check for incoming Bluetooth command from MIT App
  if (BT.available()) {
    String command = BT.readStringUntil('\n'); // Read one line from BT
    handleBluetoothCommand(command);           // Process the command
  }

  // If we're not in manual mode, control devices using sensors
  if (!manualControl) {
    autoControlDevices();
  }

  // Send temperature and device status to app for live updates
  sendTemperature();
  sendDeviceStatus();

  delay(500); // Small delay to avoid flooding
}

// Handle incoming commands from MIT App
void handleBluetoothCommand(String command) {
  command.trim(); // Remove any trailing newline or space

  // Toggle LED manually
  if (command == "LED") {
    digitalWrite(LED_RELAY_PIN, !digitalRead(LED_RELAY_PIN));
    BT.println("LED Toggled (Manual Control)");
  }

  // Toggle Fan manually
  else if (command == "FAN") {
    digitalWrite(FAN_RELAY_PIN, !digitalRead(FAN_RELAY_PIN));
    BT.println("FAN Toggled (Manual Control)");
  }

  // Toggle Alarm manually
  else if (command == "ALARM") {
    digitalWrite(ALARM_RELAY_PIN, !digitalRead(ALARM_RELAY_PIN));
    BT.println("ALARM Toggled (Manual Control)");
  }

  // Turn ON manual mode
  else if (command == "MANUAL") {
    manualControl = true;
    BT.println("Manual Control Enabled");
  }

  // Turn OFF manual mode, back to auto
  else if (command == "AUTO") {
    manualControl = false;
    BT.println("Automatic Control Enabled");
  }
}

// This function handles auto mode: devices are controlled based on sensors
void autoControlDevices() {
  // Read current light and motion sensor values
  int lightStatus = digitalRead(LDR_PIN);     // LOW = dark
  int motionDetected = digitalRead(PIR_PIN);  // HIGH = motion

  // Turn ON LED only when it's dark and motion is detected
  if (lightStatus == LOW && motionDetected == HIGH) {
    digitalWrite(LED_RELAY_PIN, LOW); // ON
    BT.println("LED ON (Dark and Motion detected)");
  } else {
    digitalWrite(LED_RELAY_PIN, HIGH); // OFF
    BT.println("LED OFF (No Motion or Bright)");
  }

  // Read analog value from LM35 and convert to temperature
  int tempReading = analogRead(THERMISTOR_PIN);    // Range: 0–1023
  float voltage = tempReading * (5.0 / 1023.0);     // Convert to voltage
  float temperature = (voltage - 0.5) * 100.0;      // LM35 formula: 10mV/°C

  // Turn ON Fan if temperature > 27°C AND motion is detected
  if (motionDetected == HIGH && temperature > 27.0) {
    digitalWrite(FAN_RELAY_PIN, LOW); // ON
    BT.println("Motion Detected and Temp > 27°C: FAN ON");
  } else {
    digitalWrite(FAN_RELAY_PIN, HIGH); // OFF
    BT.println("No Motion or Temp <= 27°C: FAN OFF");
  }

  // Trigger ALARM if temperature is dangerously high (> 100°C)
  if (temperature > 100.0) {
    digitalWrite(ALARM_RELAY_PIN, LOW); // ON
    BT.println("Temperature > 100°C: ALARM ON");
  } else {
    digitalWrite(ALARM_RELAY_PIN, HIGH); // OFF
    BT.println("Temperature <= 100°C: ALARM OFF");
  }
}

// Send temperature to MIT App for live display
void sendTemperature() {
  int tempReading = analogRead(THERMISTOR_PIN);
  float voltage = tempReading * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;

//  BT.print("Temperature:");               // Prefix for App to recognize
  BT.println(temperature, 1"°C");      // Send temperature with 1 decimal place
}

// Send LED, FAN, ALARM ON/OFF status to MIT App
void sendDeviceStatus() {
  // Send LED status
  BT.print("LED:");
  BT.println(digitalRead(LED_RELAY_PIN) == LOW ? "ON" : "OFF");

  // Send FAN status
  BT.print("FAN:");
  BT.println(digitalRead(FAN_RELAY_PIN) == LOW ? "ON" : "OFF");

  // Send ALARM status
  BT.print("ALARM:");
  BT.println(digitalRead(ALARM_RELAY_PIN) == LOW ? "ON" : "OFF");
}
