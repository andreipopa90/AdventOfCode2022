//
// Created by popaa on 06/12/2022.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include "Day6.h"
#include "fstream"

std::string dataStream;

void Day6::ReadFile() {

    std::cout << "Day 6" << std::endl;
    std::ifstream fin("../Input/Day6.txt");
    std::getline(fin, dataStream);
    fin.close();
}

void Day6::Solution1() {

    bool found;
    std::set<char> visited;
    int foundIndex = 0;

    for (int i = 0; i < dataStream.size() - 4; i++) {
        std::string subString = dataStream.substr(i, 4);
        found = true;
        for (char & j : subString) {
            if (!visited.insert(j).second) {
                found = false;
                visited.clear();
                break;
            }
        }
        if (found) {
            foundIndex = i + 4;
            break;
        }
    }

    std::cout << "Solution 1 of Day 6 is: " << foundIndex << std::endl;
}

void Day6::Solution2() {

    bool found;
    std::set<char> visited;
    int foundIndex = 0;

    for (int i = 0; i < dataStream.size() - 14; i++) {
        std::string subString = dataStream.substr(i, 14);
        found = true;
        for (char & j : subString) {
            if (!visited.insert(j).second) {
                found = false;
                visited.clear();
                break;
            }
        }
        if (found) {
            foundIndex = i + 14;
            break;
        }
    }

    std::cout << "Solution 2 of Day 6 is: " << foundIndex << std::endl;

}
