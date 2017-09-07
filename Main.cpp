#include <iostream>
#include "List.h"
#include <sstream>
using namespace std;

int main() {

	//Variables
	string userChoice = 0;
	string newString = "";
	List myList = List();
	bool doNotExit = true;
    string forDeletion = "";

	while (doNotExit) {
		cout << "1. Insert" << endl;
		cout << "2. Delete" << endl;
		cout << "3. Display" << endl;
		cout << "4. Sort" << endl;
		cout << "5. Average" << endl;
		cout << "6. Median" << endl;
		cout << "7. Shuffle" << endl;
		cout << "8. Exit" << endl;

		cout << "Make a selection from the list above: ";
		cin >> userChoice;

		//Checks to see if the user made a valid selection
		if (userChoice != "1" && userChoice != "2" && userChoice != "3" && userChoice != "4" && userChoice != "5" && userChoice != "6" && userChoice != "7" && userChoice != "8") {
			cout << "!!!Invalid Selection!!!" << endl;
			cout << "Please make a selection from the list above: ";
			cin >> userChoice;
		}
		cout << endl;

		//Converts correct input to int value for switch statement functionality
		stringstream convert(userChoice);
		int choiceConvert = 0;
		convert >> choiceConvert;

		//Menu functionality 
		switch (choiceConvert) {
		case 1:
			while (newString != "!!") {
				cout << "Please enter a new string: ";
				cout << "[Enter !! when you are done]";
				cin >> newString;
				if (newString != "!!") {
					myList.InsertAtEnd(newString);
				}
			}
			break;
		case 2:
			
			cout << "Enter the value that you want removed from the list: ";
			cout << "[!!NOTE: All instances of this value will be removed!!]";
			cin >> forDeletion;
			myList.Delete(forDeletion);
			break;
		case 3:
			myList.Display();
			break;
		case 4:
			myList.Sort();
			break;
		case 5:
			cout << "Average string length: " << myList.Average() << endl;
			break;
		case 6:
			cout << "Median number of characters: " << myList.Median() << endl;
			break;
		case 7:
			myList.Shuffle();
			break;
		case 8:
			doNotExit = false;
			break;
		}
	}
	
}