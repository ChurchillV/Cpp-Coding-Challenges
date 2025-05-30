#include <iostream>
#include <climits>

int reverse(int x) {
    long reversed = 0;
    int abs_x = std::abs(x);
    int sign = x < 0 ? -1 : 1;

    while(abs_x > 0) {
        reversed = (reversed * 10) + (abs_x % 10);
        abs_x /= 10;
    }

    reversed *= sign;

    if(reversed < INT_MIN || reversed > INT_MAX) {
        return 0;
    }

    return reversed;
}

int main() {
    int testInt = 984;

    std::cout << reverse(testInt) << std::endl;

    return 0;
}