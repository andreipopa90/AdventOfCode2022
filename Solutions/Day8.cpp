#include <iostream>
#include "Day8.h"
#include "fstream"

#define ROW 99
#define COL 99

int directionX[4] = {-1, 0, 1, 0};
int directionY[4] = {0, -1, 0, 1};
char** forest;

void Day8::ReadFile() {

    std::cout << "Day 8" << std::endl;

    // Initialize forest
    forest = new char*[ROW];
    for (int i = 0; i < ROW; i++) {
        forest[i] = new char[COL];
    }

    std::ifstream fin("../Input/Day8.txt");
    char tree;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            fin >> tree;
            forest[i][j] = tree;
        }
    }

    fin.close();

}

std::pair<bool, int> CheckView(int startX, int startY) {

    bool result = false;
    int x, y, smallerCount, totalTreesToCheck, viewCount, viewScore = 1;
    for (int i = 0; i < 4; i++) {
        x = startX;
        y = startY;
        smallerCount = 0;
        totalTreesToCheck = 0;
        viewCount = 0;
        while(x + directionX[i] >= 0 && x + directionX[i] < ROW &&
                y + directionY[i] >= 0 && y + directionY[i] < COL)
        {
            totalTreesToCheck++;
            if (forest[x + directionX[i]][y + directionY[i]] < forest[startX][startY]) {
                smallerCount++;
                viewCount++;
            }
            else {
                viewCount++;
                break;
            }

            x += directionX[i];
            y += directionY[i];

        }
        viewScore *= viewCount;
        result = result || (totalTreesToCheck == smallerCount);
    }
    return {result, viewScore};

}

void Day8::Solution() {

    int maximumViewScore = -1;
    int visible = ROW * 2 + (COL - 2) * 2;
    for (int i = 1; i < ROW - 1; i++) {
        for (int j = 1; j < COL - 1; j++) {
            std::pair<bool, int> result = CheckView(i, j);
            if(result.first) visible++;
            maximumViewScore = std::max(maximumViewScore, result.second);
        }
    }

    std::cout << "Solution 1 of Day 8 is: " << visible << std::endl;
    std::cout << "Solution 2 of Day 8 is: " << maximumViewScore << std::endl;

}
