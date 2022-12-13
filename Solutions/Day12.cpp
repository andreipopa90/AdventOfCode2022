//
// Created by popaa on 12/12/2022.
//

#include <iostream>
#include "Day12.h"
#include "fstream"
#include "vector"
#include "algorithm"
#include "queue"
#include "map"

#define ROW 41
#define COL 162

char heightMap[ROW][COL];
std::pair<int, int> start, end, dir[4]{
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
};

void Day12::ReadFile() {

    std::cout << "Day 12" << '\n';
    std::ifstream fin("../Input/Day12.txt");

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            fin >> heightMap[i][j];
            if (heightMap[i][j] == 'S') {
                start = {i, j};
                heightMap[i][j] = 'a';
            }
            if (heightMap[i][j] == 'E') {
                end = {i, j};
                heightMap[i][j] = 'z';
            }


        }
    }

}

void bfs(int direction, std::map<std::pair<int, int>, int> &roadSize, std::pair<int, int> startPoint){
    std::queue<std::pair<int, int>> queue;
    queue.push(startPoint);
    std::pair<int, int> currentPosition;

    roadSize[startPoint] = 0;

    while (!queue.empty()) {
        currentPosition = queue.front();
        queue.pop();
        for (auto & i : dir) {
            std::pair<int, int> nextDirection = {currentPosition.first + i.first, currentPosition.second + i.second};
            if (nextDirection.first >= 0 && nextDirection.first < ROW &&
                nextDirection.second >= 0 && nextDirection.second < COL)
            {
                int difference = heightMap[currentPosition.first][currentPosition.second] -
                                 heightMap[nextDirection.first][nextDirection.second];
                if (direction * difference >= -1 && roadSize.find(nextDirection) == roadSize.end()) {
                    queue.push(nextDirection);
                    roadSize[nextDirection] = roadSize[currentPosition] + 1;
                }
            }
        }
    }
}

void Day12::Solution1() {
    std::map<std::pair<int, int>, int> roadSize;

    bfs(1, roadSize, start);

    std::cout << "Solution 1 of Day 12 is: " << roadSize[end] << '\n';
}

void Day12::Solution2() {
    std::map<std::pair<int, int>, int> roadSize;

    bfs(-1, roadSize, end);

    int minimumRoad = INT32_MAX;

    for (auto const& road: roadSize) {
        if (heightMap[road.first.first][road.first.second] == 'a' && road.second < minimumRoad) {
            minimumRoad = road.second;
        }
    }

    std::cout << "Solution 2 of Day 12 is: " << minimumRoad << '\n';

}
