#include <iostream>
#include <vector>


bool validate_battlefield(std::vector< std:: vector<int> > field) {
    const int N = 10;
    std::vector< std::vector<bool> > visited(N, std::vector<bool>(N, false));
    int ship_count[5] = {0};

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    auto is_valid = [&](int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    };

    auto has_adjacent = [&](int x, int y) {
        for(int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(is_valid(nx, ny) && field[nx][ny] == 1 && !visited[nx][ny]) return true;
        }

        return false;
    };

    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            if(field[row][col] == 1 && !visited[row][col]) {
                int length = 1;
                visited[row][col] = true;

                int r = row, c = col;

                while(is_valid(r, c + 1) && field[r][c + 1] == 1) {
                    c++;
                    length++;
                    visited[r][c] = true;
                } 

                if(length == 1) {
                    r = row;
                    c = col;
                    while(is_valid(r + 1, c) && field[r + 1][c] == 1) {
                        r++;
                        length++;
                        visited[r][c] = true;
                    }
                }

                for(int i = row; i <= r; i++) {
                    for(int j = col; j <= c; j++) {
                        if(has_adjacent(i, j)) return false;
                    }
                }

                if(length > 4) return false;
                ship_count[length]++;
            }
        }
    }
    
    return ship_count[1] == 4 && ship_count[2] == 3 && ship_count[3] == 2 && ship_count[4] == 1;
}

int main() {
    std::vector< std::vector<int> > field = {
        std::vector<int> {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        std::vector<int> {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int> {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
        std::vector<int> {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int> {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int> {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    bool is_valid = validate_battlefield(field);

    std::cout << "Validity: " << is_valid << "\n";
    return 0;
}