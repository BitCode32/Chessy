# Chessy
Chessy is a high-performance chess engine build in c.

# Introduction
This chess engine supports both human vs human, human vs AI and AI vs AI matches. The chess engine allows you to set the difficulty of the AI going from easy to very hard.

# Features
COMING SOON

# Installation
## Prerequisites
Ensure you have the following installed on your system:
* CMake (minimum version 3.10)
* A compatible c++ compiler (e.g., GCC or MSVC)

## Build Steps
1. Clone the repository:
```bash
git clone https://github.com/BitCode32/Chessy.git
```

2. Navigate to the directory:
```bash
cd Chessy
```

3. Create build directory and navigate to it:
```bash
mkdir Build && cd Build
```

4. Run CMake to configure project:
```bash
cmake ..
```

5. Build the project:
```bash
cmake --build . --config Release
```
To build in debug use:
```bash
cmake --build . 
```

## Running the engine
After building the compiled executable will typically be located in the build directory:
```bash
.\ChessyApp.exe
``` 
The library file will also be include in the same folder usually as Chessy.lib for windows or Chessy.a for linux. To use the library file you will need to copy the Chessy folder containing the header files and follow the setup process for a library in the build system you are using.  

# Usage
COMING SOON!