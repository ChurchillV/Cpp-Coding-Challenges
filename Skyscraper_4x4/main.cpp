#include <iostream>
#include <algorithm>

using namespace std;

constexpr int GRID_SIZE = 4;

// Check if a number can be placed in a row and column (ensuring uniqueness)
bool isValidPlacement(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    return true;
}

// Count visible skyscrapers in a row/column
int countVisible(const int *arr) {
    int maxHeight = 0, visibleCount = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        if (arr[i] > maxHeight) {
            maxHeight = arr[i];
            visibleCount++;
        }
    }
    return visibleCount;
}

// Validate all clues in the grid
bool isGridValid(int grid[GRID_SIZE][GRID_SIZE], int *clues) {
    for (int i = 0; i < GRID_SIZE; i++) {
        int row[GRID_SIZE], col[GRID_SIZE];
        for (int j = 0; j < GRID_SIZE; j++) {
            row[j] = grid[i][j];
            col[j] = grid[j][i];
        }

        // Check row clues (left to right and right to left)
        if (clues[i] != 0 && countVisible(row) != clues[i]) return false;
        reverse(row, row + GRID_SIZE);
        if (clues[GRID_SIZE + i] != 0 && countVisible(row) != clues[GRID_SIZE + i]) return false;

        // Check column clues (top to bottom and bottom to top)
        if (clues[2 * GRID_SIZE + i] != 0 && countVisible(col) != clues[2 * GRID_SIZE + i]) return false;
        reverse(col, col + GRID_SIZE);
        if (clues[3 * GRID_SIZE + i] != 0 && countVisible(col) != clues[3 * GRID_SIZE + i]) return false;
    }
    return true;
}

// Backtracking solver
bool solve(int grid[GRID_SIZE][GRID_SIZE], int *clues, int row, int col) {
    if (row == GRID_SIZE) return isGridValid(grid, clues);

    int nextRow = (col == GRID_SIZE - 1) ? row + 1 : row;
    int nextCol = (col == GRID_SIZE - 1) ? 0 : col + 1;

    for (int num = 1; num <= GRID_SIZE; num++) {
        if (isValidPlacement(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve(grid, clues, nextRow, nextCol))
                return true;
            grid[row][col] = 0;  // Backtrack
        }
    }
    return false;
}

// Main function solving the puzzle and returning the solution grid
int** SolvePuzzle(int *clues) {
    static int grid[GRID_SIZE][GRID_SIZE] = {0};
    
    if (!solve(grid, clues, 0, 0)) return nullptr; // No solution found

    // Allocate dynamic 2D array for return
    int **solution = new int*[GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        solution[i] = new int[GRID_SIZE];
        for (int j = 0; j < GRID_SIZE; j++) {
            solution[i][j] = grid[i][j];
        }
    }
    return solution;
}

// Function to print the solution
void printSolution(int** solution) {
    if (!solution) {
        cout << "No solution found!\n";
        return;
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

// Main driver
int main() {
    int clues[16] = { 0, 0, 1, 2, 
                      0, 2, 0, 0, 
                      0, 3, 0, 0, 
                      0, 1, 0, 0 };

    int **solution = SolvePuzzle(clues);
    printSolution(solution);

    // Free allocated memory
    for (int i = 0; i < GRID_SIZE; i++) delete[] solution[i];
    delete[] solution;

    return 0;
}
