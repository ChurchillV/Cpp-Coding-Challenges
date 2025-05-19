#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

std::vector<std::string> permutations(std::string s) {
  std::set<std::string> permutations;
  std::sort(s.begin(), s.end());

  do {
    permutations.insert(s);
  } while(std::next_permutation(s.begin(), s.end()));

  return std::vector<std::string>(permutations.begin(), permutations.end());
}

int main() {

    std::vector<std::string> sample = permutations("aabb");

    for(std::string permuation : sample) {
        std::cout << permuation << std::endl;
    }
    return 0;
}