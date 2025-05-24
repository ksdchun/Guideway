# Guideway

**YOLO Object Detection with Arduino Control & Region Creator Tool**

---

## Table of Contents

1. Project Overview  
2. Components  
3. Prerequisites  
4. Installation  
5. Environment Setup  
6. Configuration  
7. Configuration Reference  
8. Usage  
   - Region Creator Tool  
   - YOLO + Arduino GUI  
9. Directory Structure  
10. Troubleshooting & FAQ 

---

## Project Overview

Guideway combines:

- A **Region Creator** GUI to define polygonal ROIs (regions of interest) over a live webcam feed and save them as `regions.json`.  
- A **YOLO + Arduino** GUI that:
  1. Loads your ROI masks.  
  2. Runs real‐time YOLO object detection (via [ultralytics](https://github.com/ultralytics/ultralytics)).  
  3. Sends start/stop/speed commands to an Arduino motor system on detection events.  
  4. Supports video recording, screenshots, auto‐resume, and configuration persistence.

---

## Components

- **region_creator.py**  
- **yolo11n_arduino.py**  
- **gui_config.json**  
- **regions.json**  
- **YOLO11n.pt** 

---

## Prerequisites

- Python 3.8+  
- pip  
- A webcam  
- Arduino connected via USB  
- OS-specific GUI support (Tkinter)

---

## Installation

1. Clone this repo:
   ```bash
   git clone https://github.com/yourusername/Guideway.git
   cd Guideway
   ```
2. Create a virtual environment and install dependencies:
   ```bash
   python3 -m venv venv
   source venv/bin/activate
   pip install -r requirements.txt
   ```

---

## Environment Setup

Use the provided `requirements.txt` for reproducible installs:
```bash
pip install -r requirements.txt
```

---

## Configuration

- **`gui_config.json`**  
  ```json
  {
    "model_path": "YOLO11n.pt",
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

---

## Configuration Reference

| Setting             | Description                                         | Default       |
|---------------------|-----------------------------------------------------|---------------|
| model_path          | Path to YOLO weights (`.pt` file)                   | YOLO11n.pt    |
| conf_threshold      | YOLO confidence cutoff (0.0–1.0)                    | 0.45          |
| region_json_path    | Path to ROI definitions JSON                        | regions.json  |
| mask_threshold      | Binary threshold for mask creation                  | 127           |
| mask_max_value      | Max value for binary mask                           | 255           |
| overlap_threshold   | Min ROI overlap fraction (0.0–1.0)                  | 0.1           |
| serial_port         | Arduino serial port                                 | COM4 |
| baud_rate           | Baud rate for serial communication                  | 9600          |
| motor_speed         | Default PWM speed for motor (0–255)                 | 255           |
| recordings_dir      | Directory for saved MP4 recordings                  | recordings    |
| screenshots_dir     | Directory for saved JPG screenshots                 | screenshots   |
| auto_screenshot     | Toggle auto‐capture on detection                    | true          |

---

## Usage

### Region Creator Tool

```bash
python region_creator.py
```

See [README_region_creator.md](README_region_creator.md).

### YOLO + Arduino GUI

```bash
python yolo11n_arduino.py
```

See [README_yolo11n_arduino.md](README_yolo11n_arduino.md).

---

## Directory Structure

```
Guideway/
├── gui_config.json
├── requirements.txt
├── region_creator.py
├── regions.json
├── YOLO11n.pt
├── recordings/           # created at runtime
├── screenshots/          # created at runtime
├── yolo11n_arduino.py
├── README.md
├── README_region_creator.md
└── README_yolo11n_arduino.md
```

---

## Troubleshooting & FAQ

| Issue                         | Solution                                                                                 |
|-------------------------------|------------------------------------------------------------------------------------------|
| Webcam not detected           | Ensure webcam is connected and not in use by other apps.    |
| Serial port busy or missing   | Close other serial monitors; verify `serial_port` matches your Arduino device.          |
| YOLO model load error         | Confirm `model_path` points to a valid `.pt` file. Reinstall `ultralytics` if needed.    |
| No ROI models found           | Use `python region_creator.py` to create at least one mask model in `regions.json`.      |
| GUI unresponsive              | Check console logs for exceptions, update Python/Tkinter, try reinstalling dependencies.  |
