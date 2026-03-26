# Arduino Melody Player with LED Light Show


## How It Works

When the button is pressed, the sketch plays a short melody one note at a time. For each non-rest note, a randomly selected LED lights up for the duration of the note.

---

## Files

| File | Description |
|------|-------------|
| `sketch_pitchtest.ino` | Main Arduino sketch — melody, LED logic, and button input |
| `pitches.h` | Frequency definitions for notes B0 through DS8 |

---


## Customizing the Melody

Edit the two arrays in `sketch_pitchtest.ino`:

```cpp
// The notes to play — use constants from pitches.h, or REST for silence
int melody[] = {
  D4, A4, REST, D4, A4, F4, A4, AS4, A4
};

// Duration of each note: 4 = quarter note, 8 = eighth note, etc.
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4
};
```

Both arrays must be the same length. Note duration is calculated as `1000 / value`, so a `4` gives a 250ms note, an `8` gives 125ms, and so on.

---

## Dependencies

No external libraries required.

---

## License

MIT — feel free to use and modify.
