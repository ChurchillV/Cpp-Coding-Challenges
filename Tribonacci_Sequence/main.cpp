#include <iostream>
#include <vector>

std::vector<int> tribonacci(std::vector<int> signature, int n) {
    std::vector<int> result;

    if(n == 0 ) return {};
    result = signature;

    for(int index = 3; index < n; index++) {
        int sum = result[index-1] + result[index-2] + result[index-3];
        result.push_back(sum);
    }

    result.resize(n);
    return result;
}

void printSequence(std::vector<int> sequence) {
    for(int index = 0l; index < sequence.size(); index++) {
        std::cout << sequence[index] << " ";
    }
}

int main() {

    std::vector<int> testSequence = tribonacci({1,1,1}, 10);
    printSequence(testSequence);
    return 0;
}