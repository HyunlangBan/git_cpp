/*
Name : Hyunlang Ban
Partner : Justen Koo

Windows 10

$ lab2-part2.exe
Please enter radius: 20
The area of your circle is:  1256

*/


#include <iostream>
using namespace std;

int main()

{
float radius;
float area;
 
cout << "Please enter radius: ";
cin >> radius;
area = 3.14 * radius * radius;
cout << "The area of your circle is:  " << area;

return 0;
}