#include <iostream>

class Stack
{
private:
	int topIndex;
	int capacity;
	int *array;

public:
	Stack(int size);
	~Stack();

	void push(int data);
	int pop();
	int top();
	bool isEmpty();
	bool isFull();
	void display();
};

// Constructor to initialize stack
Stack::Stack(int size)
{
	capacity = size;
	topIndex = -1;
	array = new int[capacity];
}

// Destructor to clean up memory
Stack::~Stack()
{
	delete[] array;
}

// Check if the stack is empty
bool Stack::isEmpty()
{
	return topIndex == -1;
}

// Check if the stack is full
bool Stack::isFull()
{
	return topIndex == capacity - 1;
}

// Add an element to the top of the stack
void Stack::push(int data)
{
	if (isFull())
	{
		std::cout << "Stack overflow!" << std::endl;
		return;
	}
	array[++topIndex] = data;
}

// Remove the top element from the stack
int Stack::pop()
{
	if (isEmpty())
	{
		std::cout << "Stack underflow!" << std::endl;
		return -1;
	}
	return array[topIndex--];
}

// Get the top element of the stack
int Stack::top()
{
	if (isEmpty())
	{
		std::cout << "Stack is empty!" << std::endl;
		return -1;
	}
	return array[topIndex];
}

// Display the stack
void Stack::display()
{
	if (isEmpty())
	{
		std::cout << "Stack is empty!" << std::endl;
		return;
	}
	std::cout << "Stack: ";
	for (int i = 0; i <= topIndex; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}


int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.display();

    std::cout << "Popped: " << s.pop() << std::endl;
    std::cout << "Top element: " << s.top() << std::endl;

    s.push(60);

    s.display();

    return 0;
}
