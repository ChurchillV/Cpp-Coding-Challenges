#include <iostream>
#include <string>

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int symmetry_count = 0;
            for(int i = low; i <= high; i++) {
                std::string integer = std::to_string(i);
                if(integer.length() % 2 == 0) {
                    int left_sum = 0, right_sum = 0;
                    for(int j = 0; j < integer.length() / 2; j++) {
                        left_sum += (int)integer[j];
                    }
                    for(int j = integer.length() / 2; j < integer.length(); j++) {
                        right_sum += (int)integer[j];
                    }
                    if(left_sum == right_sum) symmetry_count++;
                 }
            }
            return symmetry_count;
        }
    };

int main() {
    Solution* test = new Solution();
    std::cout << "Symmetry count = " << test->countSymmetricIntegers(1200,1230) << "\n";
    return 0;
}