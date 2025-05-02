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
