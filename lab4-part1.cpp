// File:     lab4-part1.cpp
// Author:   Hyunlang Ban, Justen Koo
// Date:     10/04/2018
// Purpose:  Uses branching to print different messages based on a student's
//           information.
#include <iostream>
#include <iomanip>
#include <ios>

using namespace std;

int main(){
string item;
float  price;
float tax;
float total;
string category;

do   {
cout << "Please enter an item" << endl;
cin >> item;
cout << "Please enter a price" << endl;
cin >> price;
cin.ignore() ;
cout << "Please enter a category (groceries, prepared food, other)." << endl;
getline(cin, category);
break;
}   while (category != "groceries" || category != "prepared food" || category != "other");
if (category == "groceries")   {
	tax=0.00;
}
else if (category == "prepared food")   {
	tax = price * 0.07;
}
else{
	tax=price*0.0625;
}
total = price + tax;
cout << fixed << setprecision(2)<< item << "          $" << price << endl;
cout << fixed << setprecision(2)<< "TAX           $" << tax << endl;
cout << "----------------------" << endl;
cout << fixed << setprecision(2)<< "TOTAL         $" << total;
	return 0;
}