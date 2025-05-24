# Region Creator Tool

A GUI to draw and manage polygonal Regions of Interest (ROIs) for Guideway.

---

## Features

- Define multiple **masks** (models), each containing a region.
- Draw free-form polygons over live webcam feed.
- Undo/redo editing steps.
- Rename/delete regions and masks.
- Saves output to `regions.json` for downstream use.

---

## Dependencies

- Python 3.8+
- tkinter
- sv_ttk
- opencv-python
- Pillow

Install via:

```bash
pip install opencv-python pillow sv_ttk
```

---

## Running

```bash
python region_creator.py
```
---

## User Interface

### Model Management
- **Mask Name** dropdown: select which mask model to edit.
- **New Mask...**: create a new mask model.
- **Rename Mask**: rename the current mask model.
- **Delete Mask**: delete the selected mask model and its regions.

### Region Controls
- **Region** list: shows a region for the current mask.
- **Region Info**: displays point count and coordinates of the selected region.
- **Add Region**: enter draw mode to add a new polygon region.
  - Click on the canvas to add vertices.
- **Finish Region**: save the drawn polygon as a new region.
- **Delete Region**: remove the selected region.
- **Clear All Regions**: remove all regions from the current mask.
- **Save and Close**: save all changes to `regions.json` and exit.

### Canvas Interaction
- Displays live webcam feed as background for drawing.
- Click on an existing region to select and highlight it.
- In draw mode, each click adds a vertex; lines connect points in real time.

## Output Schema (`regions.json`)

```json
{
  "model-1": {
    "regions": {
      "region-1": [[x1, y1], [x2, y2], ...],
      "region-2": [ ... ]
    }
  },
  "model-2": { … }
}
```

---

## Tips

- Resize the window as needed for better drawing experience.
- `regions.json` is human-readable; preview with any text editor.
