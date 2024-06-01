#include <iostream>
#include <vector>

// A utility function to swap two elements
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// To heapify a subtree rooted with node i which is an index in arr[]
void heapify(std::vector<int> &arr, int n, int i)
{
	int largest = i;	   // Initialize largest as root
	int left = 2 * i + 1;  // left = 2*i + 1
	int right = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (left < n && arr[left] > arr[largest])
		largest = left;

	// If right child is larger than largest so far
	if (right < n && arr[right] > arr[largest])
		largest = right;

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// Main function to do heap sort
void heapSort(std::vector<int> &arr)
{
	int n = arr.size();

	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// Call max heapify on the reduced heap
		heapify(arr, i, 0);
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
	std::vector<int> arr = {12, 11, 13, 5, 6, 7};

	std::cout << "Unsorted array: ";
	printArray(arr);

	heapSort(arr);

	std::cout << "Sorted array: ";
	printArray(arr);

	return 0;
}
