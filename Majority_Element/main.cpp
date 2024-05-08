#include <iostream>
#include <vector>
#include <map>
#include <set>

class Solution {
public:

// 1 - Iterate over the vector and store the each element along with it's frequency in a map
// 2 - Now iterate over this map, and return the key with a value greater than half the size of the array
    int majorityElement(std::vector<int>& nums) {  

        // Map to store elements and their respective frequencies
        std::map<int, int> elementFrequencyMapping;

        // For each time an element is encountered in the array, increment it's freqency 
        for(const auto& key : nums) { elementFrequencyMapping[key]++; }

        // Now, iterate over each element-frequency mapping, return the element with a frequency greater than n/2
        for(const auto& element : elementFrequencyMapping) {
            if(element.second > nums.size()/2) { return element.first; }
        }

        return 0;
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
    std::vector<int> testVector = {3,2,3};
    int result = test.majorityElement(testVector);
    std::cout << result;
    return 0;
}