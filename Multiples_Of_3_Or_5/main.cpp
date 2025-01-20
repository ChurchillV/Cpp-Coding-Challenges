#include <iostream>
#include <set>
#include <cmath>
#include <numeric>

int solution(int number) 
{
    if(number <= 0) { return 0; }

    std::set<int> multiples;
    int loop_length = floor((number-1)/3);

    int first_multiple_5 = 5 * floor((number-1)/5);
    std::cout << "First multiple of 5: " << first_multiple_5 << "\n";

    int first_multiple_3 = 3 * floor((number-1)/3);
    std::cout << "First multiple of 3: " << first_multiple_3 << "\n";

    
    multiples.insert(first_multiple_3);
    multiples.insert(first_multiple_5);


    for(int index = loop_length; index > 0; index--) {

        first_multiple_3 -= 3;
        std::cout << "Multiple of 3: " << first_multiple_3 << "\n";

        first_multiple_5 -= 5;
        std::cout << "Multiple of 5: " << first_multiple_5 << "\n";

        if(first_multiple_3 > 0) { multiples.insert(first_multiple_3); }
        if(first_multiple_5 > 0) { multiples.insert(first_multiple_5); }
        
    }

    return std::accumulate(multiples.begin(), multiples.end(), 0);
}

int main() {
    std::cout << solution(102) << "\n";
    return 0;
}