# Smart Home Controller Overview

## Smart Bluetooth-Based Home Controller

**Image:** ![Smart Home Logo](logo.png)

**Introduction:**
A compact, solar-powered smart home system using Arduino Nano, controlled via Bluetooth using a custom MIT App Inventor interface.

**Key Features:**
- Dual mode: Automatic / Manual
- Real-time temperature monitoring
- Day-night detection via LDR
- Motion sensing with PIR sensor
- Control over LED, Fan, and Alarm using relays
- Live status indicators on mobile app

**Components Used:**
- Arduino Nano
- LDR, PIR, LM35 (Thermistor)
- Bluetooth Module (HC-05)
- Relay Module
- Solar panel with AC-DC converter backup

---

**Slide 2: App & Code Integration**

**Image:** ![App UI](userinterfacelight.jpg)

**App Functionality:**
- Bluetooth connection control
- Toggle between Auto and Manual modes
- Manual ON/OFF switches for LED, Fan, Alarm
- Live status LEDs for device states
- Real-time temperature display

**Arduino Code Logic Highlights:**
- Reads LDR, PIR, and temperature values
- Auto Mode:
  - LED ON when dark + motion
  - Fan ON when motion + temp > 27°C
  - Alarm ON when temp > 100°C
- Manual Mode:
  - App toggles each device
- Sends live status & temperature to app via Bluetooth

