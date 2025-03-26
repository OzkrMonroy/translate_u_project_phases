#include "DictionaryAVLTree.h"
#include <iostream>

using namespace std;

DictionaryAVLTree::DictionaryAVLTree() : root(nullptr) {}

DictionaryAVLTree::~DictionaryAVLTree()
{
	destroyTree(root);
}

void DictionaryAVLTree::insert(const WordTranslations &word)
{
	root = insert(root, word);
}

void DictionaryAVLTree::remove(const string &word)
{
	root = removeNode(root, word);
}

AVLNode *DictionaryAVLTree::insert(AVLNode *node, const WordTranslations &word)
{
	if (!node)
		return new AVLNode(word);

	if (word.spanish < node->word.spanish)
	{
		node->left = insert(node->left, word);
	}
	else if (word.spanish > node->word.spanish)
	{
		node->right = insert(node->right, word);
	}
	else
	{
		return node;
	}

	node->height = 1 + max(getHeight(node->left), getHeight(node->right));

	int balance = getBalanceFactor(node);

	if (balance > 1 && word.spanish < node->left->word.spanish)
	{
		return rotateRight(node);
	}
	if (balance < -1 && word.spanish > node->right->word.spanish)
	{
		return rotateLeft(node);
	}
	if (balance > 1 && word.spanish > node->left->word.spanish)
	{
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}
	if (balance < -1 && word.spanish < node->right->word.spanish)
	{
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}

	return node;
}

AVLNode *DictionaryAVLTree::removeNode(AVLNode *node, const string &word)
{
	if (!node)
		return nullptr;

	if (word < node->word.spanish)
	{
		node->left = removeNode(node->left, word);
	}
	else if (word > node->word.spanish)
	{
		node->right = removeNode(node->right, word);
	}
	else
	{
		if (!node->left || !node->right)
		{
			AVLNode *temp = node->left ? node->left : node->right;
			if (!temp)
			{
				temp = node;
				node = nullptr;
			}
			else
			{
				*node = *temp;
			}

			delete temp;
		}
		else
		{
			AVLNode *temp = findMinNode(node->right);
			node->word = temp->word;
			node->right = removeNode(node->right, temp->word.spanish);
		}
	}
}

AVLNode *DictionaryAVLTree::findMinNode(AVLNode *node)
{
	while (node->left)
		node = node->left;
	return node;
}

int DictionaryAVLTree::getHeight(AVLNode *node)
{
	return node ? node->height : 0;
}

int DictionaryAVLTree::getBalanceFactor(AVLNode *node)
{
	return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLNode *DictionaryAVLTree::rotateRight(AVLNode *unbalancedNode)
{
	AVLNode *newRoot = unbalancedNode->left;
	AVLNode *rightSubtreeOfNewRoot = newRoot->right;

	newRoot->right = unbalancedNode;
	unbalancedNode->left = rightSubtreeOfNewRoot;

	unbalancedNode->height = 1 + max(getHeight(unbalancedNode->left), getHeight(unbalancedNode->right));
	newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

	return newRoot;
}

AVLNode *DictionaryAVLTree::rotateLeft(AVLNode *unbalancedNode)
{
	AVLNode *newRoot = unbalancedNode->right;
	AVLNode *leftSubtreeOfNewRoot = newRoot->left;

	newRoot->left = unbalancedNode;
	unbalancedNode->right = leftSubtreeOfNewRoot;

	unbalancedNode->height = 1 + max(getHeight(unbalancedNode->left), getHeight(unbalancedNode->right));
	newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

	return newRoot;
}

void DictionaryAVLTree::inOrderTraversal() const
{
	inOrderTraversal(root);
}

void DictionaryAVLTree::inOrderTraversal(AVLNode *node) const
{
	if (!node)
		return;

	inOrderTraversal(node->left);
	cout << "Español: " << node->word.spanish << " | ";
	cout << "Inglés: " << node->word.english << " | ";
	cout << "Italiano: " << node->word.italian << " | ";
	cout << "Francés: " << node->word.french << " | ";
	cout << "Alemán: " << node->word.german << " | " << endl;

	inOrderTraversal(node->right);
}

void DictionaryAVLTree::destroyTree(AVLNode *node)
{
	if (!node)
		return;

	destroyTree(node->left);
	destroyTree(node->right);
	delete node;
}