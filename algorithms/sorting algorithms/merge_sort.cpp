#include <iostream>
#include <vector>

// Merge two subarrays L and R into arr
void merge(std::vector<int> &arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// Create temporary arrays
	std::vector<int> L(n1);
	std::vector<int> R(n2);

	// Copy data to temporary arrays L[] and R[]
	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[left + i];
	}
	for (int i = 0; i < n2; i++)
	{
		R[i] = arr[mid + 1 + i];
	}

	// Merge the temporary arrays back into arr[left..right]
	int i = 0;	  // Initial index of first subarray
	int j = 0;	  // Initial index of second subarray
	int k = left; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[], if there are any
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[], if there are any
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

// Merge sort function
void mergeSort(std::vector<int> &arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		// Sort first and second halves
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		// Merge the sorted halves
		merge(arr, left, mid, right);
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

	mergeSort(arr, 0, arr.size() - 1);

	std::cout << "Sorted array: ";
	printArray(arr);

	return 0;
}
