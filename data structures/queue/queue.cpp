#include <iostream>

class Queue
{
private:
	int frontIndex, rearIndex, capacity;
	int *array;

public:
	Queue(int size);
	~Queue();

	void enqueue(int data);
	int dequeue();
	int front();
	bool isEmpty();
	bool isFull();
	void display();
};

// Constructor to initialize queue
Queue::Queue(int size)
{
	capacity = size;
	frontIndex = rearIndex = -1;
	array = new int[capacity];
}

// Destructor to clean up memory
Queue::~Queue()
{
	delete[] array;
}

// Check if the queue is empty
bool Queue::isEmpty()
{
	return frontIndex == -1;
}

// Check if the queue is full
bool Queue::isFull()
{
	return (rearIndex + 1) % capacity == frontIndex;
}

// Add an element to the back of the queue
void Queue::enqueue(int data)
{
	if (isFull())
	{
		std::cout << "Queue is full!" << std::endl;
		return;
	}
	if (isEmpty())
	{
		frontIndex = rearIndex = 0;
	}
	else
	{
		rearIndex = (rearIndex + 1) % capacity;
	}
	array[rearIndex] = data;
}

// Remove an element from the front of the queue
int Queue::dequeue()
{
	if (isEmpty())
	{
		std::cout << "Queue is empty!" << std::endl;
		return -1;
	}
	int data = array[frontIndex];
	if (frontIndex == rearIndex)
	{
		frontIndex = rearIndex = -1;
	}
	else
	{
		frontIndex = (frontIndex + 1) % capacity;
	}
	return data;
}

// Get the front element of the queue
int Queue::front()
{
	if (isEmpty())
	{
		std::cout << "Queue is empty!" << std::endl;
		return -1;
	}
	return array[frontIndex];
}

// Display the queue
void Queue::display()
{
	if (isEmpty())
	{
		std::cout << "Queue is empty!" << std::endl;
		return;
	}
	std::cout << "Queue: ";
	for (int i = frontIndex; i != rearIndex; i = (i + 1) % capacity)
	{
		std::cout << array[i] << " ";
	}
	std::cout << array[rearIndex] << std::endl;
}

int main()
{
	Queue q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);

	q.display();

	std::cout << "Dequeued: " << q.dequeue() << std::endl;
	std::cout << "Front element: " << q.front() << std::endl;

	q.enqueue(60);

	q.display();

	return 0;
}
