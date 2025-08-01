# Crackme Programs

This repository contains three small C++ programs for practice with reverse engineering. Each program asks for a username and password and grants access when the correct combination is provided.

## Levels

- **lite** – straightforward check.
- **simple** – obfuscated password check.
- **strong** – includes anti-debugging and checksum verification.

The valid credentials for each level are `admin` and `12345:<level>` where `<level>` is `lite`, `simple`, or `strong`.

## Building

### Ubuntu

Use `g++` with C++17 support:

```bash
cd <level>
g++ -std=c++17 -O2 main.cpp -o crackme
```

### Windows

With Visual Studio developer command prompt:

```cmd
cd <level>
cl /EHsc /std:c++17 main.cpp
```

Or with MinGW:

```cmd
cd <level>
g++ -std=c++17 -O2 main.cpp -o crackme.exe
```

## Running

Execute the built binary and enter the requested credentials. The programs exit with "Access granted" when the input matches the expected values.
