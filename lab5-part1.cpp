/*Name : Hyunlang Ban, Justen Koo
Date : 10/16
*/


#include <iostream>
using namespace std;
 
int main(){

int size = 0;
const int CAPACITY = 500;
string todo[CAPACITY];
// first array for to do list
bool check[CAPACITY];
char userChoice;
string itemToFind;
int removeItem;

	while(true)   {
		cout << "[A]dd an item to the list, [M]ark item as done, list [U]ndone items, list [D]one items, [E]rase an item, or [Q]uit the program: " << endl;
		cin >>  userChoice;
		cin.ignore();

		//Ask user to enter an item to array todo
		if (userChoice == 'A')   {
			cout << "Please enter an item to the list: ";
			getline(cin, todo[size]);
			check[size] = false;
			cout << todo[size]<<endl;
			size++;
		}

		//Ask user which item in the array they would like to mark as done
		else if (userChoice == 'M')   {
			cout<<"Please enter item you would like to mark as done"<<endl;
			getline(cin, itemToFind);
				for (int i = 0; i < size; ++i)   {
					if (todo[i]==itemToFind)   {
						check[i]=true;
					}
				}
		}	

		//Show user list of undone items in array
		else if (userChoice == 'U')   {
			for (int i = 0; i < size; ++i)   {
				if (check[i]==false){
					cout << "[" << i << "] " << todo[i] << endl;
				}
			}
		}

		//show user list of completed items in array
		else if (userChoice == 'D')   {
			for (int i = 0; i < size; ++i)   {
				if (check[i]==true)   {
					cout << "[" << i << "] "<<todo[i] << endl;
				}
			}
		}

		//Ask user which item to erase
		else if (userChoice == 'E')   {
			cout<<"Please enter index of item to remove: "<<endl;
			cin>>removeItem;

			for (int i = removeItem; i < size-1; ++i)   {
				todo[i]=todo[i+1];
				check[i]=check[i+1];
			}
			size--;
		}

		else if(userChoice=='Q')   {
			break;
		}
	}
	return 0;
}
