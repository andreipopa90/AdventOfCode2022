//
// Created by popaa on 04/12/2022.
//

#include "Day4.h"
#include "iostream"

void Day4::ReadFile() {
    std::cout << "Day 4" << std::endl;
    FILE *fp = fopen("../Input/Day4.txt", "r");
    int start1, end1, start2, end2;
    int overlaps = 0;
    int overlaps2 = 0;

    while(fscanf(fp, "%d-%d,%d-%d", &start1, &end1, &start2, &end2) != EOF){
        if (start2 >= start1 && end2 <= end1 || start1 >= start2 && end1 <= end2) {
            overlaps += 1;
            overlaps2 += 1;
        }
        else if (start1 <= start2 && start2 <= end1 && end1 <= end2 ||
                start2 <= start1 && start1 <= end2 && end2 <= end1) {
            overlaps2 += 1;
        }
    }
    fclose(fp);
    std::cout << "Solution 1 of Day 4 is: " << overlaps << std::endl;
    std::cout << "Solution 2 of Day 4 is: " << overlaps2 << std::endl;
}

void Day4::Solution1() {

}

void Day4::Solution2() {

}
