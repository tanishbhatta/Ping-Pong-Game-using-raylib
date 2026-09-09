# Terminal Pong (C++)

A playable Pong that runs entirely in the console — no graphics library, no game engine, no window. The board is a 40×20 character grid printed to the terminal each frame; you play one paddle against a simple AI.

> **On the name:** this repo is `Ping-Pong-Game-using-raylib`, but there's no raylib here — the name is a holdover from an earlier plan. Rendering is plain terminal ASCII.

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-6EE7F7?style=flat-square&logo=cplusplus&logoColor=black" />
  <img src="https://img.shields.io/badge/Windows_only-6EE7F7?style=flat-square&logo=windows&logoColor=black" />
  <img src="https://img.shields.io/badge/No_engine_·_terminal_ASCII-6EE7F7?style=flat-square" />
</p>

## Play

Move your paddle up and down; the opponent is a basic reaction-lagged AI. Input is real-time and non-blocking — you don't press Enter, the game reads keys as you hold them.

**Windows only.** It relies on `<conio.h>`, `<windows.h>`, and `system("cls")`, none of which exist on Linux/macOS as-is.

## Build & run

Compile with g++ (MinGW):

```bash
g++ main.cpp -o pong.exe -static
```

The `-static` flag matters: without it the `.exe` fails to launch on machines that don't have MinGW's `libwinpthread-1.dll` on hand (found this out the hard way — it wouldn't run on a friend's PC). Static linking bundles the runtime so the binary is self-contained. Then:

```bash
./pong.exe
```

*(Adjust `main.cpp` to your actual source filename.)*

## What it's built with

Pure C++ standard library plus two Windows-specific headers:

- **`<conio.h>`** — non-blocking keyboard input (`_kbhit()`, `_getch()`), so the game reads held keys without waiting on Enter.
- **`<windows.h>`** — originally planned for cursor repositioning to cut flicker, but that approach was abandoned; it's currently unused.
- **`<thread>` / `<chrono>`** — frame pacing via `sleep_for(50ms)`, i.e. a fixed ~20 FPS. No delta-time computation needed.

Rendering is terminal-based: a 40×20 character grid printed each frame with nested `for` loops, cleared between frames with `system("cls")`.

## Design

Three classes, each holding private state with constructors, getters, and behavior methods:

| Class | State + behavior |
|---|---|
| `Paddle` | position; `moveUp()`, `moveDown()` |
| `Ball` | position + velocity; `move()`, `bounceX()`, `bounceY()`, `reset()` |
| `Screen` | grid dimensions; `getWidth()`, `getHeight()` |

**Why OOP here:** this was my first OOP project, picked deliberately because Pong maps cleanly onto objects — each entity has its own state and behavior. I went straight to classes to learn them, rather than writing it procedurally first and hitting a wall. That said, the fit is real: each entity's state evolves independently every frame, and packing "position + how it moves + how it bounces" into one class beats threading loose `int ballX, ballY, velX, velY` through every function.

## What actually broke

The honest, unglamorous list — this is where the time went:

- **Render condition logic** — the biggest sustained fight. The per-cell decision chain (paddle span vs. edge vs. ball position) took several passes: off-by-one `-1` adjustments that weren't needed, `||` where I meant `&&`, and mixing up `getX()`/`getY()` semantics.
- **Held-key input lag** — `_kbhit()` inside an `if` pulled only one key per frame, so a held key backed up in the queue and felt sluggish. Fix: `while (_kbhit())` to drain the buffer every frame.
- **Frame-skip AI tuning** — added `frameCount % N` to give the AI reaction lag, but kept regressing it to `% 1` (no skip at all) during copy-paste passes without noticing.
- **AI dead-zone comparison bug** — wrote `diff < 3` instead of `diff < -3`, which made the paddle drift downward almost unconditionally.
- **Brace / structure tangles** — nested `while` loops with inner `if` blocks got mismatched at least twice: once a `return 0;` landed inside the game loop (program exited after one frame), once the structure got corrupted while adding the border.
- **DLL portability** — see the `-static` note above.

## What *didn't* break

Worth noting, since it shaped what the project taught me:

- **Physics** was straightforward once rendering settled — bouncing is just `vel *= -1`, no vectors, floats, or trig.
- **Frame timing** was a solved problem with `sleep_for` — no delta-time math.
- **No pointer bugs** — everything is stack-allocated by design; no `new`/`delete` yet.
- **Flicker** is cosmetic. After briefly touching the Windows Console API, I chose not to keep fighting it.
