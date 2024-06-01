#include <iostream>

// Node structure
struct Node
{
	int data;
	Node *next;
	Node *prev;

	Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
public:
	Node *head;

public:
	DoublyLinkedList() : head(nullptr) {}

	// Function to add a node at the front of the list
	void push(int data);

	// Function to add a node at the end of the list
	void append(int data);

	// Function to insert a node after a given previous node
	void insertAfter(Node *prevNode, int data);

	// Function to delete a node from the list
	void deleteNode(Node *delNode);

	// Function to display the list
	void display();

	// Function to reverse the list
	void reverse();
};

void DoublyLinkedList::push(int data)
{
	Node *newNode = new Node(data);

	newNode->next = head;
	newNode->prev = nullptr;

	if (head != nullptr)
	{
		head->prev = newNode;
	}

	head = newNode;
}

void DoublyLinkedList::append(int data)
{
	Node *newNode = new Node(data);

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	Node *temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;
}

void DoublyLinkedList::insertAfter(Node *prevNode, int data)
{
	if (prevNode == nullptr)
	{
		std::cout << "The given previous node cannot be NULL\n";
		return;
	}

	Node *newNode = new Node(data);
	newNode->next = prevNode->next;
	newNode->prev = prevNode;

	if (prevNode->next != nullptr)
	{
		prevNode->next->prev = newNode;
	}

	prevNode->next = newNode;
}

void DoublyLinkedList::deleteNode(Node *delNode)
{
	if (head == nullptr || delNode == nullptr)
	{
		return;
	}

	if (head == delNode)
	{
		head = delNode->next;
	}

	if (delNode->next != nullptr)
	{
		delNode->next->prev = delNode->prev;
	}

	if (delNode->prev != nullptr)
	{
		delNode->prev->next = delNode->next;
	}

	delete delNode;
}

void DoublyLinkedList::display()
{
	Node *temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

void DoublyLinkedList::reverse()
{
	Node *temp = nullptr;
	Node *current = head;

	while (current != nullptr)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != nullptr)
	{
		head = temp->prev;
	}
}

int main()
{
	DoublyLinkedList dll;

	dll.push(10);
	dll.push(20);
	dll.append(30);
	dll.insertAfter(dll.head, 25);

	std::cout << "Created DLL: ";
	dll.display();

	dll.deleteNode(dll.head->next);
	std::cout << "DLL after deletion: ";
	dll.display();

	dll.reverse();
	std::cout << "Reversed DLL: ";
	dll.display();

	return 0;
}
