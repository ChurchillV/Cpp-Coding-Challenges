#include <iostream>
#include <string>
#include <vector>

/**
 * 1 - Loop nFLoors number of times (loop counter variable - floorIndex)
 * 
 * 2 - For each iteration, first attach `[nFloors - floorIndex]/2` spaces to our nth string
 * 
 * 3 - Then, attach `floorIndex` number of characters
 * 
 * 4 - Finally, attach another `[nFloors - floorIndex]/2` spaces to the end of the string
 * 
 * 5 - At the end of each iteration, push the string into the vector
 * @return vector<std::string>
 * @param nFloors - Number of floors of the tower
 * 
 * 
*/
std::vector<std::string> towerBuilder(unsigned nFloors) {
    std::string floorString = "";
    std::vector<std::string> tower;

    int baseCharacterCount = (2*nFloors) - 1;
    int currentFloorCharacterCount;

    for(int floorIndex = 1; floorIndex <= nFloors; floorIndex++) {
        currentFloorCharacterCount = (2*floorIndex) - 1;

        floorString += std::string((baseCharacterCount - currentFloorCharacterCount)/2, ' ');
        floorString += std::string(currentFloorCharacterCount, '*');
        floorString += std::string((baseCharacterCount - currentFloorCharacterCount)/2, ' ');

        tower.push_back(floorString);
        floorString = "";
    }
    return tower;
}

void printTower(std::vector<std::string> tower) {
    for(int floor = 0; floor < tower.size(); floor++) {
        std::cout << tower[floor] << '\n';
    }
}

int main() {

    std::vector<std::string> tower = towerBuilder(10);
    printTower(tower);
    return 0;
}