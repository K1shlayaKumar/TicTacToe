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
    char values[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    // We draw the numbered board ONCE before the game loop starts
    drawGrid(values);

    // Game always starts with X first
    char currentPlayer = 'X';

    // The Main Game Loop
    for (int turn = 0; turn < 9; turn++) {
        int input;
        bool validMove = false; 

        //Get the input FIRST
        while (validMove == false) {
            std::cout << "Player " << currentPlayer << ", type a number (1-9): ";
            std::cin >> input;

            // We want an input between 1 and 9 and it also shouldn't be square that's already taken 
            if (input >= 1 && input <= 9 && values[input - 1] != 'X' && values[input - 1] != 'O') {
                values[input - 1] = currentPlayer; 
                validMove = true;                  
            } else {
                std::cout << "Invalid move or spot already taken! Try again.\n";
            }
        }

        //The Board Wipe (Happens AFTER they successfully make their first move)
        if (turn == 0) {
            for (int i = 0; i < 9; i++) {
                if (values[i] != 'X' && values[i] != 'O') {
                    values[i] = ' '; // Wipe the remaining numbers
                }
            }
        }

        //Clear the terminal and draw the newly updated board
        system("clear");
        drawGrid(values);

        //Swap the player
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    return 0;
}