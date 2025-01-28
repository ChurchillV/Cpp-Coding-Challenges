#include <iostream>
#include <string>
#include <map>

class Mix
{
public:
    static std::string mix(const std::string &s1, const std::string &s2) {
        std::map<char, int> s1_character_frequencies, s2_character_frequencies;
        std::string comparison_string = "";

        for (char character : s1) {
            if(std::tolower(character) == character && isalpha(character)) { s1_character_frequencies[character]++; }
        }

        for (char character : s2) {
            if(std::tolower(character) == character && isalpha(character)) { s2_character_frequencies[character]++; }
        }

        for(auto character : s1_character_frequencies) {
            if(s1_character_frequencies[character.first] > s2_character_frequencies[character.first] && s1_character_frequencies[character.first] > 1) {
                comparison_string += "1:";
                for(int index = s1_character_frequencies[character.first]; index > 0; index--) {
                    comparison_string += character.first;
                }
                comparison_string += "/";
            } else if (s2_character_frequencies[character.first] > s1_character_frequencies[character.first] && s2_character_frequencies[character.first] > 1) {
                comparison_string += "2:";
                for(int index = s2_character_frequencies[character.first]; index > 0; index--) {
                    comparison_string += character.first;
                }
                comparison_string += "/";
            } else {
                if(s1_character_frequencies[character.first] > 1 && s2_character_frequencies[character.first] > 1) {
                    comparison_string += "=:";
                    for(int index = s2_character_frequencies[character.first]; index > 0; index--) {
                        comparison_string += character.first;
                    }
                comparison_string += "/";
                }
            }
        }

        comparison_string.pop_back(); // <-- Remove trailing '/'
        return comparison_string;
    };
};

int main() {
    Mix test_mixer;
    std::string s1 = "mmmmm m nnnnn y&friend&Paul has heavy hats! &";
    std::string s2 = "my frie n d Joh n has ma n y ma n y frie n ds n&";
    std::cout << test_mixer.mix(s1, s2) << "\n";
    return 0;
}