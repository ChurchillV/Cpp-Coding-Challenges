#include <iostream>
#include <cmath>

long int findNextSquare(long int sq) {
    double square_number = sq;
    long int next_square;

    if(abs(floor(sqrt(square_number))) == sqrt(square_number)) {
        next_square  = pow(sqrt(square_number) + 1, 2);
        return next_square;
    }
    return -1;
}

int main() {
    long int answer = findNextSquare(25);
    std::cout << answer << "\n";
    return 0;
}