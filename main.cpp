#include "Solutions/Day1.h"
#include "Solutions/Day2.h"
#include "Solutions/Day3.h"
#include "Solutions/Day4.h"
#include "Solutions/Day5.h"
#include "Solutions/Day6.h"
#include "Solutions/Day7.h"
#include "Solutions/Day8.h"

int main(){
    Day1 day1;
    day1.ReadFile();
    day1.Solution1();
    day1.Solution2();

    Day2 day2;
    day2.ReadFile();
    day2.Solution1();
    day2.Solution2();

    Day3 day3;
    day3.ReadFile();
    day3.Solution1();
    day3.Solution2();

    Day4 day4;
    day4.Solution();

    Day5 day5;
    day5.ReadFile();
    day5.Solution1();
    day5.Solution2();

    Day6 day6;
    day6.ReadFile();
    day6.Solution1();
    day6.Solution2();

    Day7 day7;
    day7.ReadFile();
    day7.Solution1();
    day7.Solution2();

    Day8 day8;
    day8.ReadFile();
    day8.Solution1();
    day8.Solution2();
}