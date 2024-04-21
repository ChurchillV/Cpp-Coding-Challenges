#include <string>
#include <vector>
#include <bits/stdc++.h> 

// Given a string of space separated numbers, return the highest and lowest numbers

// 1 - Iterate through the string
// 2 - Push each number into a vector using the spaces as delimiters
// 3 - In the end, return the highest and lowest values in the vector as a string


/**
 * Returns highest and lowest values in a space-separated string
 * 
 * @param string of space separated numbers (negatives included)
 * @return string consisting of highest and lowest values eg. "5 -3"

*/
std::string highAndLow(const std::string& numbers){
    // Vector to store numbers from the string
    std::vector <int> numbersFromString;
    
    // Token to store the values the string will bring
    std::string token; 

    // We iterate through the string, using a token to store values until we encounter a space
    // In that case, the token is stored and the remaining values are re-explored
    for(int index = 0; index < numbers.length(); index++) {
        if(numbers[index]  != ' ') {
            token += numbers[index];
            // std::cout << "\n" << token;
        } else {
            numbersFromString.push_back(stoi(token));
            token = "";
        }
    }

    numbersFromString.push_back(stoi(token));

    // Sort the vector so that the highest value is at the end, and the smallest at the beginning
    // Finally return the values in string form and test so we know that we're winning
    sort(numbersFromString.begin(), numbersFromString.end());

    return std::to_string(numbersFromString.back()) + " " + std::to_string(numbersFromString.front());
}

int main() {

    std::cout << highAndLow("1 2 3 4 5");
    return 0;
}