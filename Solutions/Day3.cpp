//
// Created by Andrei Popa on 02/12/2022.
//

#include <iostream>
#include <vector>
#include <map>
#include "Day3.h"
#include "fstream"
#include "string"

std::vector<std::pair<std::string, std::string>> compartments;
std::vector<std::string> compartments2;

void Day3::ReadFile() {
    std::cout << "Day 3" << std::endl;
    std::ifstream fin("../Input/Day3.txt");
    std::string items, item1, item2;
    if (fin.is_open()){
        while(std::getline(fin, items)){
            item1 = items.substr(0, items.length() / 2);
            item2 = items.substr(items.length() / 2, items.length());
            compartments.emplace_back(item1, item2);
            compartments2.emplace_back(items);
        }
    }
    fin.close();
}

void Day3::Solution1() {

    std::map<char, int> frequencies;
    int score = 0;

    for(int i = 0; i < compartments.size(); i++) {
        for (int j = 0; j < compartments[i].first.length(); j++) {
            char character = compartments[i].first[j];
            if (!frequencies.count(character))
                frequencies[character] = 1;
        }

        for (int j = 0; j < compartments[i].second.length(); j++) {
            char character = compartments[i].second[j];
            if (frequencies.count(character))
                frequencies[character] = 2;
        }

        for (auto const [key, val] : frequencies) {
            if (val == 2 && 'a' <= key && key <= 'z') {
                score += key - 96;
            }

            if (val == 2 && 'A' <= key && key <= 'Z') {
                score += key - 38;
            }
        }

        frequencies.clear();
    }

    std::cout << "Solution 1 of Day 3 is: " << score << std::endl;

}

void Day3::Solution2() {

    std::map<char, int> frequencies;
    int score = 0;

    for(int i = 0; i < compartments2.size(); i += 3) {

        for (int j = 0; j < compartments2[i].length(); j++) {
            char character = compartments2[i][j];
            if (!frequencies.count(character))
                frequencies[character] = 1;
        }
        for (int j = 0; j < compartments2[i + 1].length(); j++) {
            char character = compartments2[i + 1][j];
            if (frequencies.count(character))
                frequencies[character] = 2;
        }
        for (int j = 0; j < compartments2[i + 2].length(); j++) {
            char character = compartments2[i + 2][j];
            if (frequencies.count(character) && frequencies[character] == 2)
                frequencies[character] = 3;
        }

        for (auto const&[key, val] : frequencies) {
            if (val == 3 && 'a' <= key && key <= 'z') {
                score += key - 96;
            }

            if (val == 3 && 'A' <= key && key <= 'Z') {
                score += key - 38;
            }
        }

        frequencies.clear();
    }

    std::cout << "Solution 2 of Day 3 is: " << score << std::endl;

}
