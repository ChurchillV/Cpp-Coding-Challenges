#include <iostream>
#include <map>
#include <stack>
#include <string>

std::string to_postfix(std::string infix) {
    std::map<char, int> operator_precedence_mapping = {{'^', 2}, {'*', 3}, {'/', 3}, {'+', 4}, {'-', 4}};
    std::stack<char> operator_stack;
    std::string postfix = "";
    infix += ')';
    
    operator_stack.push('(');

    auto print_top_of_stack = [&]() {
        std::cout << "Top of Stack " << operator_stack.top() << "\n";
    };

    for(int i = 0; i < infix.length(); i++) {
        if(operator_precedence_mapping[infix[i]]) {
            std::cout << "Current operator: " << infix[i] << "\n";
            if(operator_precedence_mapping[operator_stack.top()] <= operator_precedence_mapping[infix[i]]) {
                if(operator_stack.top() != '(') {
                    while(operator_precedence_mapping[operator_stack.top()] <= operator_precedence_mapping[infix[i]] && operator_stack.top() != '(') {
                        postfix += operator_stack.top();
                        operator_stack.pop();
                    }
                }
                operator_stack.push(infix[i]);
                print_top_of_stack();
                std::cout << "Postfix: " << postfix << "\n";
            } else {
                operator_stack.push(infix[i]);
                print_top_of_stack();
            }
        } else if(infix[i] == '(') {
            operator_stack.push(infix[i]);
            print_top_of_stack();
        } else if(infix[i] == ')') {
            while(!operator_stack.empty()) {
                if(operator_stack.top() == '(') {
                    operator_stack.pop();
                    break;
                }
                else {
                    postfix += operator_stack.top();
                    operator_stack.pop();
                    std::cout << "Postfix: " << postfix << "\n";
                }
            } 
        } else {
            postfix += infix[i];
            std::cout << "Postfix: " << postfix << "\n";
        }
    }
    return postfix;
}

int main() {
    std::string infix = "(5-4-1)+9/5/2-7/1/7";
    std::string postfix = to_postfix(infix);

    std::cout << postfix << "\n";
    return 0;
}
