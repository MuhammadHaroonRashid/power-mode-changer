# Power Mode Manager

A beautiful, professional Windows Power Mode Manager built with Python, Textual, and ctypes. It provides a gorgeous terminal user interface (TUI) to easily toggle between Windows power plans without navigating through multiple setting menus.

## Features

- **Modern TUI**: Designed using the `textual` framework with rounded borders and responsive layouts.
- **Instant Toggling**: Switch between High Performance and Custom plans with one click.
- **Native Notifications**: Shows native Windows 10/11 toast notifications when a plan is switched.
- **Theme Support**: Includes multiple themes (Dark, Blue, Green, Amber).
- **Auto-Elevation**: Automatically requests Administrator privileges if required.
- **Standalone Executable**: Packages into a single `.exe` using PyInstaller.

## Build Instructions

1. Ensure Python 3.8+ is installed.
2. Run `build.bat` in the project root.
3. The standalone executable will be generated in the `dist` folder (`dist\PowerModeManager.exe`).

## Keyboard Shortcuts

- `Up/Down` or `Tab`: Navigate buttons
- `Enter`: Select option
- `T`: Toggle theme
- `Esc`: Exit application

## Architecture

- **`main.py`**: Handles checking for Administrator elevation and starting the application.
- **`app_ui.py`**: The main Textual UI implementation, providing the visual layout and handling input events.
- **`power_manager.py`**: Uses `ctypes` to interface with `powrprof.dll`, making fast and robust calls to the Windows power management APIs.
- **`notification_manager.py`**: Leverages `windows-toasts` to issue native toast notifications to the user.
you have to create a manual power profile and provide its GUId in the code.

## License

MIT License
