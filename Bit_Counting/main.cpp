#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <typeinfo>

unsigned int countBits(unsigned long long n){
    if(n <= 0) return 0;
    std::string binary_conversion = std::bitset<128>(n).to_string();
    auto bit_count = std::count(binary_conversion.begin(), binary_conversion.end(), '1');
    return bit_count;
}

int main() {
    std::cout << countBits(533752471422917991) << "\n";
    return 0;
};