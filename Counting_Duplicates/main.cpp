#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::size_t duplicateCount(const std::string& in)
{
    if(in.length() < 2) { return 0; }

    std::vector <char> found_chars;
    std::vector <char> duplicate_chars;

    for(size_t index = 0; index < in.length(); index++) {

        // Check if the character is in the found_chars vector
        auto position = std::find(std::begin(found_chars), std::end(found_chars), tolower(in[index]));

        // If yes, check if it is in the duplicate_chars vector 
        if(position != found_chars.end()) {  
            position = std::find(std::begin(duplicate_chars), std::end(duplicate_chars), tolower(in[index]));

            // If it can't be found in the duplicate_chars vector, increment the duplicate_count and add it to the vector
            if(position == duplicate_chars.end()) { 
                duplicate_chars.push_back(tolower(in[index]));
            }
        } else {
            // Otherwise put it into the found_chars vector
            found_chars.push_back(tolower(in[index]));
        } 
    }

    return duplicate_chars.size();
}

int main() {
    std::string test_string = "a";
    char test_char = '1';
    std::cout << tolower(test_char) << "\n";
    return 0;
}
