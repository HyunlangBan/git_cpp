//==============================================================================
// Filename     : pa2.cpp
// Author(s)    : Hyunlang Ban
// Date         : 11/3
// Description  : A digital Rolodex program.
//==============================================================================

#include <fstream>
#include <iostream>
using namespace std;

const int MAX_CONTACTS = 500;
const string DATABASE_NAME = "contacts.db";

// Function declarations.
void loadContacts(string firstNames[], string lastNames[], string emails[],
                  string phoneNumbers[], int &size);
void saveContacts(string firstNames[], string lastNames[], string emails[],
                  string phoneNumbers[], int &size);

// TODO: Add your function declarations here.
void selectOptions(string firstNames[], string lastNames[], string emails[],
                   string phoneNumbers[], int &size);
void addContact(string firstNames[], string lastNames[], string emails[],
                string phoneNumbers[], int &size);
void listContacts(string firstNames[], string lastNames[], string emails[],
                  string phoneNumbers[], int &size);
void updateContact(string firstNames[], string lastNames[], string emails[],
                   string phoneNumbers[], int indexOfContact, int &size);
void removeContact(string firstNames[], string lastNames[], string emails[],
                   string phoneNumbers[], int indexOfContact, int &size);
void findContacts(string firstNames[], string lastNames[], string emails[],
                  string phoneNumbers[], string lastName, int size);

/**
 * Prompts the user with a menu and processes the selected options until the
 * user quits.
 *
 * @return The exit status.
 */
int main()
{
    string firstNames[MAX_CONTACTS];
    string lastNames[MAX_CONTACTS];
    string emails[MAX_CONTACTS];
    string phoneNumbers[MAX_CONTACTS];

    int size = 0;
    selectOptions(firstNames, lastNames, emails, phoneNumbers, size);

    return 0;
}

// TODO: Add your function definitions here.

/**
 * Loads contacts from the database file.
 *
 * @param firstNames The array to read the first name into.
 * @param lastNames The array to read the last name into.
 * @param emails The array to read the email address into.
 * @param phoneNumbers The array to read the phone number into.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 */
void loadContacts(string firstNames[], string lastNames[], string emails[],
                  string phoneNumbers[], int &size)
{

    size = 0;

    // Open the file.
    ifstream fin(DATABASE_NAME.c_str());

    // Read in the contacts. Each contact has one line for each attribute.
    while (fin.good() && size < MAX_CONTACTS)
    {
        getline(fin, firstNames[size]);
        getline(fin, lastNames[size]);
        getline(fin, emails[size]);
        getline(fin, phoneNumbers[size]);

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
 * @param firstNames The array to read the first name into.
 * @param lastNames The array to read the last name into.
 * @param emails The array to read the email address into.
 * @param phoneNumbers The array to read the phone number into.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 */
void saveContacts(string firstNames[], string lastNames[], string emails[],
                  string phoneNumbers[], int &size)
{

    // Open the file.
    ofstream fout(DATABASE_NAME.c_str());

    // Write out each contact, which each attribute on its own line.
    for (int i = 0; i < size; i++)
    {
        fout << firstNames[i] << endl
             << lastNames[i] << endl
             << emails[i] << endl
             << phoneNumbers[i] << endl;
    }

    fout.close();
}

/**
 * 1. select one option of six options
 *
 * @param firstNames The array to read the first name into.
 * @param lastNames The array to read the last name into.
 * @param emails The array to read the email address into.
 * @param phoneNumbers The array to read the phone number into.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 */
void selectOptions(string firstNames[], string lastNames[], string emails[],
                   string phoneNumbers[], int &size)
{
    char userChoice;
    int indexOfContact;
    string lastName;

    loadContacts(firstNames, lastNames, emails, phoneNumbers, size);

    while (true)
    {
        cout << "Enter a option what do you want: " << endl;
        cout << "[a]dd a contact, [l]ist all of contacts, [f]ind ontacts by last name, [u]pdate a contact, [r]emove a contact, [q]uit" << endl;
        cin >> userChoice;

        if (userChoice == 'a')
        {
            while (true)
            {
                if (size < MAX_CONTACTS)
                {
                    addContact(firstNames, lastNames, emails, phoneNumbers, size);
                    break;
                }
                else
                {
                    cout << "You can't add more contacts." << endl;
                    break;
                }
            }
        }

        else if (userChoice == 'l')
        {
            listContacts(firstNames, lastNames, emails, phoneNumbers, size);
        }

        else if (userChoice == 'f')
        {
            findContacts(firstNames, lastNames, emails, phoneNumbers, lastName, size);
        }

        else if (userChoice == 'u')
        {
            updateContact(firstNames, lastNames, emails, phoneNumbers, indexOfContact, size);
        }

        else if (userChoice == 'r')
        {
            removeContact(firstNames, lastNames, emails, phoneNumbers, indexOfContact, size);
        }
        else if (userChoice == 'q')
        {
            break;
        }
        else{
            cout<<"That's invalid option."<<endl;
        }
    }
}

/**
 * the program to prompt the user to enter the new contact's information.
 * 
 * @param firstNames The array to read the first name into.
 * @param lastNames The array to read the last name into.
 * @param emails The array to read the email address into.
 * @param phoneNumbers The array to read the phone number into.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 */
void addContact(string firstNames[], string lastNames[], string emails[],
                string phoneNumbers[], int &size)
{
    loadContacts(firstNames, lastNames, emails, phoneNumbers, size);

    cin.ignore();

    cout << "Please enter the first name: ";
    getline(cin, firstNames[size]);

    cout << "Please enter the last name: ";
    getline(cin, lastNames[size]);

    cout << "Please enter the email: ";
    getline(cin, emails[size]);

    cout << "Please enter the phone number: ";
    getline(cin, phoneNumbers[size]);

    size++;

    saveContacts(firstNames, lastNames, emails, phoneNumbers, size);
}

void listContacts(string firstNames[], string lastNames[], string emails[],
                  string phoneNumbers[], int &size)
{

    loadContacts(firstNames, lastNames, emails, phoneNumbers, size);

    for (int i = 0; i < size; i++)
    {
        cout << "Frist Name[" << i << "]: " << firstNames[i] << endl;
        cout << "Last Name[" << i << "]: " << lastNames[i] << endl;
        cout << "Email[" << i << "]: " << emails[i] << endl;
        cout << "Phone Number[" << i << "]: " << phoneNumbers[i] << endl;
    }
}

/**
 * update a contact by id.
 * 
 * @param firstNames The array to read the first name into.
 * @param lastNames The array to read the last name into.
 * @param emails The array to read the email address into.
 * @param phoneNumbers The array to read the phone number into.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 * @param indexOfContact The index of contact to update.
 */
void updateContact(string firstNames[], string lastNames[], string emails[], string phoneNumbers[], int indexOfContact, int &size)
{

    loadContacts(firstNames, lastNames, emails, phoneNumbers, size);

    while (true)
    {
        cout << "Enter the index of contact to update: ";
        cin >> indexOfContact;

        if (indexOfContact >= 0 || indexOfContact < size)
        {
            break;
        }
    }

    cin.ignore();

    cout << "Enter the new first name: ";
    getline(cin, firstNames[indexOfContact]);

    cout << "Enter the new last name: ";
    getline(cin, lastNames[indexOfContact]);

    cout << "Enter the new email: ";
    getline(cin, emails[indexOfContact]);

    cout << "Enter the new phone number: ";
    getline(cin, phoneNumbers[indexOfContact]);

    saveContacts(firstNames, lastNames, emails, phoneNumbers, size);
}

/**
 * prompt the user for the index of the contact to remove, 
 * ensure that contact exists (print an error message if it doesn't), then remove that contact. 
 * 
 * @param firstNames The array to read the first name into.
 * @param lastNames The array to read the last name into.
 * @param emails The array to read the email address into.
 * @param phoneNumbers The array to read the phone number into.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 * @param indexOfContact The index of contact to remove.
 */
void removeContact(string firstNames[], string lastNames[], string emails[],
                   string phoneNumbers[], int indexOfContact, int &size)
{
    loadContacts(firstNames, lastNames, emails, phoneNumbers, size);

    while (true)
    {

        cout << "Enter the index what do you want to remove: ";
        cin >> indexOfContact;

        if (indexOfContact >= 0 && indexOfContact < size)
        {
            break;
        }

        else
            continue;
    }

    for (int i = indexOfContact; i < size; i++)
    {

        firstNames[i] = firstNames[i + 1];
        lastNames[i] = lastNames[i + 1];
        emails[i] = emails[i + 1];
        phoneNumbers[i] = phoneNumbers[i + 1];
    }

    size--;

    saveContacts(firstNames, lastNames, emails, phoneNumbers, size);
}

/**
 * find contacts by last name.
 * 
 * @param firstNames The array to read the first name into.
 * @param lastNames The array to read the last name into.
 * @param emails The array to read the email address into.
 * @param phoneNumbers The array to read the phone number into.
 * @param size The number of contacts already read in (also, the index where the
 *             new contact will be put). This will be updated!
 * @param lastName The last name of the contact to find.
 */
void findContacts(string firstNames[], string lastNames[], string emails[],
                  string phoneNumbers[], string lastName, int size)
{

    loadContacts(firstNames, lastNames, emails, phoneNumbers, size);

    cout << "Enter the last name to find: ";
    cin >> lastName;

    for (int i = 0; i < size; i++)
    {
        if (lastNames[i] == lastName)
        {
            cout << "Frist Name[" << i << "]: " << firstNames[i] << endl;
            cout << "Last Name[" << i << "]: " << lastNames[i] << endl;
            cout << "Email[" << i << "]: " << emails[i] << endl;
            cout << "Phone Number[" << i << "]: " << phoneNumbers[i] << endl;

            //continue; //있는대로 다 검색하기위해서....
        }

        else
        {
            if (i == size - 1)
            {
                cout << "No contacts found" << endl;
            }
        }
    }

    saveContacts(firstNames, lastNames, emails, phoneNumbers, size);
}