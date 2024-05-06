#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int uniqueElementCount = 0;

        for (int index = 0; index < nums.size(); index++) {
            if(count(nums.begin(), nums.begin() + index + 1, nums[index]) == 1) {
                uniqueElementCount++;
                std::cout << "Unique elements : " << uniqueElementCount << "\n";
            } else {
                nums.erase(nums.begin() + index);
                index--;
                std::cout << "Element removed at index: " << index << "\n";
            }
        }

        return uniqueElementCount;
    }

    void printVector(std::vector<int>& array) {
        for(int value : array) {
            std::cout << value << " ";
        }
        std::cout << "\n"; 
    }
};

int main() {
    Solution test;
    std::vector<int> testVector = {1,1,2};
    int result = test.removeDuplicates(testVector);
    test.printVector(testVector);
    std::cout << result;
    return 0;
}