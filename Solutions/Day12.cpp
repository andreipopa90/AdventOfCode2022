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
std::queue<std::pair<int, int>> startPoints;

void Day12::ReadFile() {

    std::cout << "Day 12" << std::endl;
    std::ifstream fin("../Input/Day12.txt");

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            fin >> heightMap[i][j];
            if (heightMap[i][j] == 'S') {
                start = {i, j};
                startPoints.push(start);
                heightMap[i][j] = 'a';
            }
            else if (heightMap[i][j] == 'a') {
                startPoints.emplace(i, j);
            }
            if (heightMap[i][j] == 'E') {
                end = {i, j};
                heightMap[i][j] = 'z';
            }


        }
    }

}

int RoadSizes(std::pair<int, int> startPoint, std::pair<int, int> endPoint) {
    std::vector<std::pair<int, int>> visited;
    std::queue<std::pair<int, int>> queue;
    std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> parent;
    visited.push_back(startPoint);
    queue.push(startPoint);
    std::pair<int, int> currentPosition;
    std::pair<int, int> endParent = {-1, -1};

    while (!queue.empty()) {
        currentPosition = queue.front();
        queue.pop();
        if (currentPosition != endPoint) {
            for (auto & i : dir) {
                std::pair<int, int> nextDirection = {currentPosition.first + i.first, currentPosition.second + i.second};
                if (nextDirection.first >= 0 && nextDirection.first < ROW &&
                    nextDirection.second >= 0 && nextDirection.second < COL)
                {
                    int difference = heightMap[currentPosition.first][currentPosition.second] -
                                     heightMap[nextDirection.first][nextDirection.second];
                    if (difference >= - 1 &&
                        std::find(visited.begin(), visited.end(),nextDirection) == visited.end()) {
                        visited.push_back(nextDirection);
                        queue.push(nextDirection);
                        parent[currentPosition].push_back(nextDirection);
                        if (nextDirection == endPoint) {
                            endParent = currentPosition;
                        }
                    }
                }
            }
        }
        else{
            break;
        }
    }

    int roadSize = 1;

    if (endParent.first == -1 && endParent.second == -1) return -1;

    while(endParent != start) {
        for (const auto& x: parent) {
            if (std::find(x.second.begin(), x.second.end(), endParent) != x.second.end()) {
                endParent = x.first;
                roadSize += 1;
                break;
            }
        }
    }

    return roadSize;
}

void Day12::Solution1() {
    std::cout << "Solution 1 of Day 12 is: " << RoadSizes(start, end) << std::endl;
}

void Day12::Solution2() {

    std::cout << startPoints.size() << std::endl;
    std::vector<int> roadSizes;

    while(!startPoints.empty()) {
        roadSizes.push_back(RoadSizes(startPoints.front(), end));
        startPoints.pop();
    }

    int maximum = *std::max_element(std::begin(roadSizes), std::end(roadSizes));
    std::cout << "Solution 2 of Day 12 is: " << maximum << std::endl;

}
