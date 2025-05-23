#ifndef DICTIONARYAVLTREE_H
#define DICTIONARYAVLTREE_H

#include "../structs/AVLNode.h"

class DictionaryAVLTree
{
public:
	DictionaryAVLTree();
	~DictionaryAVLTree(); // Destructor

	void insert(const WordTranslations &word);
	void remove(const std::string &word);
	void inOrderTraversal() const;
	AVLNode *getRoot() const;

private:
	AVLNode *root;

	AVLNode *insert(AVLNode *node, const WordTranslations &word);
	AVLNode *removeNode(AVLNode *node, const std::string &word);
	AVLNode *findMinNode(AVLNode *node);
	int getHeight(AVLNode *node);
	int getBalanceFactor(AVLNode *node);

	AVLNode *rotateRight(AVLNode *unbalancedNode);
	AVLNode *rotateLeft(AVLNode *unbalancedNode);

	void inOrderTraversal(AVLNode *node) const;
	void destroyTree(AVLNode *node);
};

#endif // DictionaryAVLTree_H