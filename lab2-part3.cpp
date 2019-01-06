/*

Name : Hyunlang Ban
Partner : Justen Koo

Windows 10



$ lab2-part3.exe
int: 4 bytes
bits = 32
The largest number is: 2.14748e+009

short: 2 bytes
bits 16
The largest number is: 32767

long: 4 bytes
bits = 32
The largest number is: 2.14748e+009

long long: 8 bytes
bits = 64
The largest number is: 9.22337e+018

unsigned int: 4 bytes
bits = 32
The largest number is: 4.29497e+009

unsigned long: 4 bytes
bits = 32
The largest number is: 4.29497e+009

float : 4 bytes
bits = 32
The largest number is: 2.14748e+009

double : 8 bytes
bits = 64
The largest number is: 9.22337e+018

long double : 12 bytes
bits = 96
The largest number is: 3.96141e+028
*/



#include <iostream>
#include <cfloat>
#include <tgmath.h> 
using namespace std;

int main()
{

    // Print out how many bytes an int takes up.
    cout << "int: " << sizeof(int) << " bytes" << endl;

   	int bits = sizeof(int) * 8;
    cout << "bits = " << bits <<endl;
    cout << "The largest number is: "<< pow(2,bits-1)-1 << endl<<endl;

    cout << "short: " << sizeof(short) << " bytes" << endl;

    int bits2 = sizeof(short) * 8;
    cout << "bits " << bits2 <<endl;
    cout << "The largest number is: "<< pow(2,bits2-1)-1 << endl<<endl;

    cout << "long: " << sizeof(long) << " bytes" << endl;

    int bits3 = sizeof(long) * 8;
    cout << "bits = " << bits3 <<endl;
    cout << "The largest number is: "<< pow(2,bits3-1)-1 << endl<<endl;

    cout << "long long: " << sizeof(long long) << " bytes" << endl;

    int bits4 = sizeof(long long) * 8;
    cout << "bits = " << bits4 <<endl;
    cout << "The largest number is: "<< pow(2,bits4-1)-1<<endl<<endl;

    cout << "unsigned int: " << sizeof(int) << " bytes" << endl;

   	int bits5 = sizeof(int) * 8;
    cout << "bits = " << bits5 <<endl;
    cout << "The largest number is: "<< pow(2,bits5)-1 << endl<<endl;

    cout << "unsigned long: " << sizeof(long) << " bytes" << endl;

    int bits6 = sizeof(long) * 8;
    cout << "bits = " << bits6 <<endl;
    cout << "The largest number is: "<< pow(2,bits6)-1 << endl<<endl;

    cout << "float : " << sizeof(float) << " bytes" << endl;

    int bits7 = sizeof(float) * 8;
    cout << "bits = " << bits7 <<endl;
    cout << "The largest number is: "<< pow(2,bits7-1)-1 << endl<<endl;

    cout << "double : " << sizeof(double) << " bytes" << endl;

    int bits8 = sizeof(double) * 8;
    cout << "bits = " << bits8 <<endl;
    cout << "The largest number is: "<< pow(2,bits8-1)-1 << endl<<endl;

    cout << "long double : " << sizeof(long double) << " bytes" << endl;

    int bits9 = sizeof(long double) * 8;
    cout << "bits = " << bits9 <<endl;
    cout << "The largest number is: "<< pow(2,bits9-1)-1 << endl;

    
    return 0;
}