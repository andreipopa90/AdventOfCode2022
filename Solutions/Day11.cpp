#include <iostream>
#include "Day11.h"
#include "vector"
#include "sstream"
#include "algorithm"

#define MONKEYS 8

struct Monkey{

    std::vector<long long> worry;
    std::pair<char, int> operation;
    int test;
    int trueMonkeyIndex = -1;
    int falseMonkeyIndex = -1;
    long long inspected = 0;
}monkeys[MONKEYS], monkeysPart2[MONKEYS];
long long reduce;

void Day11::ReadFile() {

    std::cout << "Day 11\n";
    FILE *input = fopen("../Input/Day11.txt", "r");
    std::string line;
    for (int i = 0; i < MONKEYS; i++) {
        Monkey monkey;
        std::string line_one, item;
        int test, monkeyFalse, monkeyTrue, index;
        char number[10], operand, startItems[100];

        fscanf(input, "Monkey %d:\n", &index);
        fgets(startItems, 100, input);
        line_one = startItems;
        line_one = line_one.substr(line_one.find(": ") + 2);
        line_one.erase(line_one.length() - 1);
        std::stringstream ss(line_one);
        while (std::getline(ss, item, ',')) {
            monkey.worry.push_back(std::stoi(item));
        }
        ss.clear();

        fscanf(input, " Operation: new = old %c %s\n", &operand, number);
        monkey.operation = {operand, number[0] == 'o' ? -1 : std::stoi(number)};

        fscanf(input, " Test: divisible by %d\n", &test);
        monkey.test = test;

        fscanf(input, "  If true: throw to monkey %d\n", &monkeyTrue);
        monkey.trueMonkeyIndex = monkeyTrue;

        fscanf(input, "  If false: throw to monkey %d\n", &monkeyFalse);
        monkey.falseMonkeyIndex = monkeyFalse;
        monkeys[index] = monkey;
    }
    fclose(input);


}

void Day11::Solution1() {

    for (int i = 0; i < MONKEYS; i++) {
        monkeysPart2[i] = monkeys[i];
    }
    reduce = 1;
    for (int i = 0; i < MONKEYS; i++) {
        reduce *= monkeysPart2[i].test;
    }

    long long inspected[MONKEYS];

    for (int turn = 1; turn <= 20; turn++) {
        for (int i = 0; i < MONKEYS; i++) {
            monkeys[i].inspected += monkeys[i].worry.size();
            monkeysPart2[i].inspected += monkeysPart2[i].worry.size();
            for (int j = 0; j < monkeys[i].worry.size(); j++) {
                if (monkeys[i].operation.first == '*') {
                    monkeys[i].worry[j] = monkeys[i].operation.second == -1 ?
                                          monkeys[i].worry[j] * monkeys[i].worry[j]:
                                          monkeys[i].worry[j] * monkeys[i].operation.second;
                } else {
                    monkeys[i].worry[j] = monkeys[i].operation.second == -1 ?
                                          monkeys[i].worry[j] + monkeys[i].worry[j]:
                                          monkeys[i].worry[j] + monkeys[i].operation.second;
                }
                monkeys[i].worry[j] /= 3;

                if (monkeys[i].worry[j] % monkeys[i].test == 0) {
                    monkeys[monkeys[i].trueMonkeyIndex].worry.push_back(monkeys[i].worry[j]);
                } else {
                    monkeys[monkeys[i].falseMonkeyIndex].worry.push_back(monkeys[i].worry[j]);
                }

            }
            for (int j = 0; j < monkeysPart2[i].worry.size(); j++) {
                if (monkeysPart2[i].operation.first == '*') {
                    monkeysPart2[i].worry[j] =
                            monkeysPart2[i].operation.second == -1 ?
                            monkeysPart2[i].worry[j] * monkeysPart2[i].worry[j] :
                            monkeysPart2[i].worry[j] * monkeysPart2[i].operation.second;
                } else {
                    monkeysPart2[i].worry[j] =
                            monkeysPart2[i].operation.second == -1 ?
                            monkeysPart2[i].worry[j] + monkeysPart2[i].worry[j] :
                            monkeysPart2[i].worry[j] + monkeysPart2[i].operation.second;
                }

                monkeysPart2[i].worry[j] %= reduce;

                if (monkeysPart2[i].worry[j] % monkeysPart2[i].test == 0) {
                    monkeysPart2[monkeysPart2[i].trueMonkeyIndex].worry.push_back(monkeysPart2[i].worry[j]);
                } else {
                    monkeysPart2[monkeysPart2[i].falseMonkeyIndex].worry.push_back(monkeysPart2[i].worry[j]);
                }

            }
            monkeys[i].worry.clear();
            monkeysPart2[i].worry.clear();
        }
    }

    for (int i = 0; i < MONKEYS; i++) {
        inspected[i] = monkeys[i].inspected;
    }

    std::sort(inspected, inspected + MONKEYS);
    std::cout << "Solution 1 of Day 11 is: " << inspected[MONKEYS - 1] * inspected[MONKEYS - 2] << '\n';

}

void Day11::Solution2() {

    long long inspected[MONKEYS];

    for (int turn = 21; turn <= 10000; turn++) {
        for (int i = 0; i < MONKEYS; i++) {
            monkeysPart2[i].inspected += monkeysPart2[i].worry.size();
            for (int j = 0; j < monkeysPart2[i].worry.size(); j++) {
                if (monkeysPart2[i].operation.first == '*') {
                    monkeysPart2[i].worry[j] =
                            monkeysPart2[i].operation.second == -1 ?
                            monkeysPart2[i].worry[j] * monkeysPart2[i].worry[j] :
                            monkeysPart2[i].worry[j] * monkeysPart2[i].operation.second;
                } else {
                    monkeysPart2[i].worry[j] =
                            monkeysPart2[i].operation.second == -1 ?
                            monkeysPart2[i].worry[j] + monkeysPart2[i].worry[j] :
                            monkeysPart2[i].worry[j] + monkeysPart2[i].operation.second;
                }

                monkeysPart2[i].worry[j] %= reduce;

                if (monkeysPart2[i].worry[j] % monkeysPart2[i].test == 0) {
                    monkeysPart2[monkeysPart2[i].trueMonkeyIndex].worry.push_back(monkeysPart2[i].worry[j]);
                } else {
                    monkeysPart2[monkeysPart2[i].falseMonkeyIndex].worry.push_back(monkeysPart2[i].worry[j]);
                }

            }
            monkeysPart2[i].worry.clear();
        }
    }

    for (int i = 0; i < MONKEYS; i++) {
        inspected[i] = monkeysPart2[i].inspected;
    }
    std::sort(inspected, inspected + MONKEYS);

    std::cout << "Solution 2 of Day 11 is: " << inspected[MONKEYS - 1] * inspected[MONKEYS - 2] << '\n';

}
