# C++ Data Structures and Algorithms Submodule

This submodule is part of the key data structures and algorithms collection, implemented using Modern C++ (leveraging features from both C++20 and C++23). It demonstrates my own implementations of various data structures and algorithms, built with a focus on clarity, efficiency, and modern design practices.

---

## Overview

Utilizing the latest features of Modern C++, including modules, this project provides a well-organized library of data structures and algorithms. The code is structured to clearly separate the public interfaces from the private implementations, ensuring maintainability and ease of use.

---

## Folder Structure

- **modules/include**  
  Contains the public section of the library where the unit interface modules are defined. These headers provide the API that users can include in their own projects.

- **modules/src**  
  Houses the private implementations of the modules, where the actual code for the data structures and algorithms is maintained.

---

## Build Instructions

This project uses CMake along with C++ Modules (C++20 and C++23) to build the library. To build the project, follow these steps:

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

Ensure you have a C++23 compliant compiler installed.

*Note:* You can also choose your own CMake preset during the build process by specifying it in your commands (e.g., using `cmake --preset <preset-name>` if you have defined custom presets in your `CMakePresets.json` or `CMakeUserPresets.json` file).

---

## Usage Rights

The code is published in the spirit of free education. **Please do not use this code directly for academic assignments or professional projects.** Instead, let these implementations serve as inspiration for developing your own solutions.

---

## Feedback and Contributions

If you have any questions, suggestions, or feedback, please feel free to reach out or open an issue in the repository. Your input is greatly appreciated!

---

&copy; 2025 by Amir Nourinia