//==============================================================================
// Filename     : lab9-part3.cpp
// Author       : Hyunlang Ban
// Date         : 06-December-2018
// Description  : Implement a partially working Todo List application in Curses.
// Collaborators: Samuel Page
//==============================================================================
#include <iostream>
#include <cstdlib>
using namespace std;

// Different platforms need different header files. Here's how, using
// most C++ compilers, you can include different libraries for different
// operating systems.
#ifdef _WIN32
#include <curses.h>
#elif __APPLE__
#include <ncurses.h>
#elif __linux
#include <ncurses.h>
#endif

struct Border
{
    int maxWidth, maxHeight;
    char borderChar;
};

struct ToDoList
{
    string todo;
    bool done;
};

const static char BORDER_CHAR = char(219);
const int MAX_INPUT_SIZE = 100;
const int MAX_TODOS = 500;

void drawBorder(Border &border);
void initializeBoard(Border &border);
void clearWindow();
void drawMenu(Border &border, ToDoList &todoItems, int &size);
void drawToDoList(ToDoList &todoItems, int &size);
int charArrayToInt(char numAsString[]);

/**
 * Displays a prompt for the user to enter their initials.
 *
 * @return The exit status.
 */
int main()
{
    int size = 0;
    Border border;
    ToDoList todoItems[MAX_TODOS];
    border.borderChar = BORDER_CHAR;
    initializeBoard(border);
    drawMenu(border, todoItems[size], size);
    return 0;
}

/**
 * Initialize board.
 *
 * @param border A Border instance.
 */
void initializeBoard(Border &border)
{
    // initscr() is a function defined by ncurses/pdcurses. It initializes
    // the screen.
    initscr();

    // Says to not wait for the user to enter a key when getch is called -- just
    // start processing.
    nodelay(stdscr, true);

    // Allows the user to touch all keys, including F1-12, up, down, etc.
    keypad(stdscr, true);

    // If user presses a key, it won't be written to the screen.
    noecho();

    // Removes the cursor.
    curs_set(0);

    // Get the max width and height.
    getmaxyx(stdscr, border.maxHeight, border.maxWidth);

    // Draws the border.
    drawBorder(border);
}

/**
 * Draw a border.
 *
 * @param border A Border instance.
 */
void drawBorder(Border &border)
{
    // Draw the the top border.
    for (int i = 0; i < border.maxWidth; i++)
    {
        move(0, i);
        addch(border.borderChar);
    }
    // Draw the bottom border.
    for (int i = 0; i < border.maxWidth; i++)
    {
        move(border.maxHeight - 2, i);
        addch(border.borderChar);
    }
}

/**
 * remove all characters from the screen.
 *
 */
void clearWindow()
{
    clear();
}


/**
 * Draw a menu.
 *
 * @param border A Border instance.
 * @param todoItems A ToDoList instance. 
 * @param size the size in main memory
 */
void drawMenu(Border &border, ToDoList &todoItems, int &size)
{
    // This is a character array -- it's like a string. It only holds 3
    // characters, plus a '\0' -- the end of string character.
    char userInput[MAX_INPUT_SIZE + 1];
    do
    {

        clear();
        drawBorder(border);
        // Initialize ncurse stuff.
        initscr();
        nodelay(stdscr, false); // Wait for user input.
        keypad(stdscr, true);   // Interpret all keyboard keys.
        curs_set(1);            // Display the cursor.
        echo();                 // Makes user inputs display on the screen.

        // Prompt the user.
        mvprintw(border.maxHeight - 3, 10, "Menu -- [a]dd todo; [m]ark item as done; [q]uit: ");

        // Read in only three characters.
        getnstr(userInput, 1);

        //if user enter a(add):
        if (userInput[0] == 'a')
        {
            //clear();
            move(border.maxHeight - 4, 10);
            clrtoeol();

            //print "you selected to add a todo"
            mvprintw(border.maxHeight - 4, 10, "Enter todo item: ");
            getnstr(userInput, MAX_INPUT_SIZE);

            todoItems.todo = string(userInput);

            move(border.maxHeight - 4, 10);
            clrtoeol();
            mvprintw(border.maxHeight - 4, 10, "You added: %s", todoItems.todo.c_str());

            drawToDoList(todoItems, size);

            //mark as undone
            todoItems.done = false;

            //drawtodolist
            size++;

            //else if user enter m(mark as done)
        }
        else if (userInput[0] == 'm')
        {
            move(border.maxHeight - 4, 10);
            clrtoeol();

            mvprintw(border.maxHeight - 4, 10, "Please enter the index of the item to mark done: ");
            getnstr(userInput, MAX_INPUT_SIZE);

            todoItems.done = true;

            move(border.maxHeight - 4, 10);
            clrtoeol();
            mvprintw(border.maxHeight - 4, 10, "%s is marked as done", todoItems.todo.c_str());

            //else if user enter q(quit)
        }
        else if (userInput[0] == 'q')
        {
            //print "your selected to quit"
            mvprintw(border.maxHeight - 4, 10, "You selected to quit.");

            //else:
        }
        else
        {
            // print "invalid option"
            mvprintw(7, 10, "invalid option");
        }

        getch(); // wait for user's input
    } while (userInput[0] != 'q');

    // Don't exit until the user presses another key.
    endwin();
}

void drawToDoList(ToDoList &todoItems, int &size)
{
}

int charArrayToInt(char numAsString[])
{

    return 0;
}
