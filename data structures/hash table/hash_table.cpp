#include <iostream>
#include <list>
#include <vector>

class HashNode
{
public:
	int key;
	int value;
	HashNode(int key, int value) : key(key), value(value) {}
};

class HashTable
{
private:
	std::vector<std::list<HashNode>> table;
	int size;

	int hashFunction(int key)
	{
		return key % size;
	}

public:
	HashTable(int size);
	void insert(int key, int value);
	void remove(int key);
	int search(int key);
	void display();
};

// Constructor to initialize hash table
HashTable::HashTable(int size)
{
	this->size = size;
	table.resize(size);
}

// Insert key-value pair into the hash table
void HashTable::insert(int key, int value)
{
	int index = hashFunction(key);
	for (auto &node : table[index])
	{
		if (node.key == key)
		{
			node.value = value; // Update existing key
			return;
		}
	}
	table[index].emplace_back(key, value); // Add new key-value pair
}

// Remove key-value pair from the hash table
void HashTable::remove(int key)
{
	int index = hashFunction(key);
	for (auto it = table[index].begin(); it != table[index].end(); ++it)
	{
		if (it->key == key)
		{
			table[index].erase(it);
			return;
		}
	}
	std::cout << "Key " << key << " not found." << std::endl;
}

// Search for value by key
int HashTable::search(int key)
{
	int index = hashFunction(key);
	for (auto &node : table[index])
	{
		if (node.key == key)
		{
			return node.value;
		}
	}
	return -1; // Key not found
}

// Display the hash table
void HashTable::display()
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << "Bucket " << i << ": ";
		for (auto &node : table[i])
		{
			std::cout << "(" << node.key << ", " << node.value << ") ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	HashTable hashTable(10);

	hashTable.insert(1, 10);
	hashTable.insert(2, 20);
	hashTable.insert(3, 30);
	hashTable.insert(11, 40); // This will collide with key 1 if size is 10

	std::cout << "Hash Table:" << std::endl;
	hashTable.display();

	std::cout << "Value at key 2: " << hashTable.search(2) << std::endl;

	hashTable.remove(2);
	std::cout << "Hash Table after removing key 2:" << std::endl;
	hashTable.display();

	std::cout << "Value at key 2: " << hashTable.search(2) << std::endl;

	return 0;
}
