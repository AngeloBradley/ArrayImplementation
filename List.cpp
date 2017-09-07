#include "List.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//No-arg Constructor, initializes the main array and N to 0
List::List() {
	N = 0;
	listArray[MAX];
	//Strictly for the purpose of initializing all elements to ""
	for (int i = 0; i < MAX; i++) {
		listArray[i] = "";
	}
}

//The Empty() method replaces all values in the main array with "" (empty string)
bool List::Empty() {
	bool isEmpty = false;
	for (int i = 0; i < N; i++) {
		listArray[i] = "";
	}

	return isEmpty;
}

//The InsertAtEnd() method places a new string element at the position of N (the number of elements in the main array at any given time)
void List::InsertAtEnd(ElementType x) {
	listArray[N] = x;
	N++;
}

//The Delete() method iterates through the main array looking for all instances of a user generated input
//The method "deletes" any found instances by copying all BUT those elements into a new array
//which is, itself, copied back into the main array
void List::Delete(ElementType x) {
	int counter = 0;
	ElementType newArray[MAX];

	for (int i = 0; i < N; i++) {
		if (listArray[i] != x) {
			newArray[counter] = listArray[i];
			counter++;
		}
	}

	//Updates N by counting the number of elements in the newArray 
	N = this->NumElements(newArray);

	for (int i = 0; i < N; i++) {
		listArray[i] = newArray[i];
	}

	string userResponse;

	cout << "Would you like to see the new list: ";
	cin >> userResponse;
	if (userResponse == "Y" || userResponse == "y") {
		this->Display();
	}
}

//The Display() method 
void List::Display() {
	cout << "**!**!**!**!**!**!**!**!**!**" << endl;
	for (int i = 0; i < N; i++) {
		if (listArray[i] != "") {
			cout << i + 1 << " " << listArray[i] << endl;
		}
	}
	cout << "**!**!**!**!**!**!**!**!**!**" << endl;

}

void List::Sort() {

	int counter = 0;
	int first;
	int numElements = this->NumElements();

	ElementType temp;
	for (int i = numElements - 1; i > 0; i--) {
		first = 0;
		for (int j = 1; j <= i; j++) {
			if (listArray[j].length() > listArray[first].length()) {
				first = j;
			}
		}
		temp = listArray[first];
		listArray[first] = listArray[i];
		listArray[i] = temp;
	}
	string userResponse;
	cout << "Would you like to see the shuffled list?: ";
	cin >> userResponse;
	if (userResponse == "Y" || userResponse == "y") {
		this->Display();
	}
}

double List::Average() {
	double total = 0;

	for (int i = 0; i < N; i++) {
		total += listArray[i].length();
	}

	return total / N;
}

double List::Median() {
	this->Sort();

	double median = listArray[(int)((double)round((N + 1) / 2))].length();

	return median;
}

void List::Shuffle() {
	ElementType newArray[MAX];
	srand(time(NULL));
	int randomIndex;
	for (int i = 0; i < N; i++) {
		randomIndex = rand() % N;
		if (listArray[randomIndex] != "") {
			newArray[i] = listArray[randomIndex];
			listArray[randomIndex] = "";
		}
		else {
			i--;
		}
	}

	for (int i = 0; i < N; i++) {
		listArray[i] = newArray[i];
	}
	N = NumElements();

	this->Shuffle();
	
	string userResponse;
	cout << "Would you like to see the shuffled list?: ";
	cin >> userResponse;
	if (userResponse == "Y" || userResponse == "y") {
		this->Display();
	}

}

int List::NumElements() {
	int numElements = 0;

	for (int i = 0; i < N; i++) {
		if (listArray[i] != "") {
			numElements++;
		}
	}

	return numElements;
}

int List::NumElements(ElementType t[]) {
	int numElements = 0;

	for (int i = 0; i < N; i++) {
		if (t[i] != "") {
			numElements++;
		}
	}

	return numElements;
}






