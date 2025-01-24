#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // std::min_element
#include <unordered_map>

using Ingredients = std::unordered_map<std::string, int>;

int cakes(const Ingredients& recipe, const Ingredients& available) {
  std::vector<int> cake_count;

  for(auto &ingredient : recipe) {
    if(!available.count(ingredient.first) || (available.at(ingredient.first) / recipe.at(ingredient.first) < 1)) { 
      cake_count.push_back(0); 
    } else { 
      cake_count.push_back(std::floor(available.at(ingredient.first) / recipe.at(ingredient.first))); 
    }
  }

  return *min_element(cake_count.begin(), cake_count.end());
}

int main() {
    // Ingredients recipe    = {{"flour",  500}, {"sugar",  200}, {"eggs", 1}},
    //             available = {{"flour", 1200}, {"sugar", 1200}, {"eggs", 5}, {"milk", 200}};

    Ingredients recipe    = {{"apples",  3}, {"flour",  300}, {"milk",  100}, {"sugar", 150}, {"oil", 100}},
                    available = {{"sugar", 500}, {"flour", 2000}, {"milk", 2000}};

    std::cout << cakes(recipe, available) << "\n";
    return 0;
}