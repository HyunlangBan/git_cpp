//==============================================================================
// Filename     : lab7-part2.cpp
// Author(s)    : Justen Koo, Hyunlang Ban
// Date         : 1 November 2018
// Description  : Determines average number of rolls to get snake eyes
//==============================================================================
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

// Function Declarations
int rollDie();
bool isSnakeEyes();
int countRollsToSnakeEyes ();
int runTrials (int userTrials, int averageRolls);

// Other Declarations
int userTrials;
int trialCount = 0;
bool gameStatus;
int dieNumber;

int main() {
srand(time(0));
int averageRolls;
int firstRoll;
int secondRoll;

    // Prompt user to enter # of trials
    cout << "Please enter the number of how many trials you would like to conduct: ";
    cin >> userTrials;
    // Invoke runTrials until equal to user's input
    for (int i = 0; i < userTrials; i++) {
        runTrials(userTrials, averageRolls);
    }
    // Display the average amount of rolls
    cout << "The average number of rolls is " << averageRolls << " rolls.";
    return 0;
}

// Function Definitions
/**
* rolls a single die (generates a random number 1 - 6)
* @return
*/
int rollDie() {
    // generate a random number from 1 - 6 and assign it to dieNumber
    dieNumber = rand() % 6 + 1;
    return dieNumber;
}

/**
* roll two dice and return whether or not they are snake eyes
* @return isSnakeEyes if snake eyes
*/
bool isSnakeEyes() {
    int firstRoll = rollDie();
    int secondRoll = rollDie();
        if (firstRoll == 1 && secondRoll == 1) {
            gameStatus = true;
        }
        else {
            gameStatus = false;
            trialCount++;
        }
    return 0;
}

/**
* counts the number of times isSnakeEyes is called until it returns true
* @return
*/
int countRollsToSnakeEyes() {
    // invoke isSnakeEyes until gameStatus returns as true
    isSnakeEyes();
    return trialCount;
}

/**
* Runs countRollsToSnakeEyes until equal to userTrials and calculates average # of rolls to get snake eyes
* @param usertrials
* @param averageRolls
* @return averageRolls
*/
int runTrials(int userTrials, int averageRolls) {
    countRollsToSnakeEyes();
    averageRolls = (trialCount/userTrials);
    return 0;
}