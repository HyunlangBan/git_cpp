/*Name : Hyunlang Ban
Date : 10/3/2018
File name : pa1.cpp
Output:

$ pa1.exe
Please enter the length of password(minimum is 5):
6
Do you want to include capital character? Enter 'y' or 'n' :
y
How many capital characters do you want to include? :
2
Do you want to include number? Enter 'y' or 'n' :
y
How many numbers do you want to include? :
1
Do you want to include special character? Enter 'y' or 'n' :
y
How many special characters do you want to include? :
1
Your password is : fqJE3}


gusfk@DESKTOP-U7C18CF C:\Users\gusfk\Desktop\c
$ pa1.exe
Please enter the length of password(minimum is 5):
8
Do you want to include capital character? Enter 'y' or 'n' :
y
How many capital characters do you want to include? :
3
Do you want to include number? Enter 'y' or 'n' :
n
Do you want to include special character? Enter 'y' or 'n' :
y
How many special characters do you want to include? :
3
Your password is : laUJK];,


$ pa1.exe
Please enter the length of password(minimum is 5):
3
Please enter the length of password(minimum is 5):
2
Please enter the length of password(minimum is 5):
1
Please enter the length of password(minimum is 5):
5
Do you want to include capital character? Enter 'y' or 'n' :
n
Do you want to include number? Enter 'y' or 'n' :
n
Do you want to include special character? Enter 'y' or 'n' :
n
Your password is : xielm
*/


#include <iostream>
#include <ctime>
using namespace std;



int main(){

	srand(time(0));

//ask the user for the length of the password to generate
//	(minimum : 5) the user should be re-promoted until a valid password
//  length is entered.

	int passlen;
	char cap;
	int capnum;
	char num;
	int numnum;
	char spe;
	int spenum;
	int lowernum;
	char passlower;
	char passcap;
	char passnum;
	char passspe;

	do
	{
		cout<<"Please enter the length of password(minimum is 5): "<<endl;
		cin>> passlen;
	} while (passlen <5);

//ask the user if they want
	// 1. at least one capital (A-Z)
	// 2. at least one number (0-9)
	// 3. at least one special character 

	do{
		cout << "Do you want to include capital character? Enter 'y' or 'n' : " << endl;
	cin >> cap;

	if(cap=='y'){
		cout << "How many capital characters do you want to include? :"<<endl;
		cin >> capnum;
	}

	else{
		capnum = 0;
	}

	cout << "Do you want to include number? Enter 'y' or 'n' : " << endl;
	cin >> num;

	if(num=='y'){
		cout << "How many numbers do you want to include? :"<<endl;
		cin >> numnum;
	}

		else{
		numnum = 0;
	}

	cout << "Do you want to include special character? Enter 'y' or 'n' : " << endl;
	cin >> spe;

	if(spe=='y'){
		cout << "How many special characters do you want to include? :"<<endl;
		cin >> spenum;
	}

	else{
		spenum = 0;
	}

	}
	while(passlen < capnum+numnum+spenum);
	lowernum = passlen - (capnum + numnum + spenum);

cout<<"Your password is : ";

//uses a loop to generate each character of the password. for each character
	//randomly generates an ASCII number
	// add the character corresponding to that ASCII number to the password string
	
	//1. lower case(97 ~ 122) 
	//2. capital char(65 ~ 90)
	//3. number(48 ~ 57)
	//4. special char(33=<  =<126에서 위의 3 종류 제외)

for (int i = 0; i < lowernum; ++i)
{
	
	passlower = rand() % 26 + 97;
	cout << passlower;
}

for (int i = 0; i < capnum; ++i)
{
	passcap = rand() % 26 + 65;
	cout << passcap;
}
for (int i = 0; i < numnum; ++i)
{
	passnum = rand() % 10 + 48;
	cout << passnum;
}
for (int i = 0; i < spenum; ++i)
{
	passspe = rand() % 95 + 32;

	if ((passspe>=48&&passspe<=57)||(passspe>=65&&passspe<=90)||(passspe>=97&&passspe<=122))
	{
	i--;	
	continue;
	}

	cout << passspe;
}


	return 0;
}