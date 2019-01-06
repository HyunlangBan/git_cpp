// File:     lab3-part3.cpp
// Author:   Hyunlang Ban, Justen Koo
// Date:     09/27/2018
// Purpose:  Uses branching to print different messages based on a student's
//           information.


/*$ lab3-part3.exe
Please enter an item, a price, and a category (groceries, prepared food, or other
eggs
2.23
prepared food
eggs          $2.23
TAX           $0.14
----------------
TOTAL         $2.37*/




//Please enter an item, a price, and a category (groceries, prepared food, or other
do


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

cout << "Please enter an item, a price, and a category (groceries, prepared food, or other)" << endl;

cin >> item >> price >> category;

if (category == "groceries")   {
	tax=0.00;
	total = price + tax;
	cout << fixed << setprecision(2)<< item << "          $" << price << endl;
	cout << fixed << setprecision(2)<< "TAX           $" << tax << endl;
	cout << "----------------------" << endl;
	cout << fixed << setprecision(2)<< "TOTAL         $" << total;
	//cout << "Price" << endl;
}
else if (category == "prepared food")   {
	tax = price * 0.07;
	total = price + tax;
	cout << fixed << setprecision(2)<< item << "          $" << price << endl;
	cout << fixed << setprecision(2)<< "TAX           $" << tax << endl;
	cout << "----------------" << endl;
	cout << fixed << setprecision(2)<< "TOTAL         $" << total;
}
else{
	tax=price*0.0625;
	total = price + tax;
	cout << fixed << setprecision(2)<< item << "          $" << price << endl;
	cout << fixed << setprecision(2)<< "TAX           $" << tax << endl;
	cout << "----------------" << endl;
	cout << fixed << setprecision(2)<< "TOTAL         $" << total;}
return 0;
}