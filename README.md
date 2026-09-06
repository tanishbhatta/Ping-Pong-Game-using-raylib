# 🏓 Pong — C++ & raylib

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![raylib](https://img.shields.io/badge/raylib-FFC229?style=for-the-badge&logo=raylib&logoColor=black)
![License](https://img.shields.io/badge/license-MIT-green?style=for-the-badge)

A classic Pong clone built from scratch in C++ using [raylib](https://www.raylib.com/) — real-time paddle physics, ball collision, and score tracking in a lightweight 2D game loop.

---

## Features

- Two-paddle player vs player gameplay
- Real-time ball physics with wall and paddle collision
- Score tracking and win condition
- Simple, readable game loop — update → collision → render
- Minimal dependencies — just raylib

---

## Tech Stack

| Layer | Tool |
|---|---|
| Language | C++ |
| Graphics / Input | raylib |
| Build | g++ / CMake |

---

## Preview

_Add a screenshot or GIF of gameplay here._

---

## Getting Started

### Prerequisites

- A C++ compiler (g++ or clang)
- [raylib](https://github.com/raysan5/raylib) installed on your system

### Clone the repo

```bash
git clone https://github.com/tanishbhatta/ping-pong-game-using-raylib.git
cd ping-pong-game-using-raylib
```

### Compile

```bash
g++ main.cpp -o pong -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

### Run

```bash
./pong
```

> Adjust the compile flags depending on your OS (Linux/macOS/Windows) and how raylib is installed.

---

## Controls

| Player   |Move Up|Move Down|
|---|---|--|
| Computer | `N/A` | `N/A`   |
| Player 2 |  `↑`  |  `↓`    |

---

## Project Structure

```
.
├── main.cpp          # Game loop, input, rendering
├── ball.h / .cpp      # Ball physics & collision
├── paddle.h / .cpp    # Paddle movement & bounds
└── README.md
```

---

## Roadmap

- [ ] AI opponent (single-player mode)
- [ ] Sound effects on collision/score
- [ ] Adjustable ball speed / difficulty
- [ ] Main menu & pause screen

---

## License

This project is licensed under the [MIT License](LICENSE).

---

## Acknowledgments

- [raylib](https://www.raylib.com/) — simple and easy-to-use game programming library
