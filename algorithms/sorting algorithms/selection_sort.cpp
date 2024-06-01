#include <iostream>
#include <vector>

// Function to perform selection sort on arr[]
void selectionSort(std::vector<int> &arr)
{
	int n = arr.size();

	// One by one move boundary of unsorted subarray
	for (int i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		int minIdx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
		}

		// Swap the found minimum element with the first element
		std::swap(arr[minIdx], arr[i]);
	}
}

// Function to print an array
void printArray(const std::vector<int> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> arr = {64, 25, 12, 22, 11};

	std::cout << "Unsorted array: ";
	printArray(arr);

	selectionSort(arr);

	std::cout << "Sorted array: ";
	printArray(arr);

	return 0;
}
