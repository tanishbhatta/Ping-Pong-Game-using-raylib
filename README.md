#Pong — C++ & raylib

A classic Pong clone built from scratch in C++ using raylib — real-time paddle physics, ball collision, and score tracking in a lightweight 2D game loop.

#Features
Two-paddle player vs player gameplay
Real-time ball physics with wall and paddle collision
Score tracking and win condition
Simple, readable game loop (update → collision → render)
Minimal dependencies — just raylib
Tech Stack
Language: C++
Graphics/Input: raylib
Build: g++ / CMake

#Preview
[Image]

#Getting Started
##Prerequisites
A C++ compiler (g++ / clang)
raylib installed on your system
Build & Run
bash

# Clone the repo
`bash
git clone https://github.com/tanishbhatta/ping-pong-game-using-raylib.git
cd ping-pong-game-using-raylib
`

# Compile
`bash
g++ main.cpp -o pong -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
`
# Run
`bash
./pong
`

Adjust the compile flags depending on your OS (Linux/macOS/Windows) and how raylib is installed.

Controls
Player	Move Up	 Move Down
Computer   X	     X
Player 2   ↑	     ↓
Project Structure
.
├── main.cpp        # Game loop, input, rendering
├── ball.h / .cpp    # Ball physics & collision
├── paddle.h / .cpp  # Paddle movement & bounds
└── README.md

##Upcomming Updates
 Sound effects on collision/score
 Adjustable ball speed / difficulty
 Main menu & pause screen

##License

This project is licensed under the MIT License.

Acknowledgments
raylib — simple and easy-to-use game programming library