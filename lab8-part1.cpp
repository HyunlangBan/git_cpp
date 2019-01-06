//==============================================================================
// Filename     : lab8-part1.cpp
// Author       : Hyunlang Ban, Justen Koo
// Date         : November 8 2018
// Description  : struct for lab 5
//==============================================================================

#include <iostream>
using namespace std;

/**
 *
 * @return The exit status.
 */
struct ToDoList{
    string toDo;
    bool done;
};

int main()
{
    const int MAX_ITEMS = 1000;
    int size = 0, i;
    char menuChoice;

    ToDoList todo[MAX_ITEMS];
    
    cout << string(60, '=') << endl
         << "Welcome to the TODO List (c)." << endl
         << string(60, '=') << endl;
         
    do {
        cout << "Please choose one of the following options:" << endl
             << "  * [a]dd an item to the list" << endl
             << "  * [m]ark an item as done" << endl
             << "  * list the [u]ndone items" << endl
             << "  * list the [d]one items" << endl
             << "  * [r]emove an item" << endl
             << "  * [q]uit the program" << endl;
        
        cout << "Option: ";
        cin >> menuChoice;
        
        // In the event the user entered multiple characters, ignore all of it
        // until the next newline.
        cin.ignore(1000, '\n');
        
        // Case-normalize the user's choice.
        menuChoice = tolower(menuChoice);
        
        switch(menuChoice){
            // Quit.
            case 'q':
                break;
            
            // Add a note.
            case 'a':
                if(size >= MAX_ITEMS){
                    cout << "Sorry, the todo list is at capacity. Please "
                         << "remove an item before adding a new one." << endl;
                    break;
                }
                
                cout << endl
                     << "Please enter your todo item and press enter when "
                     << "complete." << endl << "> ";

                getline(cin, todo[size].toDo);
                todo[size].done = false;
                size++;
                
                cout << endl;
                break;
                
            // Mark an item as done.
            case 'm':
                do {
                    cout << "Please enter the index of the item to mark done "
                         << "(between 0 and " << size-1 << "): ";
                    cin >> i;
                } while(i < 0 || i >= size);
                
                while(i >= size){
                    cout << "No note with that index exists. Please try again: ";
                    cin >> i;
                }
                cin.ignore();
                todo[i].done = true;
                break;
                
            // List undone items.
            case 'u':
                cout << endl << "Undone items" << endl 
                     << string(60, '-') << endl;
                for(i = 0; i < size; i++){
                    if(!todo[i].done){
                        cout << i << ": " << todo[i].toDo << endl;
                    }
                }
                cout << endl;
                break;
                
            // List done items.
            case 'd':
                cout << endl << "Done items" << endl 
                     << string(60, '-') << endl;
                for(i = 0; i < size; i++){
                    if(todo[i].done){
                        cout << i << ": " << todo[i].toDo << endl;
                    }
                }
                cout << endl;
                break;

            // Remove an item.
            case 'r':
                do {
                    cout << "Please enter the index of the item to remove "
                         << "(between 0 and " << size-1 << "): ";
                    cin >> i;
                } while(i < 0 || i >= size);
                
                cout << "Removed item at index " << i << ": " << todo[i].toDo 
                     << "." << endl;
                
                for(int x = i; x < size-1; x++){
                    todo[x].toDo = todo[x+1].toDo;
                    todo[x].done = todo[x+1].done;
                }
                
                size = size-1;
                
                break;
                
            // Unknown option.
            default: 
                cout << "Unrecognized option." << endl;
        }
        
    } while(menuChoice != 'q');

    return 0;
}