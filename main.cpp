#include <iostream>
#include <cstdlib> 

    void drawGrid(char grid[]) {
    std::cout << "+---+---+---+" << std::endl;
    std::cout << "| " << grid[0] << " | " << grid[1] << " | " << grid[2] << " |" << std::endl;
    std::cout << "+---+---+---+" << std::endl;
    std::cout << "| " << grid[3] << " | " << grid[4] << " | " << grid[5] << " |" << std::endl;
    std::cout << "+---+---+---+" << std::endl;
    std::cout << "| " << grid[6] << " | " << grid[7] << " | " << grid[8] << " |" << std::endl;
    std::cout << "+---+---+---+" << std::endl;
    }

int main() {
    system("clear");
    char values[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    drawGrid(values);

    // To keep switching between X and O
    char currentPlayer = 'X';

    // The Main Game Loop
    for (int turn = 0; turn < 9; turn++) {
        int input;
        bool validMove = false; // Reset to false at the start of every turn


        while (validMove == false) {
            std::cout << "Player " << currentPlayer << ", type a number (1-9): ";
            std::cin >> input;

            // Check 1: Is it between 1 and 9?
            // Check 2: Is that exact spot still an empty space?
            if (input >= 1 && input <= 9 && values[input - 1] == ' ') {
                values[input - 1] = currentPlayer; // Claim the spot
                validMove = true;                  // Break out of the trap!
            } else {
                std::cout << "Invalid move or spot already taken! Try again.\n";
            }
        }

        // Clear and redraw
        system("clear");
        drawGrid(values);

        // Swap the player
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    return 0;
}