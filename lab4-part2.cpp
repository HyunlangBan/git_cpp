// File:     lab4-part1.cpp
// Author:   Hyunlang Ban, Justen Koo
// Date:     10/04/2018
#include <iostream>
#include <string>
using namespace std;

int main(){
string userInput;
int numWords = 1;
int numVow = 0;
int numCon = 0;
float avVow = 0;
float avCon = 0;

/*Prompt user to enter a full line of text*/
cout << "Please enter a full line of text" << endl;
getline(cin, userInput);

//count the number of vowels
for (int i = 0; i < userInput.size(); i++) {
    if (userInput.at(i) == 'a' || userInput.at(i) == 'e' || userInput.at(i) == 'o' || userInput.at(i) == 'u' || userInput.at(i) == 'i')  {
        numVow = numVow + 1;
    }
    else if (userInput.at(i) == ' ')   {
        numWords = numWords + 1;
    }
    else if (userInput.at(i) == '.' || userInput.at(i) == '?' || userInput.at(i) == '!' || userInput.at(i) == ',')   {
        break;
    }
    else {
        numCon = numCon + 1;
    }
}
//Calculate average vowels and average consonants
avVow = numVow / numWords;
avCon = numCon / numWords;

//Display number of vowels, words, consonants, average vowels and average consonants
cout << "The number of vowels is: " <<numVow << endl;
cout << "The number of words is: " << numWords << endl;
cout << "The number of consants are: " << numCon << endl;
cout << "The average number of vowels is: " << avVow << endl;
cout << "The average number of consonants is: " << avCon << endl;
    return 0;
}