# YOLO + Arduino Control GUI

Real-time YOLO detection with Arduino motor control.

---

## Features

- Load ROIs from `regions.json`.
- 720p live preview with detection overlays.
- Auto-start/stop motor on object detection in ROI.
- Adjustable confidence & overlap thresholds.
- Speed slider to set motor PWM (0–255).
- Video recording (MP4) & screenshots (JPG).
- Auto-resume and auto-screenshot options.
- Persistent GUI settings in `gui_config.json`.

---

## Dependencies

```bash
pip install ultralytics opencv-python numpy pyserial pillow sv_ttk
```

- [ultralytics](https://github.com/ultralytics/ultralytics)
- pyserial

---

## Configuration

Edit `gui_config.json`:

```json
{
  "model_path": "weights/YOLO11n.pt",
  "conf_threshold": 0.45,
  "region_json_path": "regions.json",
  "mask_threshold": 127,
  "mask_max_value": 255,
  "overlap_threshold": 0.1,
  "serial_port": "COM4",
  "baud_rate": 9600,
  "motor_speed": 255,
  "recordings_dir": "recordings",
  "screenshots_dir": "screenshots",
  "auto_screenshot": true
}
```

### Configuration Parameters

| Parameter           | Description                                                     | Default                 |
|---------------------|-----------------------------------------------------------------|-------------------------|
| model_path          | Path to YOLO `.pt` weights file                                 | weights/YOLO11n.pt      |
| conf_threshold      | Confidence threshold for detections (0.0–1.0)                   | 0.45                    |
| region_json_path    | Path to ROI definitions JSON file                               | regions.json            |
| mask_threshold      | Grayscale threshold for mask binarization (0–255)               | 127                     |
| mask_max_value      | Maximum value for binary mask pixels (0–255)                    | 255                     |
| overlap_threshold   | Minimum fraction of detection box overlap with ROI (0.0–1.0)    | 0.1                     |
| serial_port         | Serial port for Arduino (e.g., `COM4`)         | COM4                    |
| baud_rate           | Baud rate for serial communication                              | 9600                    |
| motor_speed         | Default PWM speed for motor control (0–255)                     | 255                     |
| recordings_dir      | Directory path where MP4 recordings are saved                   | recordings              |
| screenshots_dir     | Directory path where JPG screenshots are saved                  | screenshots             |
| auto_screenshot     | Enable automatic screenshots on detection (`true`/`false`)       | true                    |

---

## GUI Controls

- **Mask Model**: select which ROI mask to use.
- **Overlay**: toggle semi-transparent ROI overlay on/off.
- **Preview**: toggle detection preview without motor/motor stop.
- **Confidence Threshold**: slider (0.0–1.0) to set YOLO confidence cutoff.
- **Overlap Threshold**: slider (0.0–1.0) to set minimum ROI overlap for detection.
- **Motor Speed**: slider (0–255) to adjust PWM speed sent to Arduino.
- **Auto Resume**: checkbox to re-enable detection and motor after object leaves ROI.
- **Auto Screenshot**: checkbox to take automatic screenshots on detection.
- **Recording**: Start/Stop Recording buttons to capture MP4 video.

---

## Running

```bash
python yolo11n_arduino.py
```

1. Select ROI model from dropdown.
2. **Start** begins detection + Arduino run command.
3. **Pause** on detection (can auto-resume).
4. **Stop** halts motor and detection.
5. Adjust **Speed** and toggle **Record** / **Screenshot**.

---

## Arduino Protocol

- Sends ASCII commands:
  - `"1:<speed>\n"` → start motor at `<speed>`
  - `"0:0\n"` → stop motor

Implement matching listener on Arduino side (Serial.readString).

---

## Logs & Outputs

- Info printed to console.
- Recordings saved under `recordings/`.
- Screenshots under `screenshots/`.

---

## Troubleshooting

- **Serial Timeout**: ensure correct `serial_port`.
- **Model Load Error**: check `model_path` and weights file.
- **Low FPS**: reduce window size or ROI complexity.
