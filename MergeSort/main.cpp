#include <iostream>
#include <vector>
#include <cmath>

void merge(std::vector<int>& leftArray, std::vector<int>& rightArray, std::vector<int>& array) {
    int leftSize = leftArray.size();
    int rightSize = rightArray.size();
    int i = 0, l = 0, r = 0; // Indices

    while(l < leftSize && r < rightSize) {
        if(leftArray[l] < rightArray[r]) {
            array[i] = leftArray[l];
            i++;
            l++;
        } else {
            array[i] = rightArray[r];
            i++;
            r++;
        }
    }

    while(l < leftSize) {
        array[i] = leftArray[l];
        l++;
        i++;
    }

    while(r < rightSize) {
        array[i] = rightArray[r];
        r++;
        i++;
    }
}

void mergeSort(std::vector<int>& array) {

    int length = array.size();
    if(length <= 1) return;

    int middle = std::floor(length/2);
    std::vector<int> leftArray(array.begin(), array.begin() + middle);
    std::vector<int> rightArray(array.begin() + middle, array.end());

    int i = 0; // Index for left array
    int j = 0; // Index for right array

    for(; i < length; i++) {
        if(i < middle) {
            leftArray[i] = array[i];
        } else {
            rightArray[j] = array[i];
            j++;
        }
    }

    mergeSort(leftArray);
    mergeSort(rightArray);
    merge(leftArray, rightArray, array);
}


void printVector(std::vector<int> testVector) {
    for (int i = 0; i < testVector.size(); i++) {
        std::cout << testVector[i] << "\n";
    }
}

int main() {
    std::vector<int> testVector = {5, 4, 3, 6, 8, 1};

    std::cout << "Unsorted array: \n";
    printVector(testVector);

    mergeSort(testVector);

    std::cout << "Sorted array: \n";
    printVector(testVector);
    return 0;
}