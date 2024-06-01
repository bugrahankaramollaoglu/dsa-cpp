#include <iostream>

class TreeNode
{
public:
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
	TreeNode *root;

public:
	BinaryTree() : root(nullptr) {}

	void insert(int value);
	bool search(int value);
	void remove(int value);
	void preorderTraversal(TreeNode *node);
	void inorderTraversal(TreeNode *node);
	void postorderTraversal(TreeNode *node);

	void preorder();
	void inorder();
	void postorder();
};

void BinaryTree::insert(int value)
{
	TreeNode *newNode = new TreeNode(value);

	if (root == nullptr)
	{
		root = newNode;
		return;
	}

	TreeNode *current = root;
	TreeNode *parent = nullptr;

	while (current != nullptr)
	{
		parent = current;
		if (value < current->data)
			current = current->left;
		else
			current = current->right;
	}

	if (value < parent->data)
		parent->left = newNode;
	else
		parent->right = newNode;
}

bool BinaryTree::search(int value)
{
	TreeNode *current = root;

	while (current != nullptr)
	{
		if (value == current->data)
			return true;
		else if (value < current->data)
			current = current->left;
		else
			current = current->right;
	}

	return false;
}

void BinaryTree::remove(int value)
{
	// Implementation of remove operation
}

void BinaryTree::preorderTraversal(TreeNode *node)
{
	if (node == nullptr)
		return;

	std::cout << node->data << " ";
	preorderTraversal(node->left);
	preorderTraversal(node->right);
}

void BinaryTree::inorderTraversal(TreeNode *node)
{
	if (node == nullptr)
		return;

	inorderTraversal(node->left);
	std::cout << node->data << " ";
	inorderTraversal(node->right);
}

void BinaryTree::postorderTraversal(TreeNode *node)
{
	if (node == nullptr)
		return;

	postorderTraversal(node->left);
	postorderTraversal(node->right);
	std::cout << node->data << " ";
}

void BinaryTree::preorder()
{
	std::cout << "Preorder traversal: ";
	preorderTraversal(root);
	std::cout << std::endl;
}

void BinaryTree::inorder()
{
	std::cout << "Inorder traversal: ";
	inorderTraversal(root);
	std::cout << std::endl;
}

void BinaryTree::postorder()
{
	std::cout << "Postorder traversal: ";
	postorderTraversal(root);
	std::cout << std::endl;
}

int main()
{
	BinaryTree tree;

	tree.insert(50);
	tree.insert(30);
	tree.insert(70);
	tree.insert(20);
	tree.insert(40);
	tree.insert(60);
	tree.insert(80);

	tree.inorder();
	tree.preorder();
	tree.postorder();

	int key = 40;
	std::cout << "Key " << key << " " << (tree.search(key) ? "found" : "not found") << std::endl;

	return 0;
}
