#include <iostream>
#include <map>
#include <vector>
#include <stack>


std::map<char, char> coordinates{{'n', 's'}, {'s', 'n'}, {'e', 'w'}, {'w', 'e'}};

/**
 * 
Create a mapping of characters to match directions with their opposites
We iterate through the vector of coordinates 
When we encounter a coordinate, we increase the distance count
All coordinates encountered are stored in a stack
Upon encountering the next coordinate, we check whether it opposes the value at the top of the stack
If yes, we decrease the distance count
If no, we increase it and push the new coordinate onto the stack
At the end of the iteration, we return true if the stack is empty and distance count is 0, and false if otherwise
 * @param vector containing walk coordinates
 
 * @returns a boolean value showing whether the walk is valid or not
*/
bool isValidWalk(std::vector<char> walk) {
    // Our "stack" to keep track of encountered coordinates
    std::stack<char> coordinateStack;

    // Distance count
    int distance = 0;

    // Return false right away if the walk doesn't have exactly 10 coordinates
    if(walk.size() != 10) return false;

    for(int index = 0; index < walk.size(); index++) {

        // If the coordinate stack is empty, push the new coordinate onto it and increment the distance
        if(coordinateStack.empty()) {
            coordinateStack.push(walk[index]);
            distance++;
        }

        // Otherwise, we check if the encountered coordinate cancels out the coordinate at the top of our coordinate stack
        // If yes, we pop we coordinate at the top of the stack and decrement the distance
        // If no, we push the new coordinate and increment the distance
        else {
            if(walk[index] == coordinates[coordinateStack.top()]) {
                coordinateStack.pop();
                distance--;
            } else {
                coordinateStack.push(walk[index]);
                distance++;
            }
        }
    }

    // At the end of the iteration, return where the distance is 0 and the stack is empty
    return coordinateStack.empty() && distance == 0;
}

int main() {

    std::cout << std::boolalpha << isValidWalk({'e','e','e','w','n','s','n','s','e','w'});
    
    return 0;
}