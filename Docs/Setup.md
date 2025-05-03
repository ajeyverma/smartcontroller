<h3>⚡ Power Supply Setup</h3>
<p>
  If using <strong>solar power</strong>, connect the solar panel to a <strong>charge controller</strong> and use a <strong>voltage regulator</strong> (e.g., AMS1117 or 7805) to provide a stable 5V output for the Arduino and components.
</p>
<p>
  For <strong>backup power</strong>, connect an <strong>AC-DC adapter</strong> (5V output) that automatically takes over when solar input is low or unavailable. Ensure proper power isolation if needed.
</p>

<h3>🧩 Wiring Notes</h3>
<p>Ensure all components share a <strong>common ground</strong> with the Arduino. Here's how to wire each module:</p>

<h4>🔆 LDR (Light Sensor)</h4>
<p>
  Use a voltage divider with a 10kΩ resistor. Connect:
</p>
<ul>
  <li><code>5V → LDR → Junction</code></li>
  <li><code>Junction → 10kΩ Resistor → GND</code></li>
  <li><code>Junction → D2 (LDR_PIN)</code></li>
</ul>
<p>
  This setup lets D2 read <strong>LOW when dark</strong> and <strong>HIGH when bright</strong>.
</p>

<h4>🌡️ LM35 Temperature Sensor</h4>
<ul>
  <li><code>LM35 VCC → 5V</code></li>
  <li><code>LM35 GND → GND</code></li>
  <li><code>LM35 OUT → A3 (THERMISTOR_PIN)</code></li>
</ul>
<p>
  LM35 outputs 10mV/°C. For example, 27°C = ~0.27V.
</p>

<h4>🚶 PIR Motion Sensor</h4>
<ul>
  <li><code>PIR VCC → 5V</code></li>
  <li><code>PIR GND → GND</code></li>
  <li><code>PIR OUT → D4 (PIR_PIN)</code></li>
</ul>
<p>
  Use “H” jumper mode on the PIR for continuous signal while motion persists.
</p>

<h4>🔌 Relays (LED, Fan, Alarm)</h4>
<ul>
  <li><code>Relay IN1 → D8 (LED_RELAY_PIN)</code></li>
  <li><code>Relay IN2 → D9 (FAN_RELAY_PIN)</code></li>
  <li><code>Relay IN3 → D10 (ALARM_RELAY_PIN)</code></li>
  <li><code>Relay VCC → 5V</code>, <code>GND → GND</code></li>
</ul>
<p>
  Connect your high-voltage devices (e.g., bulb, fan, buzzer) to the <strong>NO (Normally Open)</strong> and <strong>COM</strong> terminals.
</p>

<h4>📶 HC-05 Bluetooth Module</h4>
<ul>
  <li><code>HC-05 TX → D6 (Arduino RX via SoftwareSerial)</code></li>
  <li><code>HC-05 RX → Voltage Divider → D7 (Arduino TX)</code></li>
  <li><code>VCC → 5V</code>, <code>GND → GND</code></li>
</ul>

<p><strong>Voltage Divider for HC-05 RX (to drop 5V TX signal to ~3.3V):</strong></p>
<pre>
Arduino TX --- 1kΩ ---+--- 2kΩ --- GND
                      |
                   HC-05 RX
</pre>

<p>
  This prevents damage to the HC-05's 3.3V logic input pin.
</p>

## 🔌 Pin Connections

<table border="1" cellspacing="0" cellpadding="8">
  <thead>
    <tr>
      <th>Component</th>
      <th>Arduino Pin</th>
      <th>Notes</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>LDR</td>
      <td>D2 (Digital)</td>
      <td>Use with voltage divider; LOW when dark</td>
    </tr>
    <tr>
      <td>LM35 Temperature Sensor</td>
      <td>A3 (Analog)</td>
      <td>Middle pin to A3; VCC & GND to 5V/GND</td>
    </tr>
    <tr>
      <td>PIR Motion Sensor</td>
      <td>D4 (Digital)</td>
      <td>OUT to D4; requires 5V and GND</td>
    </tr>
    <tr>
      <td>Relay (LED)</td>
      <td>D8</td>
      <td>IN pin of relay module</td>
    </tr>
    <tr>
      <td>Relay (Fan)</td>
      <td>D9</td>
      <td>IN pin of relay module</td>
    </tr>
    <tr>
      <td>Relay (Alarm)</td>
      <td>D10</td>
      <td>IN pin of relay module</td>
    </tr>
    <tr>
      <td>Bluetooth HC-05</td>
      <td>D6 (RX), D7 (TX)</td>
      <td>Use voltage divider on HC-05 RX</td>
    </tr>
  </tbody>
</table>

<p><strong>Note:</strong> Connect all VCCs to 5V and all GNDs to common ground.</p>
