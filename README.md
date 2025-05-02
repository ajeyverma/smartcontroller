# Smart Controller
<img src="https://raw.githubusercontent.com/ajeyverma/smartcontroller/main/Assets/AppSource/app_logo.png" alt="Smart Home Logo" width="100"/> 


This project is an Arduino + MIT App Inventor-based smart controller for LED, fan, and alarm control using sensors (LDR, PIR, Thermistor) and Bluetooth communication.

## Features
- Automatic Mode: Sensor-based control
  - LED: Turns ON when dark and motion is detected
  - Fan: Turns ON when motion is detected and temperature > 27°C
  - Alarm: Turns ON if temperature > 100°C
- Manual Mode: Control LED/Fan/Alarm from the mobile app
- Live status updates and real-time temperature display

## Components Used
- Arduino Uno
- LDR
- PIR Motion Sensor
- Thermistor (LM35)
- 3-Channel Relay Module
- Bluetooth Module (HC-05)
- AC-DC Converter (for power backup)
- <a href="https://github.com/ajeyverma/smartcontroller/tree/main/Releases" style="text-decoration: none;">Android App (MIT App Inventor) <a/>

## Files
- <a href="/ARDUINO_CODE.ino" style="text-decoration: none;">`Arduino_Code.ino`<a/> – Arduino code
- <a href="/Assets/AppSource" style="text-decoration: none;">`Assets/AppSource`<a/> – MIT App Inventor source file
- <a href="/Docs" style="text-decoration: none;">`Docs`<a/> – Project summary
- <a href="/Assets/Screenshots" style="text-decoration: none;">`Assets/Screenshots`<a/>Images/userinterfacelight.jpg` – Screenshot of the mobile app UI




