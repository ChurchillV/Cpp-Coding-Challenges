#include <iostream>
#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
    std::vector<int> result;
    if(snail_map.empty() || snail_map[0].empty()) {
        return result;
    }

    int top = 0, bottom = snail_map.size() - 1, left = 0, right = snail_map[0].size() - 1;
    int dir = 0; // 0 - right; 1 - down; 2 - left; 3 - up; --> directions
    
    while(top <= bottom && left <= right) {
        if(dir == 0) {
            for(int i = left; i <= right; i++) {
                result.push_back(snail_map[top][i]);   
            }
            top++;
        } else if(dir == 1) {
            for(int i = top; i <= bottom; i++) {
                result.push_back(snail_map[i][right]);
            }
            right--;
        } else if(dir == 2) {
            for(int i = right; i >= left; i--) {
                result.push_back(snail_map[bottom][i]);
            }
            bottom--;
        } else if(dir == 3) {
            for(int i = bottom; i >= top; i--) {
                result.push_back(snail_map[i][left]);
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }
    return result;
}

 void printVector(std::vector<int> testVector) {
        std::cout << "\n";
        for (int i = 0; i < testVector.size() - 1; i++) {
            std::cout << testVector[i] << ",";
        }
        std::cout << testVector[testVector.size() - 1];
        std::cout << "\n";
}

int main() {
    std::vector<std::vector<int>> testVector = {{1,2}, {4,3}};
    std::vector<int> resultVector = snail(testVector);
    printVector(resultVector);
    return 0;
}