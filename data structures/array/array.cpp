#include <vector>
#include <iostream>
#include <array>

int main()
{
	int numbers[5];									 // Declares an array of 5 integers
	int numbers[5] = {1, 2, 3, 4, 5};				 // Initialize array elements at declaration
	int size = sizeof(numbers) / sizeof(numbers[0]); // Gives the size of the array

	int matrix[3][3]; // Declares a 3x3 2D array

	std::array<int, 5> numbers = {1, 2, 3, 4, 5};

	// Dynamic arrays allow you to change their size at runtime.
	int *dynamicArray = new int[5]; // Dynamic array of size 5
	delete[] dynamicArray;			// Freeing memory

	std::vector<int> dynamicVector; // Dynamic array using std::vector
}
