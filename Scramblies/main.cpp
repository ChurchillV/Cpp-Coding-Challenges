#include <iostream>
#include <string>
#include <unordered_map>

bool scramble(const std::string& s1, const std::string& s2){
    std::unordered_map<char, int> reference_string_mapping;

    for(char character : s1) { 
        std::cout << "Added character: " << character << "\n";
        reference_string_mapping[character]++; 
    }

    for(char character : s2) {
        if(reference_string_mapping.find(character) == reference_string_mapping.end()) { 
            std::cout << "Cannot find character: " << character << "\n";
            return false; 
        }
        if(reference_string_mapping[character] == 1) { reference_string_mapping.erase(character); }
        else { reference_string_mapping[character]--; }
    }

    return true;
}

int main() {
    std::string testString1 = "scriptingjava";
    std::string testString2 = "javascript";

    std::cout << scramble(testString1, testString2) << "\n";
    return 0;
}
