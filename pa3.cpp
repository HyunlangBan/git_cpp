//==============================================================================
// Filename     : pa3.cpp
// Author(s)    : Hyunlang Ban
// Date         : 12/6
// Description  : A digital Rolodex program with ncurses screen.

// g++ pa3.cpp -lpdcurses -o pa3
//==============================================================================
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
#include <curses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Rolodex
{
    string firstName;
    string lastName;
    string email;
    string phoneNumber;
};

struct Border
{
    int maxWidth, maxHeight;
    char borderChar;
};

const static char BORDER_CHAR = char(219);
const int MAX_INPUT_SIZE = 100;
const int MAX_CONTACTS = 500;
const string DATABASE_NAME = "contacts.db";

// Function declarations.
void initializeBoard(Border &border);
void drawBorder(Border &border);
void loadContacts(Rolodex *&rolodex, int &size);
void saveContacts(Rolodex *&rolodex, int &size);

// TODO: Add your function declarations here.
void selectOptions(Border &border, Rolodex *rolodex, int &size);
void addContact(Border &border, Rolodex *&rolodex, int &size);
void listContacts(Border &border, Rolodex *&rolodex, int &size);
void updateContact(Border &border, Rolodex *&rolodex, int &size);
void removeContact(Border &border, Rolodex *&rolodex, int &size);
void findContacts(Border &border, Rolodex *&rolodex, int size);
int charArrayToInt(char *numAsString);
void clearWindow(Border &border);
/**
 * Prompts the user with a menu and processes the selected options until the
 * user quits.
 *
 * @return The exit status.
 */
int main()
{
    int size = 0;
    Border border;
    Rolodex rolodex[MAX_CONTACTS];
    border.borderChar = BORDER_CHAR;
    initializeBoard(border);
    selectOptions(border, rolodex, size);

    return 0;
}

/**
 * Loads contacts from the database file.
 *
 * @param rodoeldx An Instance or Rolodex.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 */
void loadContacts(Rolodex *&rolodex, int &size)
{

    size = 0;

    // Open the file.
    ifstream fin(DATABASE_NAME.c_str());

    // Read in the contacts. Each contact has one line for each attribute.
    while (fin.good() && size < MAX_CONTACTS)
    {
        getline(fin, rolodex[size].firstName);
        getline(fin, rolodex[size].lastName);
        getline(fin, rolodex[size].email);
        getline(fin, rolodex[size].phoneNumber);

        // Only increment the size if we were able to read in this contact's
        // details without errors.
        if (fin.good())
        {
            size++;
        }
    }

    fin.close();
}

/**
 * Saves the contacts to the database file.
 *
 * @param rodoeldx An Instance or Rolodex.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 */
void saveContacts(Rolodex *&rolodex, int &size)
{

    // Open the file.
    ofstream fout(DATABASE_NAME.c_str());

    // Write out each contact, which each attribute on its own line.
    for (int i = 0; i < size; i++)
    {
        fout << rolodex[i].firstName << endl
             << rolodex[i].lastName << endl
             << rolodex[i].email << endl
             << rolodex[i].phoneNumber << endl;
    }

    fout.close();
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
 * 1. select one option of six options
 *
 * @param border A Border instance.
 * @param rolodex A Rolodex instance. 
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 */
void selectOptions(Border &border, Rolodex *rolodex, int &size)
{
    // This is a character array -- it's like a string. It only holds 3
    // characters, plus a '\0' -- the end of string character.
    char userInput[MAX_INPUT_SIZE + 1];
    string lastName;

    do
    {
        clear();
        drawBorder(border);
        listContacts(border, rolodex, size);
        // Initialize ncurse stuff.
        initscr();
        nodelay(stdscr, false); // Wait for user input.
        keypad(stdscr, true);   // Interpret all keyboard keys.
        curs_set(1);            // Display the cursor.
        echo();                 // Makes user inputs display on the screen.

        // Prompt the user.
        loadContacts(rolodex, size);
        mvprintw(border.maxHeight - 3, 10, "[a]dd a contact, [l]ist all of contacts, [f]ind ontacts by last name, [u]pdate a contact, [r]emove a contact, [q]uit: ");

        // Read in only three characters.
        getnstr(userInput, 1);

        //if user enter a(add):
        if (userInput[0] == 'a')
        {
            while (true)
            {
                if (size < MAX_CONTACTS)
                {
                    addContact(border, rolodex, size);
                    move(6, 10);
                    clrtoeol();
                    break;
                }
                else
                {
                    mvprintw(border.maxHeight - 4, 10, "You can't add more contacts.");
                    break;
                }
            }
        }

        else if (userInput[0] == 'l')
        {
            listContacts(border, rolodex, size);
        }

        else if (userInput[0] == 'f')
        {
            findContacts(border, rolodex, size);
        }

        else if (userInput[0] == 'u')
        {
            updateContact(border, rolodex, size);
        }

        else if (userInput[0] == 'r')
        {
            removeContact(border, rolodex, size);
        }
        else if (userInput[0] == 'q')
        {
            break;
        }
        else
        {
            mvprintw(border.maxHeight - 4, 10, "That's invalid option.");
        }
        getch(); // wait for user's input
    } while (userInput[0] != 'q');

    // Don't exit until the user presses another key.
    endwin();
}

/**
 * the program to prompt the user to enter the new contact's information.
 * 
 * @param border A border insatnce.
 * @param rolodex A Rolodex instance.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 */
void addContact(Border &border, Rolodex *&rolodex, int &size)
{
    char userInput[MAX_INPUT_SIZE + 1];
    loadContacts(rolodex, size);

    clearWindow(border);
    move(2, 10);
    clrtoeol();

    mvprintw(2, 10, "Please enter the first name: ");
    getnstr(userInput, MAX_INPUT_SIZE);
    rolodex[size].firstName = string(userInput);

    mvprintw(3, 10, "Please enter the last name: ");
    getnstr(userInput, MAX_INPUT_SIZE);
    rolodex[size].lastName = string(userInput);

    mvprintw(4, 10, "Please enter the email: ");
    getnstr(userInput, MAX_INPUT_SIZE);
    rolodex[size].email = string(userInput);

    mvprintw(5, 10, "Please enter the phone number: ");
    getnstr(userInput, MAX_INPUT_SIZE);
    rolodex[size].phoneNumber = string(userInput);

    size++;

    saveContacts(rolodex, size);
}

/**
 * the program to show the list of all of contact's information.
 * 
 * @param border A border insatnce.
 * @param rolodex A Rolodex instance.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 */
void listContacts(Border &border, Rolodex *&rolodex, int &size)
{

    loadContacts(rolodex, size);
    move(2, 0);
    clrtoeol();

    for (int i = 0; i < size; i++)
    {
        printw("First Name[%d]: %s\n", i, rolodex[i].firstName.c_str());
        printw("Last Name[%d]: %s\n", i, rolodex[i].lastName.c_str());
        printw("Email[%d]: %s\n", i, rolodex[i].email.c_str());
        printw("Phone Number[%d]: %s\n", i, rolodex[i].phoneNumber.c_str());
    }
}

/**
 * update a contact by id.
 * 
 * @param border A border insatnce.
 * @param rolodex A Rolodex instance.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 */
void updateContact(Border &border, Rolodex *&rolodex, int &size)
{

    loadContacts(rolodex, size);
    char userInput[MAX_INPUT_SIZE + 1];

    while (true)
    {

        mvprintw(border.maxHeight - 4, 10, "Enter the index of contact to update: ");
        getnstr(userInput, MAX_INPUT_SIZE);

        int indexOfContact = charArrayToInt(userInput);

        if (indexOfContact >= 0 && indexOfContact < size)
        {
            //int indexOfContact = charArrayToInt(userInput);
            clearWindow(border);
            move(2, 10);
            clrtoeol();

            mvprintw(2, 10, "Enter the new first name: ");
            getnstr(userInput, MAX_INPUT_SIZE);

            rolodex[indexOfContact].firstName = string(userInput);

            mvprintw(3, 10, "Enter the new last name: ");
            getnstr(userInput, MAX_INPUT_SIZE);

            rolodex[indexOfContact].lastName = string(userInput);

            mvprintw(4, 10, "Enter the new email: ");
            getnstr(userInput, MAX_INPUT_SIZE);

            rolodex[indexOfContact].email = string(userInput);

            mvprintw(5, 10, "Enter the new phone number: ");
            getnstr(userInput, MAX_INPUT_SIZE);

            rolodex[indexOfContact].phoneNumber = string(userInput);

            break;
        }
        else
        {
            if (indexOfContact == 0)
            {
                mvprintw(border.maxHeight - 5, 10, "There is no more contact.");
                break;
            }
            else
            {
                mvprintw(border.maxHeight - 5, 10, "You entered the wrong index.");
                continue;
            }
        }
    }
    saveContacts(rolodex, size);
}

/**
 * prompt the user for the index of the contact to remove, 
 * ensure that contact exists (print an error message if it doesn't), then remove that contact. 
 * 
 * @param border A border insatnce.
 * @param rolodex A Rolodex instance.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 */
void removeContact(Border &border, Rolodex *&rolodex, int &size)
{
    loadContacts(rolodex, size);
    char userInput[MAX_INPUT_SIZE + 1];
    int indexOfContact;

    while (true)
    {

        mvprintw(border.maxHeight - 4, 10, "Enter the index what do you want to remove: ");
        getnstr(userInput, MAX_INPUT_SIZE);

        int indexOfContact = charArrayToInt(userInput);

        if (indexOfContact >= 0 && indexOfContact < size)
        {
            break;
        }
        else if (indexOfContact >= size)
        {
            mvprintw(border.maxHeight - 5, 10, "There is no more contact.");
            break;
        }
        else
            continue;
    }

    for (int i = indexOfContact; i < size; i++)
    {

        rolodex[i].firstName = rolodex[i + 1].firstName;
        rolodex[i].lastName = rolodex[i + 1].lastName;
        rolodex[i].email = rolodex[i + 1].email;
        rolodex[i].phoneNumber = rolodex[i + 1].phoneNumber;
    }

    size--;

    saveContacts(rolodex, size);
}

/**
 * find contacts by last name.
 * 
 * @param border A border insatnce.
 * @param rolodex A Rolodex instance.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 */
void findContacts(Border &border, Rolodex *&rolodex, int size)
{

    loadContacts(rolodex, size);
    char userInput[MAX_INPUT_SIZE + 1];
    int indexOfContact;
    bool check;

    mvprintw(border.maxHeight - 4, 10, "Enter the last name to find: ");
    getnstr(userInput, MAX_INPUT_SIZE);

    string lastName = string(userInput);

    for (int i = 0; i < size; i++)
    {
        if (rolodex[i].lastName == lastName)
        {
            clearWindow(border);
            mvprintw(2, 10, "First Name[%d]: %s", i, rolodex[i].firstName.c_str());
            mvprintw(3, 10, "Last Name[%d]: %s", i, rolodex[i].lastName.c_str());
            mvprintw(4, 10, "Email[%d]: %s", i, rolodex[i].email.c_str());
            mvprintw(5, 10, "Phone Number[%d]: %s", i, rolodex[i].phoneNumber.c_str());

            check = true;
        }

        else
        {
            if (check == false && i == size - 1)
            {
                mvprintw(border.maxHeight - 5, 10, "No contacts found");
            }
        }
    }

    saveContacts(rolodex, size);
}

/**
 * to convert a number as a char array into an integer
 * 
 * @param numAsString The char array which chagned into integer.
 * @return index 
 */
int charArrayToInt(char *numAsString)
{
    string userInfo = numAsString; // Input string
    istringstream inSS(userInfo);
    int index; // Index

    // Parse Index values from input string
    inSS >> index;

    return index;
}


/**
 * clear current window.
 * 
 * @param border A border instance.
 */
void clearWindow(Border &border)
{
    clear();
    drawBorder(border);

    // Initialize ncurse stuff.
    initscr();
    nodelay(stdscr, false); // Wait for user input.
    keypad(stdscr, true);   // Interpret all keyboard keys.
    curs_set(1);            // Display the cursor.
    echo();                 // Makes user inputs display on the screen.
}