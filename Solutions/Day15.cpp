#include <cstdio>
#include "Day15.h"
#include <vector>
#include "algorithm"
#define SENSORS 34
#define LINE 2000000

std::vector<std::pair<int, int>> sensors(SENSORS);
std::vector<std::pair<int, int>> beacons(SENSORS);

void Day15::ReadFile() {

    scanf("Day 15\n");

    FILE* fin = fopen("../Input/Day15.txt", "r");
    int sensorX, sensorY, beaconX, beaconY;
    int index = 0;
    while(fscanf(fin, "Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d\n",
                 &sensorX, &sensorY, &beaconX, &beaconY) != EOF) {
        sensors[index] = {sensorX, sensorY};
        beacons[index] = {beaconX, beaconY};
        index++;
    }

    fclose(fin);
}

void Day15::Solution1() {

    int noBeacons = 0;
    std::vector<std::pair<int, int>> ranges;

    for (int s = 0; s < SENSORS; s++) {
        int manhattan = std::abs(sensors[s].first - beacons[s].first) +
                std::abs(sensors[s].second - beacons[s].second);
        int rowDifference = manhattan - std::abs(sensors[s].second - LINE);
        if (rowDifference >= 0) {
            std::pair<int, int> range = {-rowDifference + sensors[s].first, rowDifference + sensors[s].first};
            ranges.push_back(range);
        }
    }

    std::sort(ranges.begin(), ranges.end());

    std::pair<int, int> previous = ranges[0];
    for (int i = 1; i < ranges.size(); i++) {
        if (ranges[i].first <= previous.second && ranges[i].second > previous.second)
        {
            previous = {previous.first, ranges[i].second};
        } else if (ranges[i].first > previous.second) {
            noBeacons += (previous.second - previous.first);
        }
    }
    noBeacons += (previous.second - previous.first);

    printf("Solution 1 of Day 15 is: %d\n", noBeacons);

}

void Day15::Solution2() {


    std::vector<std::pair<int, int>> ranges;
    int manhattanDistance[SENSORS];
    for (int i = 0; i < SENSORS; i++) {
        manhattanDistance[i] = std::abs(sensors[i].first - beacons[i].first) +
                               std::abs(sensors[i].second - beacons[i].second);
    }

    bool found = false;
    for (int line = 0; line <= LINE * 2 && !found; line++) {
        for (int s = 0; s < SENSORS; s++) {
            int rowDifference = manhattanDistance[s] - std::abs(sensors[s].second - line);
            if (rowDifference >= 0) {
                std::pair<int, int> range = {std::max(0, -rowDifference + sensors[s].first),
                                             std::min(LINE * 2, rowDifference + sensors[s].first)};
                ranges.push_back(range);
            }
        }

        std::sort(ranges.begin(), ranges.end());

        std::pair<int, int> previous = ranges[0];
        for (int i = 1; i < ranges.size(); i++) {
            if (ranges[i].first <= previous.second && ranges[i].second > previous.second) {
                previous = {previous.first, ranges[i].second};
            } else if (ranges[i].first == previous.second + 2) {
                long long coordinate = (ranges[i].first + previous.second) / 2;
                long long result = coordinate * LINE * 2 + line;
                printf("Solution 2 of Day 15 is: %lld\n", result);
                found = true;
                break;
            }
        }
        ranges.clear();
    }
}
