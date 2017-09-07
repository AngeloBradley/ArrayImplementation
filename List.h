// file: List.h 
#include<string>
using namespace std;
typedef string ElementType;
const int MAX = 100;

	class List
	{
	public:
		List(); // Create an empty list
		bool Empty(); // Return true if the list is empty, otherwise return false
		void InsertAtEnd(ElementType x); // Insert a value x at the end of the list
		void Delete(ElementType x); // If value x is in the list, remove x (all instances)
		void Display(); // Display the data values in the list
		void Sort(); // Sort the list of strings based on length (shortest to longest)
		double Average(); // Compute amd return the average string length for the strings in the list
		double Median(); // Compute and return the median string length for the strings in the list
		void Shuffle(); // Shuffle the strings in the list around
		int NumElements(); //Counts actual number of elements in the array
		int NumElements(ElementType t[]); //Counts actual number of elements in the array

	private:
		int N; // Number of values in list
		ElementType listArray[MAX]; // The array to hold the list values
	};
