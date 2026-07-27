# Power Mode Manager

A lightweight, high-performance Windows Power Mode Manager written in native C++. It provides an intuitive terminal user interface (TUI) to easily toggle between Windows power plans (High Performance, Balanced, Power Saver, and Custom profiles).

## Features

- **Native C++ Performance**: Fast, lightweight execution without runtime overhead.
- **Modern Console TUI**: Built with clean box-drawing characters and ANSI color support.
- **Instant Toggling**: Switch between power profiles effortlessly.
- **Native Notifications**: Displays Windows notification toasts on power plan changes.
- **Theme Support**: Customizable color schemes for the terminal interface.
- **Easy Build Process**: Includes simple build scripts supporting CMake and Zig compiler toolchains.

## Build Instructions

1. Ensure a C++ compiler or CMake build environment is set up.
2. Run `build.bat` in the project root to compile the executable.

## Keyboard Shortcuts

- `Up/Down` or `Tab`: Navigate buttons
- `Enter`: Select option
- `T`: Toggle theme
- `Esc`: Exit application

## Architecture

- **`src/main.cpp`**: Entry point for initializing console settings and starting the UI loop.
- **`src/UI.cpp`**: Terminal UI implementation, handling layout rendering and keyboard inputs.
- **`src/PowerManager.cpp`**: Interfaces with `powrprof.dll` via Windows API to query and set active power schemes.
- **`src/NotificationManager.cpp`**: Displays system notifications when power plans are switched.
- **`src/ThemeManager.cpp`**: Manages UI color themes and styling.

> **Note**: For custom profiles, ensure the profile GUID is configured accordingly.

## License

MIT License

