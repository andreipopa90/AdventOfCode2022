//
// Created by popaa on 06/12/2022.
//

#include <iostream>
#include <map>
#include "Day7.h"
#include "fstream"
#include "sstream"
#include "vector"

struct Folder{
    int size;
    std::vector<Folder*> next;
    Folder *prev;
    std::string name;
}*root;

Folder* FindFolder(Folder* folder, const std::string& folderName) {
    if (folder->name == folderName && folderName == "/") return root;
    for(auto& i : folder->next) {
        if (i->name == folderName) return i;
    }
    return nullptr;
}

void FindSizes(Folder* folder, int &size) {
    for (auto& i: folder->next) {
        size = i->size <= 100000 ? size + i->size : size;
        FindSizes(i, size);
    }
}

void FindHighestSizes(Folder* folder, int minimumToDelete, int& sizeToDelete) {

    for (auto& i: folder->next) {
        sizeToDelete = i->size >= minimumToDelete && i->size < sizeToDelete ? i->size : sizeToDelete;
        FindHighestSizes(i, minimumToDelete, sizeToDelete);
    }

}

void Day7::ReadFile() {

    std::cout << "Day 7" << std::endl;
    std::ifstream fin("../Input/Day7.txt");
    std::string inputLine, inputToken;

    root = new Folder;
    root->size = 0;
    root->name = "/";
    root->prev = nullptr;
    root->next = static_cast<std::vector<Folder *>>(0);
    Folder* currentFolder = root;

    while (std::getline(fin, inputLine)) {
        std::stringstream splitter(inputLine);

        // Don't care about ls
        if (inputLine[0] == '$' && inputLine.find("cd") != -1) {
            while(std::getline(splitter, inputToken, ' ')) {}
            // Go down or up one level
            if (inputToken != "..")
                currentFolder = FindFolder(currentFolder, inputToken);
            else {
                currentFolder = currentFolder->prev;
            }
        }

        // Add new directory to the folder structure
        else if (inputLine.find("dir") != -1) {
            while(std::getline(splitter, inputToken, ' ')) {}
            auto* newFolder = new Folder;
            newFolder->name = inputToken;
            newFolder->prev = currentFolder;
            newFolder->next = static_cast<std::vector<Folder *>>(0);
            newFolder->size = 0;
            currentFolder->next.push_back(newFolder);
        }

        // Update size of directory and all sizes until the root
        else if ('0' <= inputLine[0] && inputLine[0] <= '9') {
            std::getline(splitter, inputToken, ' ');
            currentFolder->size += stoi(inputToken);
            Folder* iterator = currentFolder;
            while (iterator->name != "/") {
                iterator = iterator->prev;
                iterator->size += stoll(inputToken);
            }
        }
        // Clear the string stream
        splitter.clear();
        splitter.str(std::string());
    }

    fin.close();
}

void Day7::Solution1() {

    int size = 0;
    FindSizes(root, size);
    std::cout << "Solution 1 of Day 7 is: " << size << std::endl;

}

void Day7::Solution2() {
    int maximumSize = 70000000;
    int minimumNeeded = 30000000;
    int minimumToDelete = minimumNeeded - maximumSize + root->size;
    // Start from root cause that is the biggest one at first and would free the most space
    int directorySizeToDelete = root->size;
    FindHighestSizes(root, minimumToDelete, directorySizeToDelete);
    std::cout << "Solution 2 of Day 7 is: " << directorySizeToDelete << std::endl;
}
