#include<iostream>    /* standard input/output library which lets us work with different objects */

using namespace std; // we use to get names from the standard library

int main()   // main function where the program starts executing....
{
	string myString="Hello world"; // Give only understandable names to variables
        int myAge= 21;
	string caution;
        caution="Don't memorize , Understand thoroughly";
        const int practiceHours= 30;

	cout<<"Hello \n World !\n";   // cout is used for printing data on console
        cout<< " Three : "<<0+3;    
	cout<<"\n"; // \n is used to get to a newline instead of contuining on same line
	cout<<"String is "<<myString<<"\n";
	cout<<"Caution every person must take : \" "<<caution<<"\" \n";
        cout<<"Kartik's Age is going to be become "<<myAge<<"\n";	
	return 0; // we use to close the function 
}
