#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

void sleepSort(int num)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(num));
	std::cout << num << " ";
}

int main()
{
	std::vector<int> nums = {5, 3, 8, 1, 2, 4};
	std::vector<std::thread> threads;

	for (int num : nums)
	{
		threads.push_back(std::thread(sleepSort, num));
	}

	for (auto &th : threads)
	{
		th.join();
	}

	std::cout << std::endl;
	return 0;
}
