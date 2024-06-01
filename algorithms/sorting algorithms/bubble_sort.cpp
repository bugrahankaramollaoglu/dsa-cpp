#include <iostream>
#include <vector>

// Function to perform bubble sort on arr[]
void bubbleSort(std::vector<int> &arr)
{
	int n = arr.size();
	for (int i = 0; i < n - 1; i++)
	{
		// Last i elements are already in place
		for (int j = 0; j < n - i - 1; j++)
		{
			// Swap if the element found is greater than the next element
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
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
	std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

	std::cout << "Unsorted array: ";
	printArray(arr);

	bubbleSort(arr);

	std::cout << "Sorted array: ";
	printArray(arr);

	return 0;
}
