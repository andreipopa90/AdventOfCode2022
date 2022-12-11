#include <iostream>
#include <algorithm>
#include "Day1.h"
#include "fstream"

std::vector<int> ratios;

void Day1::Solution1() {
    int maxRatio = *std::max_element(std::begin(ratios), std::end(ratios));
    std::cout << "Solution 1 of Day 1 is: " << maxRatio << std::endl;
}

void Day1::Solution2() {
    std::sort(ratios.begin(), ratios.end(), std::greater<int>());
    int topThree = ratios[0] + ratios[1] + ratios[2];
    std::cout << "Solution 2 of Day 1 is: " << topThree << std::endl;
}

void Day1::ReadFile() {
    std::cout << "Day 1" << std::endl;
    std::ifstream fin("../input/Day1.txt");
    std::string ratio;
    int elfRatio = 0;
    int counter = 0;
    if (fin.is_open()){
        while (std::getline(fin, ratio)) {
            if (ratio[0] == '\0') {
                ratios.push_back(elfRatio);
                elfRatio = 0;
            }
            else {
                counter += 1;
                elfRatio += stoi(ratio);
            }
        }
    }
    fin.close();
}
