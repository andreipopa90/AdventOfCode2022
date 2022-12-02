//
// Created by popaa on 01/12/2022.
//

#include "Day2.h"
#include "fstream"
#include "map"
#include "iostream"



int score;
int actualScore;

void Day2::ReadFile() {
    std::map<std::pair<char, char>, int> winningTable;
    std::map<std::pair<char, char>, int> actualTable;
    winningTable[std::pair('A', 'X')] = 4;
    winningTable[std::pair('A', 'Y')] = 8;
    winningTable[std::pair('A', 'Z')] = 3;
    winningTable[std::pair('B', 'X')] = 1;
    winningTable[std::pair('B', 'Y')] = 5;
    winningTable[std::pair('B', 'Z')] = 9;
    winningTable[std::pair('C', 'X')] = 7;
    winningTable[std::pair('C', 'Y')] = 2;
    winningTable[std::pair('C', 'Z')] = 6;

    actualTable[std::pair('A', 'X')] = 3;
    actualTable[std::pair('A', 'Y')] = 4;
    actualTable[std::pair('A', 'Z')] = 8;
    actualTable[std::pair('B', 'X')] = 1;
    actualTable[std::pair('B', 'Y')] = 5;
    actualTable[std::pair('B', 'Z')] = 9;
    actualTable[std::pair('C', 'X')] = 2;
    actualTable[std::pair('C', 'Y')] = 6;
    actualTable[std::pair('C', 'Z')] = 7;

    std::ifstream fin("../input/Day2.txt");
    std::string ratio;
    char A, B;
    score = 0;
    actualScore = 0;
    if (fin.is_open()){
        while (fin >> A >> B) {
            std::pair match(A, B);
            score += winningTable[match];
            actualScore += actualTable[match];
        }
    }
    fin.close();
}

void Day2::Solution1() {
    //A, X - rock - 1pt
    //B, Y - paper - 2pt
    //C, Z - scissor - 3pt
    //Win - 6, Lost - 0, Draw - 3
    std::cout << "Solution 1 for Day 2 is: " << score << std::endl;
}

void Day2::Solution2() {
    //X - Loss - 0
    //Y - Draw - 3
    //Z - Win - 6
    //A- rock - 1pt
    //B- paper - 2pt
    //C- scissor - 3pt
    std::cout << "Solution 2 for Day 2 is: " << actualScore << std::endl;
}
