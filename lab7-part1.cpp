//==============================================================================
// Filename     : lab7-part1.cpp
// Author(s)    : Justen Koo, Hyunlang Ban
// Date         : 1 November 2018
// Description  : Calculate area of shape chosen by user
//==============================================================================
#include <fstream>
#include <iostream>
using namespace std;

// Function Declarations
double areaTriangle (double triangleHeight, double triangleBase);
double areaRectangle (double rectangleBase, double rectangleHeight);
double areaCircle (double circleRadius);

// Other Declarations
char usermenuChoice;
const double pi = 3.14;

int main (){
    double triangleBase;
    double triangleHeight;
    double rectangleBase;
    double rectangleHeight;
    double circleRadius;

    do {
        cout << "Please choose a shape to calculate the area of: " << endl;
        cout << "[T]riangle, [R]ectangle, [C]ircle or [Q]uit: ";
        cin >> usermenuChoice;
            if (usermenuChoice == 'T'){
                cout << "Triangle Selected." << endl;
                // invoke function for solving Triangle
                cout << "The area of your triangle is " << areaTriangle(triangleHeight, triangleBase) << endl;
            }
            else if (usermenuChoice == 'R'){
                cout << "Rectangle Selected." << endl;
                // invoke function for Rectangle
                cout << "The area of your rectangle is " << areaRectangle(rectangleHeight, rectangleBase) << endl;
            }
            else if (usermenuChoice == 'C'){
                cout << "Circle Selected." << endl;
                // invoke function for Circle
                cout << "The area of your circle is " << areaCircle(circleRadius) << endl; 

            }
            else if (usermenuChoice == 'Q'){
                break;
            }
    } while (usermenuChoice != 'T' || usermenuChoice != 'R' || usermenuChoice != 'C' || usermenuChoice != 'Q');
    return 0;
}

// Function Definitions
/**
* Solve area of a rectangle based on user's input
* @param rectangleHeight height of triangle
* @param rectangleBase base of triangle
* @return areaRectangle
*/
double areaRectangle (double rectangleHeight, double rectangleBase) {
    cout << "Please enter the height of the rectangle: ";
    cin >> rectangleHeight;
    cout << "Please enter the base of the rectangle: ";
    cin >> rectangleBase;
    double areaRectangle = (rectangleBase * rectangleHeight);
    return areaRectangle;
}

/**
* Solve area of a Triangle based on user's input
* @param triangleheight of triangle
* @param triangleBase base of triangle
* @return areaTriangle
*/
double areaTriangle (double triangleHeight, double triangleBase) {
    cout << "Please enter the height of the triangle: ";
    cin >> triangleHeight;
    cout << "Please enter the base of the triangle: ";
    cin >> triangleBase;
    double areaTriangle = (triangleBase * triangleHeight) / 2.0;
    return areaTriangle;
}

/*
* Solve area of a Circle based on user's input
* @param circleRadius radius of the circle
* @return areaCircle
*/
double areaCircle (double circleRadius) {
    cout << "Please enter the radius of the circle: ";
    cin >> circleRadius;
    double areaCircle = (pi * (circleRadius * circleRadius));
    return areaCircle;
}