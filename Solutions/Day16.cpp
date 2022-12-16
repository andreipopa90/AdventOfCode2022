//
// Created by popaa on 16/12/2022.
//

#include <fstream>
#include "Day16.h"
#include <sstream>
#include <iostream>
#include <vector>
#define NODES 10

struct Node{
    int rate;
    char name[2];
    std::vector<Node*> neighbours;
};

void Day16::ReadFile() {

    std::ifstream fin("../Input/Day16.txt");
    std::string line;
    while (std::getline(fin, line)) {
        std::string name = line.substr(line.find_first_of(' ') + 1, 2);
        size_t start = line.find_first_of('=') + 1;
        size_t end = line.find_first_of(';');
        int rate = std::stoi(line.substr(start, end - start));
        size_t neighboursStart = (line.find("valves") != -1) ? line.find("valves") + 7 : line.find("valve") + 6;
        std::string neighbours = line.substr(neighboursStart);
        std::cout << neighbours << std::endl;
    }
}

void Day16::Solution1() {

}

void Day16::Solution2() {

}
