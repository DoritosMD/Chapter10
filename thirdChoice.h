#pragma once
#ifndef OPTION_THREE_LOCK
#define OPTION_THREE_LOCK

#include <iostream>
#include <fstream>
#include <string>
#include "input.h"
#include "bTree.h"
#include "binary_tree_node.h"

using namespace std;

binary_tree_node<string>* default_tree();
void play(binary_tree_node<string>* current_ptr);
void askAndMove(binary_tree_node<string>*& current_ptr);
void learn(binary_tree_node<string>* leaf_ptr);
void writeTreeToFile(binary_tree_node<string>* ptr, ostream& outs);
void readTreeFromFile(binary_tree_node<string>*& ptr, istream& ins);
bool inquire(string prompt);

//Precondition: N/A
//Postcondition: Returns pointer to root node.
binary_tree_node<string>* default_tree()
{
	binary_tree_node<string>* root_ptr;
	binary_tree_node<string>* child_ptr;

	const string root_question("Is it a mammal?");
	const string left_question("Does it have stripes?");
	const string right_question("Is it a bird?");
	const string animal1("zebra");
	const string animal2("lion");
	const string animal3("eagle");
	const string animal4("gila monster");

	root_ptr = new binary_tree_node<string>(root_question);

	child_ptr = new binary_tree_node<string>(left_question);
	child_ptr->setLeft(new binary_tree_node<string>(animal1));
	child_ptr->setRight(new binary_tree_node<string>(animal2));
	root_ptr->setLeft(child_ptr);

	child_ptr = new binary_tree_node<string>(right_question);
	child_ptr->setLeft(new binary_tree_node<string>(animal3));
	child_ptr->setRight(new binary_tree_node<string>(animal4));
	root_ptr->setRight(child_ptr);

	return root_ptr;
}
//Precondition: Pointer to the root node is needed.
//Postcondition: New question and answer are added to tree.
void play(binary_tree_node<string>* current_ptr)
{
	cout << "\n\tThink of an animal, then press any key to continue.\n\n";
	system("pause");

	while (!current_ptr->isLeaf())
		askAndMove(current_ptr);
	cout << ("\n\tMy guess is " + current_ptr->getData() + ". ");
	if (!inquire("\n\tAm I right? (Y/Yes or N/No): "))
	{
		learn(current_ptr);
		cout << "\n\tThanks for teaching me a thing or two.\n\n";
	}
	else
		cout << "\n\tI knew it all along!\n";
}
//Precondition: Pointer to root node is needed.
//Postcondition: Moves pointer throughout the tree.
void askAndMove(binary_tree_node<string>*& current_ptr)
{
	cout << "\n\t" << current_ptr->getData();
	if (inquire("\n\tPlease answer (Y/Yes or N/No): "))
		current_ptr = current_ptr->getLeft();
	else
		current_ptr = current_ptr->getRight();
}
//Precondition: Pointer to a current leaf is needed.
//Postcondition: Adds new information to the tree based on user input.
void learn(binary_tree_node<string>* leaf_ptr)
{
	string guess_animal;
	string correct_animal;
	string new_question;

	cin.ignore();

	guess_animal = leaf_ptr->getData();
	correct_animal = inputString("\n\tI give up. What are you?: ", true);

	cout << "\n\tPlease type a yes/no question that will distinguish a " << correct_animal << " from a " << guess_animal << ".";
	new_question = inputString("\n\tYour question: ", true);

	leaf_ptr->setData(new_question);
	cout << "\n\tAs a " << correct_animal << ", " << new_question;
	if (inquire("\n\tPlease answer (Y/Yes or N/No): "))
	{
		leaf_ptr->setLeft(new binary_tree_node<string>(correct_animal));
		leaf_ptr->setRight(new binary_tree_node<string>(guess_animal));
	}
	else
	{
		leaf_ptr->setLeft(new binary_tree_node<string>(guess_animal));
		leaf_ptr->setRight(new binary_tree_node<string>(correct_animal));
	}
}
//Precondition: Pointer to the root node is needed.
//Postcondition: Writes data from tree to file.
void writeTreeToFile(binary_tree_node<string>* ptr, ostream& outs)
{
	if (ptr == nullptr) 
		outs << "#\n"; 
	else
	{
		outs << ptr->getData() << '\n';
		writeTreeToFile(ptr->getLeft(), outs);
		writeTreeToFile(ptr->getRight(), outs);
	}
}
//Precondition: Pointer is needed.
//Postcondition: Reads data from file to tree.
void readTreeFromFile(binary_tree_node<string>*& ptr, istream& ins)
{
	string current;
	if (ins.eof())
	{
		return;
	}
	else
	{
		getline(ins, current, '\n');

		if (current == "#") 
			return;
		else
		{
			ptr = new binary_tree_node<string>(current);
			readTreeFromFile(ptr->getLeft(), ins);
			readTreeFromFile(ptr->getRight(), ins);
		}
	}
}
//Precondition: N/A
//Postcondition: Returns true/false based on user input.
bool inquire(string prompt)
{
	char answer = inputChar(prompt, 'Y', 'N');
	if (toupper(answer) == 'Y')
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif