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
    std::cout << "First Door will always be picked first and changed afterwards\n";
    while (numberOfTriesAux--) {
        int doorToTry = 0;
        unsigned int doors[numberOfDoors];
        for (int i = 0; i < numberOfDoors; ++i) {
            doors[i] = 0;
        }
        srand((numberOfDoors + numberOfTries) * time(NULL) + rand());
        int winningDoor = rand() % numberOfDoors; // usa castigatoare
        doors[winningDoor] = 1;
        doorToTry = 0;
        int numberOfOpened = 0;
        for (int i = 0; i < numberOfDoors; ++i) {
            if (i != doorToTry && doors[i] == 0 && numberOfOpened < numberOfOtherDoors - 1) {
                doors[i] = 2;
                numberOfOpened++;
            }
        }
        if (doors[doorToTry] == 0) {
            wins++;
        }
    }
    std::cout << "You had a winrate of: " << (wins * 100.0) / numberOfTries << "%\n";
    return 0;
}