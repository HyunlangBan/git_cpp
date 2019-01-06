// File:    books.cpp
// Author:  Hank Feild
// Date:    05-Nov-2018
// Purpose: Keeps track of a list of library books added by the user.

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_BOOKS = 3;

/**
 * Stores information about a book.
 */
struct Book {
    string author, title;
    int yearPublished, pageCount;
};

/**
 * Stores information about a library book.
 */
struct LibraryBook {
    Book bookInfo;
    int numCopies, copiesCheckedOut;
};

void addLibraryBook(LibraryBook books[], int &size, int capacity);
void listLibraryBooks(LibraryBook books[], int size);
LibraryBook newLibraryBook(); 
void printLibraryBook(LibraryBook libraryBook);

/**
 * Presents the user with a menu to add or list library books, or quit.
 * 
 * @return Exit status (0 is good).
 */
int main(){
    LibraryBook books[MAX_BOOKS];
    int size = 0;
    string menuChoice;

    do {
        // Display menu.
        cout << endl;
        cout << string(80, '=') << endl;
        cout << "== MENU" << endl;
        cout << string(80, '=') << endl;
        cout << "- [a]dd a new book" << endl;
        cout << "- [l]ist books" << endl;
        cout << "- [q]uit" << endl;
        cout << endl;
        cout << "Your choice: ";
        cin >> menuChoice;
        cin.ignore();
        cout << endl;

        // Process the user's choice.
        if(menuChoice == "a"){
            addLibraryBook(books, size, MAX_BOOKS);
        } else if(menuChoice == "l"){
            listLibraryBooks(books, size);
        } else if(menuChoice != "q"){
            cout << "ERROR: Invalid option." << endl;
        }

    } while(menuChoice != "q");

    return 0;
}

/**
 * Adds a new library book or displays an error if the array is at capacity.
 * 
 * @param books The array of books to add the new book to.
 * @param size The number of books currently in the array (will be modified).
 * @param capacity The maximum number of books the array may contain.
 */
void addLibraryBook(LibraryBook books[], int &size, int capacity){
    if(size >= capacity){
        cout << "Error: the list of books is at capacity; please remove "
             << "one or more books before adding a new one." << endl;
        return;
    }

    cout << string(80, '*') << endl;
    cout << "** Add new book" << endl;
    cout << string(80, '*') << endl;

    books[size] = newLibraryBook();
    size++;
}

/**
 * Displays all of the books in the given array.
 * 
 * @param books The array of books to list.
 * @param size The number of books currently in the array.
 */
void listLibraryBooks(LibraryBook books[], int size){
    // Display each book.
    for(int i = 0; i < size; i++){
        // Print a banner above each book.
        cout << string(12, '-') << endl;
        cout << "| Book " << setw(3) << i << " |" << endl;
        cout << string(12, '`') << endl;

        // Print the book information.
        printLibraryBook(books[i]);
        cout << endl;
    }
}

/**
 * Creating a new LibraryBook instance and reading the information in from the
 * user.
 * 
 * @return The new LibraryBook instance.
 */
LibraryBook newLibraryBook() {
    // Create the new instance.
    LibraryBook libraryBook;

    // Prompt the user for each piece of information.
    // author
    cout << "Enter author's name: ";
    getline(cin, libraryBook.bookInfo.author);

    // title
    cout << "Enter title: ";
    getline(cin, libraryBook.bookInfo.title);

    // pub year
    cout << "Enter year published: ";
    cin >> libraryBook.bookInfo.yearPublished;

    cout << "Enter page count: ";
    cin >> libraryBook.bookInfo.pageCount;

    // Num copies
    cout << "Enter number of copies in the library: ";
    cin >> libraryBook.numCopies;

    // copies checked out
    cout << "Enter number of copies currently checked out: ";
    cin >> libraryBook.copiesCheckedOut;

    cin.ignore();

    // Return the instance.
    return libraryBook;
}

/**
 * Display a LibraryBook's info.
 * 
 * @param libraryBook The book to display.
 */
void printLibraryBook(LibraryBook libraryBook){
    // author
    cout << "Author:    " << libraryBook.bookInfo.author << endl;
    // title
    cout << "Title:     " << libraryBook.bookInfo.title << endl;
    // year published
    cout << "Year Pub.: " << libraryBook.bookInfo.yearPublished << endl;
    // page count
    cout << "Pages:     " << setw(4) << libraryBook.bookInfo.pageCount << endl;
    // num copies
    cout << "Copies:    " << setw(4) << libraryBook.numCopies << endl;
    // copies checked out
    cout << "Out:       " << setw(4) << libraryBook.copiesCheckedOut << endl;
}
