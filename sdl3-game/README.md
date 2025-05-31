# SDL3 Game Project

## Overview
This project is a simple video game developed without a game engine, utilizing SDL3 for graphics and window management. The game is designed to be cross-platform, compatible with Linux, macOS, and Windows, and will also have a version compiled in WebAssembly.

## Project Structure
```
sdl3-game
├── src
│   ├── main.c          # Entry point of the game
│   ├── window.c        # Window management functions
│   ├── window.h        # Header for window management
│   ├── graphics.c      # Graphics rendering functions
│   ├── graphics.h      # Header for graphics functions
│   └── game.c          # Main game logic
├── include
│   └── game.h          # Header for main game functions
├── lib                 # External libraries and dependencies
├── assets              # Game assets (images, sounds, etc.)
├── build               # Build artifacts
├── web
│   └── index.html      # Entry point for the WebAssembly version
├── CMakeLists.txt      # CMake configuration file
├── Makefile            # Makefile for building the project
├── README.md           # Project documentation
└── .gitignore          # Files to ignore in version control
```

## Getting Started

### Prerequisites
- Install SDL3 on your system. Follow the instructions on the [SDL website](https://www.libsdl.org/download-2.0.php) for your platform.
- Ensure you have CMake and a compatible C/C++ compiler installed.

### Building the Project

#### Using CMake
1. Navigate to the project directory:
   ```
   cd sdl3-game
   ```
2. Create a build directory:
   ```
   mkdir build && cd build
   ```
3. Run CMake to configure the project:
   ```
   cmake ..
   ```
4. Build the project:
   ```
   cmake --build .
   ```

#### Using Makefile
1. Navigate to the project directory:
   ```
   cd sdl3-game
   ```
2. Run the Makefile to build the project:
   ```
   make
   ```

### Running the Game
After building the project, you can run the game executable generated in the `build` directory.

### WebAssembly Version
To compile the game for WebAssembly, follow the specific instructions provided in the `web` directory. Ensure you have the necessary tools for WebAssembly development.

## Contributing
Feel free to contribute to this project by submitting issues or pull requests. Your feedback and contributions are welcome!

## License
This project is licensed under the MIT License. See the LICENSE file for more details.