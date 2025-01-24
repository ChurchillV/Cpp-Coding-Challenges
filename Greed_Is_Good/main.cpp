#include <iostream>
#include <map>
#include <array>

int score(const std::array<unsigned, 5>& dice) {
  std::map<int, int> scores_3 = {{1, 1000}, {6,600}, {5, 500}, {4, 400}, {3, 300}, {2, 200}};
  std::map<int, int> scores_1 = {{1, 100}, {5, 50}};
  std::map<int, int> score_frequency;
  int final_score = 0;

  for(auto score : dice) {
    score_frequency[score]++;
  }

  for(auto score : score_frequency) {
    if(score_frequency[score.first] >= 3) {
        final_score += scores_3[score.first];
        std::cout << "Incrementing score by: " << scores_3[score.first] << "\n";

        if(score_frequency[score.first] - 3 > 0 && scores_1.count(score.first)) {
            final_score += scores_1[score.first] * (score_frequency[score.first] - 3);
            std::cout << "Incrementing score by: " << scores_1[score.first] * (score_frequency[score.first] - 3) << "\n";
        }
    } else { 
        final_score += scores_1[score.first] * score_frequency[score.first];
        std::cout << "Incrementing score by: " << scores_1[score.first] * score_frequency[score.first] << "\n";
    } 
  }
  std::cout << "Final Score: " << final_score << "\n";
  return final_score;
}

int main() {

    std::array<unsigned, 5> dice = {5, 5, 5, 5, 1};
    std::cout << score(dice) << "\n";
    return 0;
}