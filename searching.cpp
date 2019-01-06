//==============================================================================
// Filename     : lecture11-searching-algorithms.cpp
// Author       : CSC160 class
// Date         : 02-Dec-2018
// Description  : Searches through a list of strings (read in from a file).
//==============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int CAPACITY = 1000;

void readInDataFile(string filename, string values[], int &size, int maxSize);
bool checkIfSorted(string values[], int size);
int linearSearch(string target, string values[], int size);
int binarySearch(string target, string values[], int size);

/**
 * Searches through a list of strings using a either linear or binary search
 * based on whether it's sorted or not.
 *
 * @return The exit status.
 */
int main()
{
    string filename, target, values[CAPACITY];
    int size, foundIndex;
    bool isSorted = false;

    // Read in the file.
    cout << "Please enter the name of the file of strings to search through: ";
    getline(cin, filename);
    readInDataFile(filename, values, size, CAPACITY);

    // Check if it's sorted.
    isSorted = checkIfSorted(values, size);
    cout<<"The data you entered is ";
    if(isSorted)
        cout<<"sorted!"<<endl;
    else
        cout<<"unsorted. :<"<<endl;

    // Search for the data.
    do {
        cout << "Enter a value to search, or QUIT to stop: ";
        cin >> target;
        if(target != "QUIT"){
            
            // Run binary search if sorted.
            if(isSorted){
                foundIndex = binarySearch(target, values, size);
                if(foundIndex > -1){
                    cout << target << " found at index " << foundIndex << endl;
                } else {
                    cout << target << " not found in list." << endl;
                }
                
            // Linear search otherwise.
            } else {
                foundIndex = linearSearch(target, values, size);
                if(foundIndex > -1){
                    cout << target << " found at index " << foundIndex << endl;
                } else {
                    cout << target << " not found in list." << endl;
                }
            }
        }
    } while(target != "QUIT");

    return 0;
}

/**
 * Reads in a file of whitespace-separated strings into an array.
 *
 * @param filename The name of the file to read.
 * @param nums The array to store the numbers in.
 * @param size The number of numbers read in.
 * @param maxSize The max number of numbers to read in.
 */
void readInDataFile(string filename, string list[], int &size, int maxSize){
    size = 0;
    ifstream fin(filename.c_str());
    if(fin.good()){
        while(fin.good() && size < maxSize){
            fin >> list[size];
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
 * Determines if all of the strings in list are sorted or not.
 *
 * @param list The list to sort.
 * @param size The size of list.
 * @return True if the list is sorted, false otherwise.
 */
bool checkIfSorted(string list[], int size){
    // iterate thorugh the list
    for(int i = 0; i < size-1 ; i++){
        // if two items should be swapped
        if(list[i+1]<list[i]){
            // return false
            return false;
        }
    }
        

    return true;
}

/**
 * Searches a list of strings for a target using linear search.
 *
 * @param target The string to find in the list.
 * @param list The list to search over.
 * @param size The size of list.
 */
int linearSearch(string target, string list[], int size){
    // TODO -- keep track of how many comparisons are made and
    // print that out before returning.
    int comparisions=0;

    for(int i = 0; i < size; i++){
        if(list[i]==target){
            cout<<"comparisions: "<<comparisions<<endl;
            return i;
        }
    comparisions++;
    }
    cout<<"comparisions: "<<comparisions<<endl;
    return -1;
}

/**
 * Searches a list of strings for a target using binary search.
 *
 * @param target The string to find in the list.
 * @param list The list to search over.
 * @param size The size of list.
 */
int binarySearch(string target, string list[], int size){
    // TODO -- keep track of how many comparisons are made and
    // print that out before returning.
    int comparisons = 0;
    
    int min = 0;
    int max = size - 1;
    int mid = (max+min)/2;
    while(min<=max){
        if (list[mid]==target){
            cout<<"_comparisions: "<<comparisons<<endl;
            return mid;//중간에 리턴이 나오면 바로 끝냄
        }
        else if (target < list[mid]){
            max = mid - 1;
            mid = (max+min)/2;
        }
        else{
            min = mid + 1;
            mid = (max+min)/2;
        }
        comparisons++;
    }
    cout<<"comparisions: "<<comparisons<<endl; //?

    return -1;
}
