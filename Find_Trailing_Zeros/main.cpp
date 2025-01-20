#include <iostream>
#include <cmath>

long zeros(long n) {
    if(n <= 0) return 0; 

    size_t count = 0;

    for(int index = 5; n/index >= 1; index *= 5) count += floor(n/index);

    return count;
}

int main() {
    std::cout << "Trailing zeros: " << zeros(23) << "\n";
    return 0;
}