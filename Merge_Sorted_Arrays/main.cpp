#include <iostream>
#include <vector>

class Solution {
    public:
    // 1 - Iterate m + n times, creating pointers for both vectors
    //
    // 2 - For each iteration, compare the value of each vector at their respective pointer indexes
    //
    // 3 - If the second vector value is found to be smaller, or the first vector value is 0,...
    //     we shift each value in the first vector one step to the right and place the
    //     value at the proper value, and increment the pointer index for the second vector
    //
    // 4 - If the first vector value if smaller, we just increment its pointer
        void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
            int nums1CurrentIndex = m - 1;
            int nums2CurrentIndex = n - 1;
            int adjustableSpace = m + n - 1;

            while(nums2CurrentIndex >= 0) {
                if(nums1CurrentIndex >= 0 && nums1[nums1CurrentIndex] > nums2[nums2CurrentIndex]) {
                    nums1[adjustableSpace--] = nums1[nums1CurrentIndex--];
                } else {
                    nums1[adjustableSpace--] = nums2[nums2CurrentIndex--];
                }
            } 
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
    std::vector<int> array1 = {5,8,10,0,0,0};
    std::vector<int> array2 = {4,7,9};
    test.merge(array1, 3, array2, 3);
    test.printVector(array1);
    return 0;
}