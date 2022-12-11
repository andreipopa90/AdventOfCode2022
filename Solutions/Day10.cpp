#include <iostream>
#include "Day10.h"
#include "fstream"

void AddClockCycles(int &threshold, int clockCycle, int reg, int &sum, char characters[6][40]){
    if (clockCycle == threshold && clockCycle >= 20 && clockCycle <= 220) {
        sum += reg * clockCycle;
        threshold += 40;
    }
    int row = (clockCycle - 1) / 40;
    int col = (clockCycle - 1) - 40 * row;
    characters[row][col] = reg - 1 <= col && col <= reg + 1 ? '#' : ' ';
}

void Day10::ReadFile() {

    std::cout << "Day 10\n";

    std::ifstream fin("../Input/Day10.txt");
    std::string instruction;
    int clockCycle = 0;
    int threshold = 20;
    int registerX = 1;
    int sum = 0;
    char characters[6][40];
    while(getline(fin, instruction)) {
        if (instruction[0] == 'n') {
            clockCycle += 1;
            AddClockCycles(threshold, clockCycle, registerX, sum, characters);
        }
        else if (instruction[0] == 'a') {
            clockCycle += 1;
            AddClockCycles(threshold, clockCycle, registerX, sum, characters);

            clockCycle += 1;
            AddClockCycles(threshold, clockCycle, registerX, sum, characters);

            size_t spaceIndex = instruction.find(' ');
            int value = std::stoi(instruction.substr(spaceIndex + 1, instruction.length() - spaceIndex - 1));
            registerX += value;
        }
    }

    std::cout << "Solution 1 of Day 10 is: " << sum << std::endl;
    std::cout << "Solution 2 of Day 10 is: PAPKFKEJ" << std::endl;
    for (auto & character : characters) {
        for (char j : character) {
            std::cout << j;
        }
        std::cout << std::endl;
    }

}
