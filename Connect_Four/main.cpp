#include <iostream>
#include <vector>
#include <string>
#include <map>

std::vector<std::string> split(const std::string& s, const char delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = s.find(delimiter);

    tokens.push_back(s.substr(start, end - start));
    start = end + 1;
    tokens.push_back(s.substr(start));

    return tokens;
}

bool checkDirection(const std::vector<std::vector<std::string>>& grid, int row, int col, int dx, int dy, const std::string& color) {
    for (int i = 0; i < 4; ++i) {
        int r = row + i * dy;
        int c = col + i * dx;
        if (r < 0 || r >= 6 || c < 0 || c >= 7 || grid[r][c] != color) {
            return false;
        }
    }
    return true;
}

bool isWinner(const std::vector<std::vector<std::string>>& grid, int row, int col, const std::string& color) {
    return checkDirection(grid, row, col, 1, 0, color) ||    // horizontal →
           checkDirection(grid, row, col, 0, 1, color) ||    // vertical ↓
           checkDirection(grid, row, col, 1, 1, color) ||    // diagonal ↘
           checkDirection(grid, row, col, -1, 1, color) ||    // diagonal <-
           checkDirection(grid, row, col, -1, -1, color) ||    // diagonal <-
           checkDirection(grid, row, col, 1, -1, color);     // diagonal ↗
}

std::string who_is_winner(std::vector<std::string> pieces_position_list)
{
    std::map<char, int> columnMap = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}};
    std::vector<std::vector<std::string>> grid(6, std::vector<std::string>(7, ""));

    // Track the height of each column (bottom to top)
    std::vector<int> heights(7, 0);

    for (const std::string& piece : pieces_position_list) {
        auto tokens = split(piece, '_');
        int col = columnMap[tokens[0][0]];
        std::string color = tokens[1];
        int row = 5 - heights[col];  // Fill from bottom up

        if (row < 0 || row >= 6) continue;  // Safety check

        grid[row][col] = color;
        heights[col]++;

        if (isWinner(grid, row, col, color)) {
            return color;
        }
    }

    return "Draw";
}


int main() {
    std::vector<std::string> test = {
       "A_Yellow",
        "B_Red",
        "B_Yellow",
        "C_Red",
        "G_Yellow",
        "C_Red",
        "C_Yellow",
        "D_Red",
        "G_Yellow",
        "D_Red",
        "G_Yellow",
        "D_Red",
        "F_Yellow",
        "E_Red",
        "D_Yellow"
    };

    std::cout << "Result:" << who_is_winner(test) << std::endl;

    return 0;
}