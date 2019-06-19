#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
    int numberOfTries = 0;
    int numberOfDoors = 3;
    int numberOfOtherDoors = 2;
    int wins = 0;

    std::cout << "Run default test? [y/n]\n";
    char answer;
    std::cin >> answer;
    if (answer == 'n') {
        std::cout << "Insert the number of doors for the Monty Hall problem\n";
        std::cin >> numberOfDoors;
        numberOfOtherDoors = numberOfDoors - 1;
    }
    std::cout << "Insert the number of tests for the Monty Hall problem\n";
    std::cin >> numberOfTries;
    int numberOfTriesAux = numberOfTries;
    while (numberOfTriesAux--) {
        int doorToTry = 0;
        unsigned int doors[numberOfDoors];
        for (int i = 0; i < numberOfDoors; ++i) {
            doors[i] = 0;
        }
        srand((numberOfDoors + numberOfTries) * time(NULL));
        doors[rand() % numberOfDoors] = 1; // usa castigatoare
        std::cout << "Pick a Door to begin\n";
        do {
            std::cin >> doorToTry;
        } while (doorToTry < 0 || doorToTry > numberOfDoors);
        std::cout << "Unlucky Doors will be opened now\n";
        int numberOfOpened = 0;
        for (int i = 0; i < numberOfDoors; ++i) {
            if (i != doorToTry && doors[i] == 0 && numberOfOpened < numberOfOtherDoors - 1) {
                doors[i] = 2;
                numberOfOpened++;
            }
        }
        std::vector<int> remainingDoors;
        for (int i = 0; i < numberOfDoors; ++i) {
            if (doors[i] != 2) {
                remainingDoors.push_back(i);
            }
        }
        std::cout << "The remaining doors are:";
        for (auto& doorNr : remainingDoors) {
            std::cout << doorNr << " ";
        }
        std::cout << std::endl;
        std::cout << "Keep choice? [y/n]\n";
        std::cin >> answer;
        if (answer == 'n') {
            do {
            std::cin >> doorToTry;
            } while (doorToTry < 0 || doorToTry > numberOfDoors);
        } 
        if (doors[doorToTry] == 1) {
            std::cout << "You Won\n";
            wins++;
        } else {
            std::cout << "You Lost\n";
        }
    }
    std::cout << "You had a winrate of:" << (wins * 100.0) / numberOfTries << "%\n";
    return 0;
}