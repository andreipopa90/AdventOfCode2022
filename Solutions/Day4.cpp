#include "Day4.h"
#include "iostream"

void Day4::Solution() {
    std::cout << "Day 4" << std::endl;
    FILE *fp = fopen("../Input/Day4.txt", "r");
    int start1, end1, start2, end2;
    int overlaps = 0;
    int overlaps2 = 0;

    while(fscanf(fp, "%d-%d,%d-%d", &start1, &end1, &start2, &end2) != EOF){
        if (start1 <= start2 && end2 <= end1 || start2 <= start1 && end1 <= end2) {
            overlaps += 1;
            overlaps2 += 1;
        }
        else if (std::max(start1, start2) <= std::min(end1, end2)) {
            overlaps2 += 1;
        }
    }
    fclose(fp);
    std::cout << "Solution 1 of Day 4 is: " << overlaps << std::endl;
    std::cout << "Solution 2 of Day 4 is: " << overlaps2 << std::endl;
}
