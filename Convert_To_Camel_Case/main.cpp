#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::vector<std::string> split_by_delimiters(std::string main_string) {
    std::vector<std::string> sub_strings;
    std::string current_string = "";

    for(int index = 0; index < main_string.length(); index++) {
        if(main_string[index] == '-' || main_string[index] == '_') {
            if(!current_string.empty()) {
                sub_strings.push_back(current_string);
            }
            current_string = "";
        } else {
            current_string += main_string[index];
        }
    };

    if(!current_string.empty()) {
        sub_strings.push_back(current_string);
    }

    return sub_strings;
}

void print_strings(std::vector<std::string> strings) {
    for(int index = 0; index < strings.size(); index++) {
        std::cout << strings.at(index) << "\n"; 
    }
}

std::string to_camel_case(std::string text) {
    std::vector<std::string> sub_strings = split_by_delimiters(text);
    std::string final_string;

    if(text.length() < 1) { return "";}

    for(int index = 0; index < sub_strings.size(); index++) {
        if(index == 0 && sub_strings.at(index)[0] != toupper(sub_strings.at(index)[0])) {
            sub_strings.at(index)[0] = sub_strings.at(index)[0];
        } else {
            sub_strings.at(index)[0] = toupper(sub_strings.at(index)[0]);
        }

        final_string += sub_strings.at(index);
    }
    return final_string;
}

int main() {
    std::string str1 = "Invoke-new_function";
    // std::string str2 = "fgjskmd";
    // std::cout << str1 + str2 << "\n";
    // print_strings(split_by_delimiters(str1));

    std::cout << to_camel_case(str1) << "\n";
    return 0;
}