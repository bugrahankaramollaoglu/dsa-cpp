#include <iostream>
#include <vector>

// Function to perform binary search on arr[]
// Returns the index of x if it is present in arr[], otherwise -1
int binarySearch(const std::vector<int> &arr, int left, int right, int x)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		// Check if x is present at mid
		if (arr[mid] == x)
		{
			return mid;
		}

		// If x is greater, ignore the left half
		if (arr[mid] < x)
		{
			left = mid + 1;
		}
		// If x is smaller, ignore the right half
		else
		{
			right = mid - 1;
		}
	}

	// If we reach here, the element was not present
	return -1;
}

// Function to print the result
void printResult(int index)
{
	if (index != -1)
	{
		std::cout << "Element found at index " << index << std::endl;
	}
	else
	{
		std::cout << "Element not found in array" << std::endl;
	}
}

int main()
{
	std::vector<int> arr = {2, 3, 4, 10, 40};
	int x = 10;

	std::cout << "Array: ";
	for (int num : arr)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	int result = binarySearch(arr, 0, arr.size() - 1, x);
	printResult(result);

	return 0;
}
