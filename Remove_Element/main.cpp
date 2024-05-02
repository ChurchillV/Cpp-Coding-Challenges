#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
    public:
// 1 - Rearrange the array using the remove function such that all values equal to `val`...
//     are moved to the far side of the vector, returning the start index of this range.
// 
// 2 - Using the erase method, we remove all elements starting from this start index to the end of the vector.
        int removeElement(std::vector<int>& nums, int val) {
            nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
            return nums.size();
        }

        // Function to print out vector values
        void printVector(std::vector<int>& array) {
            for(int index = 0; index < array.size(); index++) {
                std::cout << array[index] << " ";
            }
            std::cout << "\n";
        }
};


int main() {
    Solution test;
    std::vector<int> testVector = {0,1,2,2,3,0,4,2};
    int result = test.removeElement(testVector, 2);
    std::cout << "Modified array: " << "\n";
    test.printVector(testVector);
    std::cout << "Number of remaining elements: " << result;
    
    return 0;
}