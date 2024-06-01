#include <iostream>
#include <vector>

// Function to perform insertion sort on arr[]
void insertionSort(std::vector<int> &arr)
{
	int n = arr.size();
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;

		// Move elements of arr[0..i-1], that are greater than key,
		// to one position ahead of their current position
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// Function to print an array
void printArray(const std::vector<int> &arr)
{
	for (int num : arr)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> arr = {12, 11, 13, 5, 6};

	std::cout << "Unsorted array: ";
	printArray(arr);

	insertionSort(arr);

	std::cout << "Sorted array: ";
	printArray(arr);

	return 0;
}
