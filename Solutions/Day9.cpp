#include "Day9.h"
#include "iostream"
#include "fstream"
#include "map"
#include "set"
#include "vector"

std::map<char, std::pair<int, int>> directions{
        {'R', {0, 1}},
        {'U', {-1, 0}},
        {'D', {1, 0}},
        {'L', {0, -1}}
};

bool ManhattanDistance(std::pair<int, int> head, std::pair<int, int> tail) {
    int x = abs(head.first - tail.first);
    int y = abs(head.second - tail.second);
    return x + y >= 0 && x + y <= 2 && x >= 0 && x <= 1 && y >= 0 && y <= 1;
}

void Day9::ReadFile() {

    std::cout << "Day 9" <<std::endl;
    std::ifstream fin("../Input/Day9.txt");
    std::set<std::pair<int, int>> tailPositions;
    std::set<std::pair<int, int>> longTailPositions;
    std::pair<int, int> longRopeTravel[10];
    std::pair<int, int> start = {0, 0};
    char direction;
    int steps;

    tailPositions.insert(start);
    longTailPositions.insert(start);
    for (int i = 0; i < 10; i++) {
        longRopeTravel[i] = start;
    }

    while(fin >> direction >> steps) {
        for (int i = 1; i <= steps; i++) {
            longRopeTravel[0].first = longRopeTravel[0].first + directions[direction].first;
            longRopeTravel[0].second = longRopeTravel[0].second + directions[direction].second;
            for (int j = 1; j < 10; j++) {
                if (!ManhattanDistance(longRopeTravel[j - 1], longRopeTravel[j])) {
                    int x = longRopeTravel[j].first - longRopeTravel[j - 1].first;
                    int y = longRopeTravel[j].second - longRopeTravel[j - 1].second;

                    if (x < 0)
                        longRopeTravel[j].first = longRopeTravel[j].first + 1;
                    else if (x > 0)
                        longRopeTravel[j].first = longRopeTravel[j].first - 1;

                    if (y < 0)
                        longRopeTravel[j].second = longRopeTravel[j].second + 1;
                    else if (y > 0)
                        longRopeTravel[j].second = longRopeTravel[j].second - 1;
                }
            }
            longTailPositions.insert(longRopeTravel[9]);
            tailPositions.insert(longRopeTravel[1]);
        }
    }

    fin.close();

    std::cout << "Solution 1 of Day 9 is: " << tailPositions.size() << std::endl;
    std::cout << "Solution 2 of Day 9 is: " << longTailPositions.size() << std::endl;

}
