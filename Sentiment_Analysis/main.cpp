#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string removePunctuations(string& s) {
    string result = "";
    for(char c : s) {
        if(!ispunct(c)) result += tolower(c);
    }

    return result;
}

bool isNegative(string& input) {

    vector<string> keywords = {"bad", "hate", "terrible", "awful", "disgusting", "horrible", "horrific", "disappointing"};

    for(string word: keywords) {
        if(word == input) {
            return true;
        }
    }

    return false;
}

vector<string> split(string& input) {
    stringstream ss(input);
    string word;
    vector<string> words;

    while(ss >> word) {
        if(word.size() >= 3) {
            words.push_back(word);
        }
    }

    return words;
}

string sentimentAnalysis(string input) {
    string normalized_input = removePunctuations(input);
    vector<string> words = split(normalized_input);
    int count = 0;

    for(string word: words) {
        if(isNegative(word)) {
            count++;
        }
    }

    float percentage = ((float)count/(float)words.size()) * 100;

    if(percentage <= 5) {
        return "POSITIVE";
    } else if(percentage > 5 && percentage < 20) {
        return "NEUTRAL";
    } else {
        return "NEGATIVE";
    }

    return "Indeterminate";
}

int main() {
    string test_string = "I like the fact that the food is nice.";
    cout << sentimentAnalysis(test_string) << endl;
}