#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node *next;

	Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList
{
private:
	Node<T> *head; // Pointer to the head of the list

public:
	// Constructor to initialize an empty list
	SinglyLinkedList() : head(nullptr) {}

	// Destructor to deallocate memory
	~SinglyLinkedList()
	{
		clear();
	}

	// Method to insert an element at the beginning of the list
	void push_front(T value)
	{
		Node<T> *newNode = new Node<T>(value);
		newNode->next = head;
		head = newNode;
	}

	// Method to insert an element at the end of the list
	void push_back(T value)
	{
		Node<T> *newNode = new Node<T>(value);
		if (!head)
		{
			head = newNode;
			return;
		}
		Node<T> *current = head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = newNode;
	}

	// Method to remove the first element from the list
	void pop_front()
	{
		if (!head)
			return;
		Node<T> *temp = head;
		head = head->next;
		delete temp;
	}

	// Method to check if the list is empty
	bool empty() const
	{
		return head == nullptr;
	}

	// Method to clear the list
	void clear()
	{
		while (!empty())
		{
			pop_front();
		}
	}

	// Method to print the elements of the list
	void print() const
	{
		Node<T> *current = head;
		while (current)
		{
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
};

int main()
{
	SinglyLinkedList<int> myList;

	// Insert elements at the beginning
	myList.push_front(10);
	myList.push_front(20);
	myList.push_front(30);

	// Insert elements at the end
	myList.push_back(40);
	myList.push_back(50);

	// Print the list
	myList.print(); // Output: 30 20 10 40 50

	// Remove the first element
	myList.pop_front();

	// Print the list after removal
	myList.print(); // Output: 20 10 40 50

	// Clear the list
	myList.clear();

	return 0;
}
