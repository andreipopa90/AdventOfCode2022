#include "Day7.h"
#include "fstream"
#include "vector"

struct Folder{
    int size = 0;
    std::vector<Folder*> next = static_cast<std::vector<Folder *>>(0);
    Folder *prev = nullptr;
    std::string name;
    Folder(Folder* previous, std::string name) {
        this->prev = previous;
        this->name = std::move(name);
    }

}*root;

int sizeSum, directorySizeToDelete;

Folder* FindFolder(Folder* folder, const std::string& folderName) {
    if (folder->name == folderName && folderName == "/") return root;
    for(auto& i : folder->next) {
        if (i->name == folderName) return i;
    }
    return nullptr;
}

void FindSizes(Folder* folder, int &lowestSizeSum, int minimumToDelete, int& sizeToDelete) {
    for (auto& i: folder->next) {
        lowestSizeSum = i->size <= 100000 ? lowestSizeSum + i->size : lowestSizeSum;
        sizeToDelete = i->size >= minimumToDelete && i->size < sizeToDelete ? i->size : sizeToDelete;
        FindSizes(i, lowestSizeSum, minimumToDelete, sizeToDelete);
    }
}

void Day7::ReadFile() {

    printf("Day 7\n");
    std::ifstream fin("../Input/Day7.txt");
    std::string inputLine, inputToken;

    root = new Folder(nullptr, "/");
    Folder* currentFolder = root;

    while (std::getline(fin, inputLine)) {
        // Don't care about ls
        if (inputLine[0] == '$' && inputLine.find("cd") != -1) {
            // Folder name is at the end
            inputToken = inputLine.substr(inputLine.find_last_of(' ') + 1, inputLine.size());
            // Go down or up one level
            currentFolder = inputToken == ".." ? currentFolder->prev : FindFolder(currentFolder, inputToken);
        }

        // Add new directory to the folder structure
        else if (inputLine.find("dir") != -1) {
            // Folder name is at the end
            inputToken = inputLine.substr(inputLine.find_last_of(' ') + 1, inputLine.size());
            auto* newFolder = new Folder(currentFolder, inputToken);
            currentFolder->next.push_back(newFolder);
        }

        // Update size of directory and all sizes until the root
        else if ('0' <= inputLine[0] && inputLine[0] <= '9') {
            // Filesize is at the beginning
            inputToken = inputLine.substr(0, inputLine.find(' '));
            currentFolder->size += stoi(inputToken);
            Folder* iterator = currentFolder;
            // Update the sizes of the parent folders
            while (iterator->name != "/") {
                iterator = iterator->prev;
                iterator->size += stoi(inputToken);
            }
        }
    }

    fin.close();
}

void Day7::Solution1() {
    int minimumToDelete = 30000000 - 70000000 + root->size;
    // Start from root cause that is the biggest one at first and would free the most space
    directorySizeToDelete = root->size;
    FindSizes(root, sizeSum, minimumToDelete, directorySizeToDelete);
    printf("Solution 1 of Day 7 is: %d\n", sizeSum);
}

void Day7::Solution2() {
    printf("Solution 2 of Day 7 is: %d\n", directorySizeToDelete);
}
