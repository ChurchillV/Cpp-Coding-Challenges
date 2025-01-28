#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cctype>

class Mix
{
public:
    static std::string mix(const std::string &s1, const std::string &s2) {
        std::map<char, int> s1_character_frequencies, s2_character_frequencies;
        std::unordered_set<char> characters;
        std::string comparison_string = "";

        // Populate frequency maps and collect all characters
        for (char character : s1) {
            if (std::tolower(character) == character && std::isalpha(character)) {
                s1_character_frequencies[character]++;
                characters.insert(character);
            }
        }

        for (char character : s2) {
            if (std::tolower(character) == character && std::isalpha(character)) {
                s2_character_frequencies[character]++;
                characters.insert(character);
            }
        }

        // Collect all characters into a vector
        std::vector<std::tuple<char, int, char>> sorted_characters;
        for (char character : characters) {
            int freq1 = s1_character_frequencies[character];
            int freq2 = s2_character_frequencies[character];

            if (freq1 > freq2 && freq1 > 1) {
                sorted_characters.emplace_back(character, freq1, '1');
            } else if (freq2 > freq1 && freq2 > 1) {
                sorted_characters.emplace_back(character, freq2, '2');
            } else if (freq1 > 1 && freq2 > 1) {
                sorted_characters.emplace_back(character, freq1, '=');
            }
        }

        // Sort the vector by frequency in descending order, then by source ('1', '2', '='), and finally by character
        std::sort(sorted_characters.begin(), sorted_characters.end(),
                [](const std::tuple<char, int, char> &a, const std::tuple<char, int, char> &b) {
                    if (std::get<1>(a) != std::get<1>(b))
                        return std::get<1>(a) > std::get<1>(b); // Descending frequency
                    if (std::get<2>(a) != std::get<2>(b))
                        return std::get<2>(a) < std::get<2>(b); // Ascending source ('1', '2', '=')
                    return std::get<0>(a) < std::get<0>(b);     // Ascending character
                });

        // Build the comparison string
        for (const auto &[character, frequency, source] : sorted_characters) {
            comparison_string += source;
            comparison_string += ':';
            comparison_string.append(frequency, character);
            comparison_string += '/';
        }

        // Remove trailing '/'
        if (!comparison_string.empty()) {
            comparison_string.pop_back();
        }

        return comparison_string;
    };
};

int main() {
    Mix test_mixer;
    std::string s1 = "Are they here";
    std::string s2 = "yes, they are here";
    std::cout << test_mixer.mix(s1, s2) << "\n";
    return 0;
}