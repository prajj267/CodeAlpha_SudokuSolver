# CodeAlpha_SudokuSolver
A GUI-based Sudoku solver in C++ using SFML
# 🧩 SudokuSolver

A GUI-based Sudoku solver built in C++ using [SFML](https://www.sfml-dev.org/).  
Users can input puzzles, visualize the solving process, and interact with the grid in a clean graphical interface.

---


## 🚀 Features

- Graphical 9x9 Sudoku grid using SFML
- Manual puzzle input via mouse and keyboard
- Real-time visual solving with backtracking
- Input validation and clear visual feedback
- Clean and beginner-friendly C++ source code

---

## 🔧 Requirements

- C++ compiler (e.g. `g++` via MinGW or MSVC)
- [SFML 2.5.1](https://www.sfml-dev.org/download.php)
- `arial.ttf` font (included in `fonts/` folder)

---

## 🛠️ Build Instructions (Windows + g++)

1. Install [SFML 2.5.1](https://www.sfml-dev.org/download.php)
2. Navigate to the project folder:

cd path/to/SudokuSolver


Compile Using the following command

g++ src/sudoku_gui.cpp -o sudoku.exe -I"path/to/SFML/include" -L"path/to/SFML/lib" -lsfml-graphics -lsfml-window -lsfml-system

Copy required SFML DLLs into the same folder as sudoku.exe:

sfml-graphics-2.dll

sfml-window-2.dll

sfml-system-2.dll

Run:

sudoku.exe

 How to Use
Click on a cell and type a number (1–9)

Press Enter or click Solve (if implemented) to begin solving

Watch the backtracking algorithm visualize the process

Press Escape or close the window to exit

🧠 Concepts Used
Backtracking algorithm

2D arrays for grid representation

SFML for GUI rendering and event handling

Input validation and state management

🙌 Acknowledgements
SFML — Simple and Fast Multimedia Library

Sudoku logic based on classic backtracking.

End of README.






