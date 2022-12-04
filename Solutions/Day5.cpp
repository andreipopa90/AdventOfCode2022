//
// Created by popaa on 04/12/2022.
//

#include <iostream>
#include "Day5.h"

void Day5::ReadFile() {

    std::cout << "Day 5" << std::endl;

    FILE *file = fopen("../Input/Day5.txt", "r");
    char line[100];
    while(fscanf(file, "%s", line) != EOF){

    }
    fclose(file);

}

void Day5::Solution1() {
    std::cout << "Solution 1 of Day 5 is: " << std::endl;
}

void Day5::Solution2() {
    std::cout << "Solution 2 of Day 5 is: " << std::endl;
}
