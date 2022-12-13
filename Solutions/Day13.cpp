#include <fstream>
#include <iostream>
#include "Day13.h"
#include "vector"
#include "sstream"

#define PACKETS 8
std::pair<std::string, std::string> packetPairs[PACKETS];

void Day13::ReadFile() {

    std::ifstream fin("../Input/Day13.txt");
    std::string packetsOne, packetsTwo, emptyLine;


    for (auto & packetPair : packetPairs){
        getline(fin, packetsOne);
        getline(fin, packetsTwo);
        getline(fin, emptyLine); //don't care but I got to read this
        packetPair = {packetsOne, packetsTwo};
    }

    for(const auto &packets: packetPairs){
        std::cout << packets.first << '\n';
        std::cout << packets.second << '\n';
    }

    fin.close();

}

void Day13::Solution1() {

    for (const auto &packets: packetPairs) {
        std::stringstream ssOne(packets.first);
        std::stringstream ssTwo(packets.second);
        std::string packet;
        std::vector<std::string> packetsOne;
        std::vector<std::string> packetsTwo;

        while(getline(ssOne, packet, ',')) {
            packetsOne.emplace_back(packet);
        }
        while(getline(ssTwo, packet, ',')) {
            packetsTwo.emplace_back(packet);
        }

    }


}

void Day13::Solution2() {

}
