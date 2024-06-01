#include <iostream>

class AVLNode
{
public:
	int key;
	AVLNode *left;
	AVLNode *right;
	int height;

	AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
private:
	AVLNode *root;

	AVLNode *insert(AVLNode *node, int key);
	AVLNode *deleteNode(AVLNode *node, int key);
	AVLNode *minValueNode(AVLNode *node);
	int height(AVLNode *node);
	int getBalance(AVLNode *node);
	AVLNode *leftRotate(AVLNode *x);
	AVLNode *rightRotate(AVLNode *y);
	void preOrder(AVLNode *node);

public:
	AVLTree() : root(nullptr) {}
	void insert(int key);
	void deleteNode(int key);
	void preOrder();
};

// Helper function to get the height of the tree
int AVLTree::height(AVLNode *node)
{
	if (node == nullptr)
		return 0;
	return node->height;
}

// Helper function to get the balance factor of the node
int AVLTree::getBalance(AVLNode *node)
{
	if (node == nullptr)
		return 0;
	return height(node->left) - height(node->right);
}

// Right rotate
AVLNode *AVLTree::rightRotate(AVLNode *y)
{
	AVLNode *x = y->left;
	AVLNode *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = std::max(height(y->left), height(y->right)) + 1;
	x->height = std::max(height(x->left), height(x->right)) + 1;

	// Return new root
	return x;
}

// Left rotate
AVLNode *AVLTree::leftRotate(AVLNode *x)
{
	AVLNode *y = x->right;
	AVLNode *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = std::max(height(x->left), height(x->right)) + 1;
	y->height = std::max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

// Insert a node
AVLNode *AVLTree::insert(AVLNode *node, int key)
{
	if (node == nullptr)
		return new AVLNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	node->height = 1 + std::max(height(node->left), height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

void AVLTree::insert(int key)
{
	root = insert(root, key);
}

// Find the node with the minimum key value
AVLNode *AVLTree::minValueNode(AVLNode *node)
{
	AVLNode *current = node;

	while (current->left != nullptr)
		current = current->left;

	return current;
}

// Delete a node
AVLNode *AVLTree::deleteNode(AVLNode *root, int key)
{
	if (root == nullptr)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else
	{
		if ((root->left == nullptr) || (root->right == nullptr))
		{
			AVLNode *temp = root->left ? root->left : root->right;

			if (temp == nullptr)
			{
				temp = root;
				root = nullptr;
			}
			else
				*root = *temp;
			delete temp;
		}
		else
		{
			AVLNode *temp = minValueNode(root->right);

			root->key = temp->key;

			root->right = deleteNode(root->right, temp->key);
		}
	}

	if (root == nullptr)
		return root;

	root->height = 1 + std::max(height(root->left), height(root->right));

	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void AVLTree::deleteNode(int key)
{
	root = deleteNode(root, key);
}

// Pre-order traversal
void AVLTree::preOrder(AVLNode *node)
{
	if (node != nullptr)
	{
		std::cout << node->key << " ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

void AVLTree::preOrder()
{
	preOrder(root);
	std::cout << std::endl;
}

int main()
{
	AVLTree tree;

	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);
	tree.insert(25);

	std::cout << "Pre-order traversal of the constructed AVL tree is:\n";
	tree.preOrder();

	tree.deleteNode(20);

	std::cout << "Pre-order traversal after deletion of 20:\n";
	tree.preOrder();

	return 0;
}
