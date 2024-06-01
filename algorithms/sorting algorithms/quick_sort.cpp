#include <iostream>
#include <vector>

// A utility function to swap two elements
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// This function takes last element as pivot, places the pivot element at its correct position in sorted array,
// and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
int partition(std::vector<int> &arr, int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1);	   // Index of smaller element

	for (int j = low; j < high; j++)
	{
		// If current element is smaller than or equal to pivot
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(std::vector<int> &arr, int low, int high)
{
	if (low < high)
	{
		// pi is partitioning index, arr[p] is now at right place
		int pi = partition(arr, low, high);

		// Separately sort elements before partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
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
	std::vector<int> arr = {10, 7, 8, 9, 1, 5};

	std::cout << "Unsorted array: ";
	printArray(arr);

	quickSort(arr, 0, arr.size() - 1);

	std::cout << "Sorted array: ";
	printArray(arr);

	return 0;
}
