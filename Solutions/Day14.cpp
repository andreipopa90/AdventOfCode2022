//
// Created by popaa on 15/12/2022.
//

#include <iostream>
#include <vector>
#include "Day14.h"
#include "sstream"
#include "fstream"
#include "set"
#define LINES 123

std::set<std::pair<int, int>> visited;
int maxRow;

void Day14::ReadFile() {


    /**
     * 498: 4, 5, 6
     * 499, 6
     * 503, 4
     * 502, 4
     * 502, 5
     * 502, 6
     * 502, 7
     * 502, 8
     * 502, 9
     */


    std::cout << "Day 14\n";
    std::ifstream fin("../Input/Day14.txt");
    std::string walls;
    std::string wallCoordinates;
    while(getline(fin, walls)) {
        std::stringstream sin(walls);
        int index = 0;

        std::pair<int, int> previous = {-1, -1};

        while(std::getline(sin, wallCoordinates, '-')) {
            if (index > 0) wallCoordinates = wallCoordinates.substr(2);
            size_t position = wallCoordinates.find(',');
            std::pair<int, int> coordinates = {std::stoi(wallCoordinates.substr(0, position)),
                                               std::stoi(wallCoordinates.substr(position + 1))};
            maxRow = std::max(maxRow, coordinates.second);
            if (previous.first == -1 & previous.second == -1) {
                previous = coordinates;
            } else {
                bool swapped = false;
                if (previous > coordinates) {
                    swap(previous, coordinates);
                    swapped = true;
                }
                for (int i = previous.first; i <= coordinates.first; i++) {
                    for (int j = previous.second; j <= coordinates.second; j++)
                        visited.insert({i, j});
                }
                if (swapped) swap(previous, coordinates);
                previous = coordinates;
            }
            index += 1;
        }
    }
    fin.close();

}

void Day14::Solution1() {

    int turns;
    bool solution1 = false;
    for (turns = 0;;turns++) {
        std::pair<int, int> current = {500, 0};
        bool stopped = false;
        while (!stopped && current.second < maxRow + 1) {
            if (current.second == maxRow && !solution1){
                std::cout << "Solution 1 of Day 14 is: " << turns << std::endl;
                solution1 = true;
            }
            std::pair<int, int> down = {current.first, current.second + 1};
            std::pair<int, int> left = {current.first - 1, current.second + 1};
            std::pair<int, int> right = {current.first + 1, current.second + 1};
            if (visited.find(down) == visited.end()){
                current.second += 1;
            } else if (visited.find(left) == visited.end()) {
                current = left;
            } else if (visited.find(right) == visited.end()) {
                current = right;
            } else {
                stopped = true;
            }
        }
        visited.insert(current);
        if (visited.find({500, 0}) != visited.end()) break;
    }

    std::cout << "Solution 2 of Day 14 is: " << turns << std::endl;

}

void Day14::Solution2() {

}
