#include <iostream>

// Node structure
struct Node
{
	int data;
	Node *next;

	Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList
{
public:
	Node *last; // Pointer to the last node

public:
	CircularLinkedList() : last(nullptr) {}

	// Function to add a node at the front of the list
	void push(int data);

	// Function to add a node at the end of the list
	void append(int data);

	// Function to insert a node after a given previous node
	void insertAfter(Node *prevNode, int data);

	// Function to delete a node from the list
	void deleteNode(int key);

	// Function to display the list
	void display();
};

void CircularLinkedList::push(int data)
{
	Node *newNode = new Node(data);

	if (last == nullptr)
	{
		last = newNode;
		newNode->next = newNode; // Point to itself
	}
	else
	{
		newNode->next = last->next;
		last->next = newNode;
	}
}

void CircularLinkedList::append(int data)
{
	Node *newNode = new Node(data);

	if (last == nullptr)
	{
		last = newNode;
		newNode->next = newNode; // Point to itself
	}
	else
	{
		newNode->next = last->next;
		last->next = newNode;
		last = newNode;
	}
}

void CircularLinkedList::insertAfter(Node *prevNode, int data)
{
	if (prevNode == nullptr)
	{
		std::cout << "The given previous node cannot be NULL\n";
		return;
	}

	Node *newNode = new Node(data);
	newNode->next = prevNode->next;
	prevNode->next = newNode;

	if (prevNode == last)
	{
		last = newNode;
	}
}

void CircularLinkedList::deleteNode(int key)
{
	if (last == nullptr)
	{
		std::cout << "List is empty." << std::endl;
		return; // List is empty
	}

	Node *current = last->next; // Start from the first node
	Node *previous = last;

	// Check if the node to be deleted is the only node in the list
	if (last->next == last && last->data == key)
	{
		delete last;
		last = nullptr;
		return;
	}

	// Loop through the list to find the node to delete
	do
	{
		// Node to be deleted is found
		if (current->data == key)
		{
			// Adjust the pointers to remove the node
			previous->next = current->next;

			// If the node to be deleted is the last node
			if (current == last)
			{
				last = previous;
			}

			// If the node to be deleted is the first node
			if (current == last->next)
			{
				last->next = current->next;
			}

			delete current;
			return;
		}

		previous = current;
		current = current->next;

	} while (current != last->next); // Continue until we loop back to the start node
}

void CircularLinkedList::display()
{
	if (last == nullptr)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}

	Node *temp = last->next;
	do
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	} while (temp != last->next);

	std::cout << std::endl;
}

int main()
{
	CircularLinkedList cll;

	cll.append(10);
	cll.append(20);
	cll.append(30);
	cll.push(5);

	std::cout << "Created CLL: ";
	cll.display();

	cll.insertAfter(cll.last->next, 15);
	std::cout << "CLL after insertion: ";
	cll.display();

	cll.deleteNode(5);
	cll.deleteNode(10);
	cll.deleteNode(20);
	cll.deleteNode(30);
	std::cout << "CLL after deletion: ";
	cll.display();

	return 0;
}
