//==============================================================================
// Filename     : lecture11-sorting-algorithms.cpp
// Author       : CSC160 class
// Date         : 23-Apr-2018
// Description  : Sorts and prints a list of strings using a user-specified 
//                sorting method.
//==============================================================================
 
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
 
const int CAPACITY = 1000;
 
void readInDataFile(string filename, string values[], int &size, int maxSize);
void bubbleSort(string values[], int size);
void selectionSort(string values[], int size);
void insertionSort(string values[], int size);
void printValues(string values[], int size);
 
/**
 * Sorts and prints a list of numbers using a user-specified sorting method.
 *
 * @return The exit status.
 */
int main()
{
    string filename;
    string values[CAPACITY];
    int size, menuChoice;
 
    cout << "Please enter the name of the file of whitespace-separated "
         << "strings to sort: ";
    getline(cin, filename);
 
    cout << "Which sort would you like to use?"<< endl
         << "  1) bubble sort" << endl
         << "  2) selection sort" << endl
         << "  3) insertion sort" << endl
         << "choice: ";
    cin >> menuChoice;
 
    readInDataFile(filename, values, size, CAPACITY);
 
    if(menuChoice == 1){
        bubbleSort(values, size);
    } else if(menuChoice == 2){
        selectionSort(values, size);
    } else if(menuChoice == 3){
        insertionSort(values, size);
    }
 
    printValues(values, size);
 
    return 0;
}
 
/**
 * Reads in a file of whitespace-separated strings into an array.
 *
 * @param filename The name of the file to read.
 * @param values The array to store the numbers in.
 * @param size The number of numbers read in.
 * @param maxSize The max number of numbers to read in.
 */
void readInDataFile(string filename, string values[], int &size, int maxSize){
    size = 0;
    ifstream fin(filename.c_str());
    if(fin.good()){
        while(fin.good() && size < maxSize){
            fin >> values[size];
            if(fin.good()){
                size++;
            }
        }
    } else {
        cerr << "Could not open the file." << endl;
    }
    fin.close();
}
 
/**
 * Sorts a list of strings using Bubble Sort.
 *
 * @param list The list to sort.
 * @param size The size of list.
 */
void bubbleSort(string list[], int size){
    // TODO
    int swaps = 1;
    string temp;

    while(swaps > 0){
        swaps = 0;
        for(int i=0; i < size-1; i++){
            if(list[i] > list[i+1]){
                temp = list[i];
                list[i] = list[i+1];
                list[i+1] = temp;
                swaps++;

            }
        }
    }
}
 
/**
 * Sorts a list of strings using Selection Sort.
 *
 * @param list The list to sort.
 * @param size The size of list.
 */
void selectionSort(string list[], int size){
    // TODO
}
 
/**
 * Sorts a list of strings using Insertion Sort.
 *
 * @param list The list to sort.
 * @param size The size of list.
 */
void insertionSort(string values[], int size){
    // TODO
    for(int i=1; i<size; i++){
        int j = i;
        string temp;
        while(j>0 && values[j-1]>values[j]){
                temp = values[j-1];
                values[j-1] = values[j];
                values[j] = temp;
                j--;
            }
    }
}
/**
 * Prints the given list of strings.
 *
 * @param list The list to print.
 * @param size The size of list.
 */
void printValues(string list[], int size){
    cout << "Data:" << endl;
    for(int i = 0; i < size; i++){
        cout << "  " << i << ". " << list[i] << endl;
    }
}