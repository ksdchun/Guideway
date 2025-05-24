# Arduino Speed Control Sketch

This Arduino sketch listens on serial (9600 baud) for commands in the format `"<signal>:<speed>\n"`.
It drives a motor via PWM and direction pins.

---

## Pin Connections

- **ENA** (PWM speed control) → Arduino pin 10  
- **IN1** (direction) → Arduino pin 8  
- **IN2** (direction) → Arduino pin 9  
- **Motor driver outputs** → motor terminals  
- **GND** → common ground  
- **5V** → Vcc on driver (if required)

---

## Serial Protocol

- `"1:<speed>\n"` – start motor at `<speed>` (0–255)  
- `"0:0\n"` – stop motor  

Example from Python:
```python
ser.write(f"1:{speed}\n".encode())
```

---

## Uploading the Sketch

1. Open the project folder in Arduino IDE or use Arduino CLI.  
2. Select board (e.g. **Arduino Uno**) and correct port.  
3. Sketch path: `arduino_speed_control.ino`  
4. Upload.

---

## Customization

- Change `ENA`, `IN1`, `IN2` pin definitions at the top.  
- Adjust `Serial.begin(9600)` to match your host settings.  
