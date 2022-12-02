#include "Solutions/Day1.h"
#include "Solutions/Day2.h"
#include "iostream"

int main(){
    Day1 day1;
    day1.ReadFile();
    day1.Solution1();
    day1.Solution2();
    std::cout << "------------------------------------" << std::endl;
    Day2 day2;
    day2.ReadFile();
    day2.Solution1();
    day2.Solution2();
}