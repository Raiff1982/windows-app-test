# Windows App Test

## Overview
This project is a Windows application that allows users to install various software using Winget. The application is built using C++ and the Win32 API and includes a menu-driven interface for selecting software to install.

## Features
- Menu-driven interface with options to install different software.
- Error handling with informative message boxes.
- About dialog providing version information.

## Prerequisites
- Windows 10 or later.
- Winget installed and configured on the system.

## Software Installation Options
The following software can be installed using the application:
- Python
- Visual Studio Code
- Git
- Node.js
- Docker
- Java
- Notepad++

## Building the Project
1. **Clone the repository**:
    ```sh
    git clone gh repo clone Raiff1982/windows-app-test
    ```
2. **Open the solution in Visual Studio**:
    - Locate and open the `windows app test.sln` file.
3. **Build the solution**:
    - Right-click on the solution in Solution Explorer and select `Build`.
4. **Run the application**:
    - Locate the executable in the `x64\Release` or `x64\Debug` folder and run it.

## Usage
1. **Launch the application**:
    - Run `windows app test.exe`.
2. **Navigate the menu**:
    - Use the `File` menu to exit the application.
    - Use the `Help` menu to view the About dialog.
    - Use the `Install` menu to select and install software.
3. **Install software**:
    - Select the desired software from the `Install` menu.
    - Follow the on-screen prompts to complete the installation.

## Error Handling
The application includes error handling to provide informative message boxes in case of failures, such as:
- Failure to create the main window.
- Software not found in the software map.

## Code Structure
- **Main Application File**: `windows app test.cpp`
- **Header File**: `resource.h`
- **Precompiled Header**: `pch.h`

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing
Contributions are welcome! Please open an issue or submit a pull request.

## Authors
- Jonathan https://github.com/Raiff1982

## Acknowledgments
Special thanks to Microsoft Copilot for assisting in the development of this application.
