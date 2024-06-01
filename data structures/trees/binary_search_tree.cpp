#include <iostream>

class TreeNode
{
public:
	int key;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BST
{
private:
	TreeNode *root;

	TreeNode *search(TreeNode *root, int key);
	TreeNode *insert(TreeNode *root, int key);
	TreeNode *deleteNode(TreeNode *root, int key);
	void inorderTraversal(TreeNode *root);

public:
	BST() : root(nullptr) {}
	void insert(int key);
	void remove(int key);
	bool find(int key);
	void inorder();
};

// Search for a key in the tree
TreeNode *BST::search(TreeNode *root, int key)
{
	if (root == nullptr || root->key == key)
		return root;
	if (root->key < key)
		return search(root->right, key);
	return search(root->left, key);
}

// Insert a key into the tree
TreeNode *BST::insert(TreeNode *root, int key)
{
	if (root == nullptr)
		return new TreeNode(key);
	if (key < root->key)
		root->left = insert(root->left, key);
	else if (key > root->key)
		root->right = insert(root->right, key);
	return root;
}

// Delete a node with a given key from the tree
TreeNode *BST::deleteNode(TreeNode *root, int key)
{
	if (root == nullptr)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == nullptr)
		{
			TreeNode *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr)
		{
			TreeNode *temp = root->left;
			delete root;
			return temp;
		}
		TreeNode *temp = root->right;
		while (temp->left != nullptr)
			temp = temp->left;
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

// Inorder traversal of the tree
void BST::inorderTraversal(TreeNode *root)
{
	if (root == nullptr)
		return;
	inorderTraversal(root->left);
	std::cout << root->key << " ";
	inorderTraversal(root->right);
}

// Public method to insert a key
void BST::insert(int key)
{
	root = insert(root, key);
}

// Public method to remove a key
void BST::remove(int key)
{
	root = deleteNode(root, key);
}

// Public method to find a key
bool BST::find(int key)
{
	return search(root, key) != nullptr;
}

// Public method to perform inorder traversal
void BST::inorder()
{
	inorderTraversal(root);
	std::cout << std::endl;
}

int main()
{
	BST bst;

	bst.insert(50);
	bst.insert(30);
	bst.insert(70);
	bst.insert(20);
	bst.insert(40);
	bst.insert(60);
	bst.insert(80);

	std::cout << "Inorder traversal of the tree: ";
	bst.inorder();

	int key = 40;
	std::cout << "Key " << key << " " << (bst.find(key) ? "found" : "not found") << std::endl;

	bst.remove(40);
	std::cout << "Inorder traversal after removing 40: ";
	bst.inorder();

	return 0;
}
