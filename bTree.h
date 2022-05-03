#pragma once
#ifndef BTREE_LOCK
#define BTREE_LOCK

#include <iostream>

template<class T>
class TreeNode
{
public:
	template<class T>
	friend class bTree;
	TreeNode(const T& _data = T(), TreeNode* _leftNode = NULL, TreeNode* _rightNode = NULL) //Constructor
		:data(_data), leftNode(_leftNode), rightNode(_rightNode)
	{}
private:
	T data;
	TreeNode* leftNode;
	TreeNode* rightNode;
};
template<class T>
class bTree
{
private:
	TreeNode<T>* root;
	int nodeCount;
public:
	bTree() //Constructor
	{
		root = NULL;
		nodeCount = 0;
	}
	bTree(const T& _data) //Constructor
	{
		TreeNode<T>* temp = new TreeNode<int>(_data);
		root = temp;
		nodeCount = 0;
	}
	~bTree() //Destructor
	{
		deleteTree();
	}
	//Precondition: Root can be NULL.
	//Postcondition: Pushes value by calling function.
	void push(const T& _data)
	{
		TreeNode<T>* thisNode = new TreeNode<T>(_data);
		if (root == NULL) { root = thisNode; return; }
		TreeNode<T>* currentNode = root;
		insert(thisNode, currentNode);
	}
	//Precondition: N/A
	//Postcondition: Inserts value with recursion.
	void insert(TreeNode<T>* thisNode, TreeNode<T>* currentNode)
	{
		if (thisNode->data < currentNode->data || thisNode->data == currentNode->data)
		{
			if (currentNode->leftNode == NULL)
			{
				currentNode->leftNode = thisNode;
				return;
			}
			else insert(thisNode, currentNode->leftNode);
		}
		else
		{
			if (currentNode->rightNode == NULL)
			{
				currentNode->rightNode = thisNode;
				return;
			}
			else insert(thisNode, currentNode->rightNode);
		}
	}
	//Precondition: N/A
	//Postcondition: Displays contents using pre-order traversal.
	void printPreOrder(void)
	{
		if (root == NULL) throw invalid_argument("ERROR: bTree is empty.");
		TreeNode<T>* currentNode = root;
		iteratePreOrder(currentNode);
	}
	//Precondition: N/A
	//Postcondition: Uses pointer to access node from left/right using pre-order traversal.
	void iteratePreOrder(TreeNode<T>* currentNode)
	{
		if (currentNode != NULL)
		{
			std::cout << "\t\t" << currentNode->data << std::endl;
			iteratePreOrder(currentNode->leftNode);

		}
		else return;
		iteratePreOrder(currentNode->rightNode);
	}
	//Precondition: N/A
	//Postcondition: Dispalys contents using in-order traversal.
	void printInOrder(void)
	{
		if (root == NULL) throw invalid_argument("ERROR: bTree is empty.");
		TreeNode<T>* currentNode = root;
		iterateInOrder(currentNode);
	}
	//Precondition: N/A
	//Postcondition: Uses pointer to access node from left/right using in-order traversal.
	void iterateInOrder(TreeNode<T>* currentNode)
	{
		if (currentNode != NULL)
		{
			iterateInOrder(currentNode->leftNode);
		}
		else return;
		std::cout << "\t\t" << currentNode->data << std::endl;
		iterateInOrder(currentNode->rightNode);
	}
	//Precondition: N/A
	//Postcondition: Displays contents using post-order traversal.
	void printPostOrder(void)
	{
		if (root == NULL) throw invalid_argument("ERROR: bTree is empty.");
		TreeNode<T>* currentNode = root;
		iteratePostOrder(currentNode);
	}
	//Precondition: N/A
	//Postcondition: Uses pointer to access node from left/right using post-order traversal.
	void iteratePostOrder(TreeNode<T>* currentNode)
	{
		if (currentNode != NULL)
		{
			iteratePostOrder(currentNode->leftNode);
		}
		else return;
		iteratePostOrder(currentNode->rightNode);
		std::cout << "\t\t" << currentNode->data << std::endl;
	}
	//Precondition: N/A
	//Postcondition: Deletes tree.
	void deleteTree(void)
	{
		TreeNode<T>* currentNode = root;
		iteratePostOrderDelete(currentNode);
		root = NULL;
		nodeCount = 0;
	}
	//Precondition: N/A
	//Postcondition: Uses pointer to access node from left/right using post-order traversal method.
	void iteratePostOrderDelete(TreeNode<T>* currentNode)
	{
		if (currentNode != NULL)
		{
			iteratePostOrderDelete(currentNode->leftNode);
		}
		else return;
		iteratePostOrderDelete(currentNode->rightNode);
		delete currentNode;
	}
	//Precondition: N/A
	//Postcondition: Returns number of nodes in tree.
	int countNodes(void)
	{
		nodeCount = 0;
		TreeNode<T>* currentNode = root;
		iteratePostOrderCount(currentNode);
		return nodeCount;
	}
	//Precondition: N/A
	//Postcondition: Uses pointer to access node from left/right using post-order traversal method.
	void iteratePostOrderCount(TreeNode<T>* currentNode)
	{
		if (currentNode != NULL)
		{
			iteratePostOrderCount(currentNode->leftNode);
		}
		else return;
		iteratePostOrderCount(currentNode->rightNode);
		nodeCount++;
	}
	//Precondition: Valid node must be found.
	//Postcondition: Returns true when node is found; otherwise, false.
	bool searchNode(T nodeData)
	{
		if (root == NULL) throw invalid_argument("ERROR: bTree is empty.");
		bool nodeFound = false;
		TreeNode<T>* currentNode = root;
		iteratePostOrderSearch(currentNode, nodeFound, nodeData);
		return nodeFound;
	}
	//Precondition: N/A
	//Postcondition: Find indicated node in tree.
	void iteratePostOrderSearch(TreeNode<T>* currentNode, bool& nodeFound, T nodeData)
	{
		if (currentNode != NULL)
		{
			iteratePostOrderSearch(currentNode->leftNode, nodeFound, nodeData);
		}
		else return;
		iteratePostOrderSearch(currentNode->rightNode, nodeFound, nodeData);
		if (currentNode->data == nodeData) nodeFound = true;
	}
};
#endif