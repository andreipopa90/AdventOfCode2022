#include <iostream>
#include "chrono"
#include "Solutions/Day1.h"
#include "Solutions/Day2.h"
#include "Solutions/Day3.h"
#include "Solutions/Day4.h"
#include "Solutions/Day5.h"
#include "Solutions/Day6.h"
#include "Solutions/Day7.h"
#include "Solutions/Day8.h"
#include "Solutions/Day9.h"
#include "Solutions/Day10.h"
#include "Solutions/Day11.h"
#include "Solutions/Day12.h"
#include "Solutions/Day13.h"
#include "Solutions/Day14.h"
#include "Solutions/Day15.h"
#include "Solutions/Day16.h"

int main(){
    auto start = std::chrono::high_resolution_clock::now();
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
    day8.Solution();

    Day9 day9;
    day9.ReadFile();

    Day10 day10;
    day10.ReadFile();

    Day11 day11;
    day11.ReadFile();
    day11.Solution1();
    day11.Solution2();

    Day12 day12;
    day12.ReadFile();
    day12.Solution1();
    day12.Solution2();

    Day13 day13;
    day13.ReadFile();
    day13.Solution1();
    day13.Solution2();

//    Day14 day14;
//    day14.ReadFile();
//    day14.Solution1();
//    day14.Solution2();

    Day15 day15;
    day15.ReadFile();
    day15.Solution1();
//    day15.Solution2();

    Day16 day16;
    day16.ReadFile();
    day16.Solution1();
    day16.Solution2();

    auto stop = std::chrono::high_resolution_clock::now();
    long long duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    std::cout << "Time it took to complete in miliseconds: " << duration << std::endl;

}