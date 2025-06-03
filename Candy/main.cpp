#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int candy(vector<int>& ratings) {
    const int size = ratings.size();
    vector<int> left(size, 1);
    vector<int> right(size, 1);
    int candy_count = 0;

    for(int i = 1; i < size; i++) {
        if(ratings[i] > ratings[i - 1]) {
            left[i] = left[i-1] + 1;
        }
    }

    for(int i = size - 2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]) {
            right[i] = right[i+1] + 1;
        }
    }

    for(int i = 0; i < size; i++) {
        candy_count += max(left[i], right[i]);
    }

    return candy_count;
}

int main() {
    vector<int> ratings = {1,2};
    cout << candy(ratings) << endl;
    return 0;
}