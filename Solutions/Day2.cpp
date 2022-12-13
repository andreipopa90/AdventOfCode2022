#include "Day2.h"
#include "fstream"
#include "map"
#include "iostream"

int score;
int actualScore;

void Day2::ReadFile() {
    std::cout << "Day 2" << '\n';
    std::ifstream fin("../input/Day2.txt");
    std::map<std::pair<char, char>, int> guessedTable = {
            {{'A', 'X'}, 4},
            {{'A', 'Y'}, 8},
            {{'A', 'Z'}, 3},
            {{'B', 'X'}, 1},
            {{'B', 'Y'}, 5},
            {{'B', 'Z'}, 9},
            {{'C', 'X'}, 7},
            {{'C', 'Y'}, 2},
            {{'C', 'Z'}, 6}
    };

    std::map<std::pair<char, char>, int> actualTable = {
            {{'A', 'X'}, 3},
            {{'A', 'Y'}, 4},
            {{'A', 'Z'}, 8},
            {{'B', 'X'}, 1},
            {{'B', 'Y'}, 5},
            {{'B', 'Z'}, 9},
            {{'C', 'X'}, 2},
            {{'C', 'Y'}, 6},
            {{'C', 'Z'}, 7}
    };
    char A, B;
    score = 0;
    actualScore = 0;
    if (fin.is_open()){
        while (fin >> A >> B) {
            score += guessedTable[{A, B}];
            actualScore += actualTable[{A, B}];
        }
    }
    fin.close();
}

void Day2::Solution1() {
    // A, X - rock - 1pt
    // B, Y - paper - 2pt
    // C, Z - scissor - 3pt
    // Win - 6
    // Lost - 0
    // Draw - 3
    std::cout << "Solution 1 of Day 2 is: " << score << '\n';
}

void Day2::Solution2() {
    // X - Loss - 0
    // Y - Draw - 3
    // Z - Win - 6
    // A - rock - 1pt
    // B - paper - 2pt
    // C - scissor - 3pt
    std::cout << "Solution 2 of Day 2 is: " << actualScore << '\n';
}
