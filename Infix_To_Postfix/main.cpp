#include <iostream>
#include <map>
#include <stack>
#include <string>

std::string to_postfix(const std::string& infix) {
    std::map<char, int> precedence = {
        {'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}
    };

    std::stack<char> ops;
    std::string postfix;

    for (char token : infix) {
        if (std::isalnum(token)) {
            postfix += token;
        } 
        else if (token == '(') {
            ops.push(token);
        } 
        else if (token == ')') {
            while (!ops.empty() && ops.top() != '(') {
                postfix += ops.top();
                ops.pop();
            }
            if (!ops.empty()) ops.pop(); // remove the '('
        } 
        else if (precedence.count(token)) {
            while (!ops.empty() && ops.top() != '(' &&
                   precedence[ops.top()] >= precedence[token]) {
                postfix += ops.top();
                ops.pop();
            }
            ops.push(token);
        }
    }

    // Pop any remaining operators
    while (!ops.empty()) {
        postfix += ops.top();
        ops.pop();
    }

    return postfix;
}


int main() {
    std::string infix = "(5-4-1)+9/5/2-7/1/7";
    std::string postfix = to_postfix(infix);

    std::cout << postfix << "\n";
    return 0;
}