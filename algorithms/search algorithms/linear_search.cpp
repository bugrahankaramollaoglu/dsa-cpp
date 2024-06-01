#include <iostream>
#include <vector>

// Function to perform linear search on arr[]
// Returns the index of x if it is present in arr[], otherwise -1
int linearSearch(const std::vector<int> &arr, int x)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == x)
		{
			return i;
		}
	}
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

	int result = linearSearch(arr, x);
	printResult(result);

	return 0;
}
