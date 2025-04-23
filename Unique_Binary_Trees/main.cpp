#include <iostream>
#include <vector>

class Solution {
    public:
        int numTrees(int n) {
            std::vector <int> numberOfTrees(n);
            numberOfTrees[0] = 1;

            for(int node = 1; node <= n; node++) {
                for(int root = 0; root < node; root++) {
                    numberOfTrees[node] += numberOfTrees[root] * numberOfTrees[node - root - 1];
                }
            }

            return numberOfTrees[n];
        }
    };

int main() {
    Solution* solution = new Solution();
    std::cout << "Answer: " << solution->numTrees(5) << "\n";
    return 0;
}