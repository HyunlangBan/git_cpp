// File:     lab3-part1.cpp
// Author:   Hyunlang Ban, Justen Koo
// Date:     09/27/2018
// Purpose:  Uses branching to print different messages based on a student's
//           information.

/*
$ lab3-part1.exe
Enter the number of credit hours you have completed: 33
Enter your commuter status [1=commuter,0=not a commuter]: 1
Enter your major prefix (CSC/BEN/MTH/etc.): CSC
Parking must be a pain!
You have Sophomore status
You're at home in LSB!

*/
#include <iostream>
using namespace std;

int main(){
    int credits;
    bool isCommuter;
    string major;

    cout << "Enter the number of credit hours you have completed: ";
    cin >> credits;

    cout << "Enter your commuter status [1=commuter,0=not a commuter]: ";
    cin >> isCommuter;

    cout << "Enter your major prefix (CSC/BEN/MTH/etc.): ";
    cin >> major;

    // TODO Add in the questions/solutions here.
    //1. if student is commuter --> Parking must be a pain!
    //2. 30>=credits and credits <=59 --> sophomore
    //3. if credit+30 between 30 and 59 ==> next year sophomore
    //4. major --> you're at home in LSB!

    if(isCommuter == 1){
        cout<<"Parking must be a pain!"<<endl;
    }
    if(credits>=30 && credits<=59){
        cout<<"You have Sophomore status"<<endl;
    }
   else if((credits+30)>=30 && (credits+30)<=59){
        cout<<"You'll be a Sophomore next year!"<<endl;
    }
    if(major=="CSC"||major=="MTH"||major=="BEN"||major=="BIO"||major=="ENV"||major=="BUS"){
        cout<<"You're at home in LSB!";
    }
   
    return 0;
}
