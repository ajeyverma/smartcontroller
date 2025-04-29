<img src="https://raw.githubusercontent.com/ajeyverma/smartcontroller/main/Assets/logo.png" alt="Smart Home Logo" width="100"/> 


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
- Android App (MIT App Inventor)

## Files
- `Code/Arduino_Code.ino` – Arduino code
- `App/smartControllerV2.aia` – MIT App Inventor source file
- `Presentation/Smart_Home_Controller_Presentation.pdf` – Project summary
- `Images/userinterfacelight.jpg` – Screenshot of the mobile app UI

## How to Use
1. Upload the Arduino code.
2. Import `.aia` into MIT App Inventor to build your app.
3. Connect your Android device to the Bluetooth module.
4. Use the app to control appliances or let sensors take over.


