//
// Created by popaa on 04/12/2022.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Day5.h"
#include "fstream"
#define CRATES 9
#define LINES 8

std::vector<std::vector<char>> crates;
std::vector<std::vector<char>> crates2;

void Day5::ReadFile() {

    std::cout << "Day 5" << std::endl;

    int amount, stack1, stack2;
    std::string line, move, from, to;

    std::ifstream fin("../Input/Day5.txt");

    // Initialize crates
    for (int i = 1; i <= CRATES; i++) {
        std::vector<char> cratesi;
        crates.push_back(cratesi);
        crates2.push_back(cratesi);
    }

    for(int i = 0; i < LINES; i++){
        std::getline(fin, line);
        for (int j = 1; j < line.length(); j += 4) {
            if ('A' <= line[j] && line[j] <= 'Z'){
                crates[j / 4].push_back(line[j]);
                crates2[j / 4].push_back(line[j]);
            }
        }
    }
    for (int i = 0; i < CRATES; i++){
        std::reverse(crates[i].begin(), crates[i].end());
        std::reverse(crates2[i].begin(), crates2[i].end());
    }

    // The line with indexes. No need for it!
    getline(fin, line);
    std::vector<char> subvector;
    while(fin >> move >> amount >> from >> stack1 >> to >> stack2) {
        subvector = {crates[stack1 - 1].end() - amount, crates[stack1 - 1].end()};
        std::reverse(subvector.begin(), subvector.end());
        crates[stack1 - 1].erase(crates[stack1 - 1].end() - amount, crates[stack1 - 1].end());
        crates[stack2 - 1].insert(crates[stack2 - 1].end(), subvector.begin(), subvector.end());

        subvector = {crates2[stack1 - 1].end() - amount, crates2[stack1 - 1].end()};
        crates2[stack1 - 1].erase(crates2[stack1 - 1].end() - amount, crates2[stack1 - 1].end());
        crates2[stack2 - 1].insert(crates2[stack2 - 1].end(), subvector.begin(), subvector.end());
    }

    fin.close();

}

void Day5::Solution1() {
    std::cout << "Solution 1 of Day 5 is: ";
    for (int i = 0; i < CRATES; i++) {
        std::cout << crates[i].back();
    }
    std::cout << std::endl;
}

void Day5::Solution2() {

    std::cout << "Solution 2 of Day 5 is: ";
    for (int i = 0; i < CRATES; i++) {
        std::cout << crates2[i].back();
    }
    std::cout << std::endl;
}
