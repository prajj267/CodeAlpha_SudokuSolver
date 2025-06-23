#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const int SIZE = 9;
const int CELL_SIZE = 60;
int grid[SIZE][SIZE] = {0};
bool original[SIZE][SIZE] = {false};

bool isValid(int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (grid[i][j] == num)
                return false;
        }
    }
    return true;
}

bool solveSudoku() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku())
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void resetGrid() {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (!original[i][j])
                grid[i][j] = 0;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(SIZE * CELL_SIZE, SIZE * CELL_SIZE + 80), "Sudoku Solver");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Font not found!\n";
        return 1;
    }

    int selectedRow = 0, selectedCol = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Mouse Click
            if (event.type == sf::Event::MouseButtonPressed) {
                int x = event.mouseButton.x / CELL_SIZE;
                int y = event.mouseButton.y / CELL_SIZE;
                if (x < SIZE && y < SIZE) {
                    selectedCol = x;
                    selectedRow = y;
                }
            }

            // Keyboard Input
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode >= '1' && event.text.unicode <= '9') {
                    int num = event.text.unicode - '0';
                    grid[selectedRow][selectedCol] = num;
                    original[selectedRow][selectedCol] = true;
                } else if (event.text.unicode == '0' || event.text.unicode == 8) {
                    grid[selectedRow][selectedCol] = 0;
                    original[selectedRow][selectedCol] = false;
                }
            }

            // Solve with 'S'
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                solveSudoku();
            }

            // Clear with 'C'
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C) {
                resetGrid();
            }
        }

        // Draw
        window.clear(sf::Color::White);

        // Draw cells
        for (int i = 0; i <= SIZE; i++) {
            sf::RectangleShape line(sf::Vector2f(SIZE * CELL_SIZE, i % 3 == 0 ? 4 : 1));
            line.setFillColor(sf::Color::Black);
            line.setPosition(0, i * CELL_SIZE);
            window.draw(line);
            line.setSize(sf::Vector2f(i % 3 == 0 ? 4 : 1, SIZE * CELL_SIZE));
            line.setPosition(i * CELL_SIZE, 0);
            window.draw(line);
        }

        // Draw numbers
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (grid[row][col] != 0) {
                    sf::Text text;
                    text.setFont(font);
                    text.setString(std::to_string(grid[row][col]));
                    text.setCharacterSize(30);
                    text.setFillColor(original[row][col] ? sf::Color::Black : sf::Color::Blue);
                    text.setPosition(col * CELL_SIZE + 20, row * CELL_SIZE + 10);
                    window.draw(text);
                }
            }
        }

        window.display();
    }

    return 0;
}
