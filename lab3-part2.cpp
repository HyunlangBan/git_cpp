// File:     lab3-part2.cpp
// Author:   Hyunlang Ban, Justen Koo
// Date:     09/27/2018
// Purpose:  Uses branching to print different messages based on a student's
//           information.


/*$ lab3-part2.exe
This is your first guess. Guess a number betweem 1 to 50 :
45
You lose!
This is your second guess. Guess a number betweem 1 to 50 :
34
You lose!
This is your last guess. Guess a number betweem 1 to 50 :
66
You lose! Game over!*/



#include <stdlib.h> // For rand() and srand()
#include <time.h> // For time()
#include <iostream>
using namespace std;

int main(){
    int secret, usersGuess;
    // Seed the random number generator by uncommenting the line below
    srand(time(0));
    // Generate a random number and project it to the range 1 to 50; uncomment the line below.
    secret = rand() % 50 + 1;
    //cout<<secret<<endl;

    cout<<"This is your first guess. Guess a number betweem 1 to 50 : "<<endl;
    cin>>usersGuess;


    if(usersGuess==secret){
    	cout<<"You win the game!"<<endl;
    }



    else{
    	cout<<"You lose!"<<endl;

    	cout<<"This is your second guess. Guess a number betweem 1 to 50 : "<<endl;
   		cin>>usersGuess;

   			 if(usersGuess==secret){
    		cout<<"You win!"<<endl;
    			}

    		else{
    			cout<<"You lose!"<<endl;
    			cout<<"This is your last guess. Guess a number betweem 1 to 50 : "<<endl;
    			cin>>usersGuess;

					if(usersGuess==secret){
    				cout<<"You win!"<<endl;}

    			    else{
    					cout<<"You lose! Game over!"<<endl;}


    }
    }

     



return 0;    }

