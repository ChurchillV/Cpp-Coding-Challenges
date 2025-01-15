#include <iostream>
#include <string>
#include <vector>

std::string likes(const std::vector<std::string> &names)
{
    std::string final_text = "";
    switch (names.size())
    {
    case 0:
        final_text += "no one likes this";
        break;
    case 1:
        final_text += names[0] + " likes this";
        break;
    case 2:
        final_text += names[0] + " and " + names[1] + " like this";
        break;
    case 3:
        final_text += names[0] + ", " + names[1] + " and " + names[2] + " like this";
        break;
    
    default:
        final_text += names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this"; 
        break;
    }
    return final_text; // Do your magic!
}

int main() {
    std::vector<std::string> names = {"Johnny", "Kwaku tech", "James", "Keely"};
    std::cout << likes(names) << "\n";
    return 0;
}