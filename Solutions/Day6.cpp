//
// Created by popaa on 06/12/2022.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "Day6.h"
#include "fstream"

std::string dataStream;

void Day6::ReadFile() {

    std::cout << "Day 6" << std::endl;
    std::ifstream fin("../Input/Day6.txt");
    std::getline(fin, dataStream);

}

void Day6::Solution1() {

    bool found = false;
    std::vector<char> visited;
    int foundIndex = 0;

    for (int i = 0; i < dataStream.size() - 4 && !found; i++) {
        std::string subString = dataStream.substr(i, 4);
        visited.clear();
        found = true;
        for (int j = 0; j < subString.size(); j++) {
            if (std::count(visited.begin(), visited.end(), subString[j])) {
                found = false;
                break;
            }
            visited.push_back(subString[j]);
        }
        if (found) {
            foundIndex = i + 4;
            break;
        }
    }

    std::cout << "Solution 1 of Day 6 is: " << foundIndex << std::endl;
}

void Day6::Solution2() {

    bool found = false;
    std::vector<char> visited;
    int foundIndex = 0;

    for (int i = 0; i < dataStream.size() - 14 && !found; i++) {
        std::string subString = dataStream.substr(i, 14);
        visited.clear();
        found = true;
        for (int j = 0; j < subString.size(); j++) {
            if (std::count(visited.begin(), visited.end(), subString[j])) {
                found = false;
                break;
            }
            visited.push_back(subString[j]);
        }
        if (found) {
            foundIndex = i + 14;
            break;
        }
    }

    std::cout << "Solution 2 of Day 6 is: " << foundIndex << std::endl;

}
