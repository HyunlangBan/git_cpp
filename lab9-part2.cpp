//==============================================================================
// Filename     : lab9-part2.cpp
// Author       : Hank Feild
// Date         : 03-Nov-2014
// Description  : Demonstrates reading strings in from the user. 
//
//                To compile on Windows, do:
//                    g++ lab9-part2.cpp -lpdcurses -o lab9-part2
//                To compile on OSX or Linux, do:
//                    g++ lab9-part2.cpp -lncurses -o lab9-part2
// Collaborators: None.
//==============================================================================
#include <iostream>
#include <cstdlib>

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

/**
 * Displays a prompt for the user to enter their initials.
 *
 * @return The exit status.
 */
int main()
{
    // This is a character array -- it's like a string. It only holds 3
    // characters, plus a '\0' -- the end of string character.
    char initials[4]; 

    // Initialize ncurse stuff.
    initscr();
    nodelay(stdscr, false); // Wait for user input.
    keypad(stdscr, true);   // Interpret all keyboard keys.
    curs_set(1);            // Display the cursor.
    echo();                 // Makes user inputs display on the screen.

    // Prompt the user.
    mvprintw(5, 10, "Please enter your initials (up to 3): ");

    // Read in only three characters.
    getnstr(initials, 3);

    // Display the user's input a few lines below.
    mvprintw(7, 10, "Thanks, %s!; press any key to exit.", initials);

    // Don't exit until the user presses another key.
    getch();

    endwin();
    return 0;
}