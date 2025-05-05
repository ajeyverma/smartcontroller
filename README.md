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
- <a href="/Docs" style="text-decoration: none;">`Docs`<a/> – Project summary and Documentation 
- <a href="/Releases" style="text-decoration: none;">`Release`<a/> – Mobile App
- <a href="/ARDUINO_CODE.ino" style="text-decoration: none;">`Arduino_Code.ino`<a/> – Arduino code
- <a href="/Assets/Screenshots" style="text-decoration: none;">`Assets/Screenshots`<a/> – Screenshot of the mobile app UI
- <a href="/Assets/AppSource" style="text-decoration: none;">`Assets/AppSource`<a/> – MIT App Inventor source file 
   ( <i>In case of any modication, Use App Source </i> )

## How to Use
1. Construct the circuit by following the steps in the <a href="/Docs/Setup.md">documentation</a>.
2. Upload the <a href="/ARDUINO_CODE.ino" style="text-decoration: none;">Arduino code</a>.
3. Install app present in <a href="/Releases" style="text-decoration: none;">Release<a/>.
4. Connect your Android device to the Bluetooth module.
5. Use the app to control appliances or let sensors take over.
  








