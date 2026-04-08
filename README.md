# Arduino Melody Player with LED Light Show

## Circuit Diagram

![Circuit Diagram](Lightshow.png)

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
  A3, REST, E4, REST,
  REST, REST, A3, REST, 
  REST, E4, REST, REST, 
  C4, REST, E4, REST, 
  G4, B3, REST, REST,
  E4, REST, REST
};

// Duration of each note: treating every step as an equal 16th note on a grid
int noteDurations[] = {
  16, 16, 16, 16, 
  16, 16, 16, 16, 
  16, 16, 16, 16, 
  16, 16, 16, 16, 
  16, 16, 16, 16, 
  16, 16, 16
};
```

Both arrays must be the same length.
Note duration is calculated as `1905 / value` (to achieve Calabria 2007's 126 BPM), so a `16` gives roughly a 119ms note step.
To speed up or slow down the overall tempo of the song, change the `1905` base number.

---

## Dependencies

No external libraries required.

---

## License

MIT — feel free to use and modify.
