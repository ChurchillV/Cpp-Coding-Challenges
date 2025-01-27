#include <iostream>
#include <string>
#include <cmath>
#include <vector>

std::string range_extraction(std::vector<int> args) {
    int start_of_range, end_of_range;
    bool is_in_range = false;
    std::string range = "";

    start_of_range = args[0];
    for(int index = 1; index <= args.size(); index++) {
        if(args[index] - args[index-1] == 1) {
            is_in_range = true;
            end_of_range = args[index];
        } else {
            if(is_in_range) {
                range += (end_of_range == start_of_range + 1) ? 
                        std::to_string(start_of_range) + "," + std::to_string(end_of_range) + "," :
                        std::to_string(start_of_range) + "-" + std::to_string(end_of_range) + ",";
                is_in_range = false;
            } else {
                range += std::to_string(start_of_range) + ",";
            }
            start_of_range = args[index];
        }
    }         

    range.pop_back(); // <-- Remove last comma
    return range;
}

int main() {
    std::vector<int> test_vector = {-3,-2,-1,2,10,15,16,18,19,20};
    std::cout << range_extraction(test_vector) << "\n";
    return 0;
}