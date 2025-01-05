#include <iostream>
#include <string>
#include <map>

bool is_isogram(const std::string& str) {
    std::map<char, int> letter_frequency_mapping;

    if(str.empty()) { 
        return true; 
    }

    for(const auto& letter : str) {
        if(std::isalpha(letter)) {
            letter_frequency_mapping[std::tolower(letter)]++;

            if(letter_frequency_mapping[std::tolower(letter)] > 1) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::string testString = "c";
    std::cout << is_isogram(testString) << "\n";
    return 0;
}