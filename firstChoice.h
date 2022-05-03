#pragma once
#ifndef FIRST_CHOCIE_LOCK
#define FIRST_CHOIC_LOCK
#include <iostream>
#include <string>
#include "binary_tree_node.h"

using namespace std;

//Precondition: Input binary tree node.
//Postcondition: Create root node.
void createdRoot(binary_tree_node<string>*& root)
{
    root->setData("Trunk");
    cout << "\n\tA> Created root (" << root->getData() << ") with no leaf.\n";
    cout << '\n';
    print_tree("\t\t", root, false, true, false);
}
//Precondition: Input binary tree node.
//Postcondition: Creates two branches for tree.
void createdBranches(binary_tree_node<string>*& root)
{
    binary_tree_node<string>* branch1 = new binary_tree_node<string>;
    branch1->setData("branch #1");
    binary_tree_node<string>* branch2 = new binary_tree_node<string>;
    branch2->setData("branch #2");

    cout << "\n\tB> Root (" << root->getData() << ") grows two branches: " << branch1->getData() << " and " << branch2->getData() << ".\n";
    root->setLeft(branch1);
    cout << "\t\tA branch of (" << root->getLeft()->getData() << ") grows left of the root.\n";
    root->setRight(branch2);
    cout << "\t\tA branch of (" << root->getRight()->getData() << ") grows right of the root.\n";

    cout << '\n';
    print_tree("\t\t", root, false, true, false);
}
//Precondition: Input binary tree node.
//Postcondition: Creates leaves for tree.
void createdLeaves(binary_tree_node<string>*& root)
{
    cout << "\n\tC> Branches grows leaves.\n";
    binary_tree_node<string>* leftLeaf1 = new binary_tree_node<string>;
    leftLeaf1->setData("leaf #1");
    root->getLeft()->setLeft(leftLeaf1);

    binary_tree_node<string>* leftLeaf2 = new binary_tree_node<string>;
    leftLeaf2->setData("leaf #2");
    root->getLeft()->setRight(leftLeaf2);
    cout << "\n\t\tLeft branch of (" << root->getLeft()->getData() << ") grows two leaves: " << leftLeaf1->getData() << " and " << leftLeaf2->getData() << ".\n";

    cout << '\n';
    print_tree("\t\t", root, false, true, false);
    binary_tree_node<string>* rightLeaf1 = new binary_tree_node<string>;
    rightLeaf1->setData("leaf #3");
    root->getRight()->setLeft(rightLeaf1);

    binary_tree_node<string>* rightLeaf2 = new binary_tree_node<string>;
    rightLeaf2->setData("leaf #4");
    root->getRight()->setRight(rightLeaf2);
    cout << "\n\t\tRight branch of (" << root->getRight()->getData() << ") grows two leaves: " << rightLeaf1->getData() << " and " << rightLeaf2->getData() << ".\n";

    cout << '\n';
    print_tree("\t\t", root, false, true, false);

    binary_tree_node<string>* fruit = new binary_tree_node<string>;
    fruit->setData("apple");
    root->getLeft()->getLeft()->setLeft(fruit);
    cout << "\n\tD>. Left leaf sprouts and yields a fruit (" << fruit->getData() << ").\n";

    cout << '\n';
    print_tree("\t\t", root, false, true, false);

    binary_tree_node<string>* fruit2 = new binary_tree_node<string>;
    fruit2->setData("orange");
    binary_tree_node<string>* fruit3 = new binary_tree_node<string>;
    fruit3->setData("coconut");
    root->getRight()->getLeft()->setLeft(fruit2);
    root->getRight()->getLeft()->setRight(fruit3);
    cout << "\n\tE> Right leaf sprouts and yields two fruits (" << fruit2->getData() << " and " << fruit3->getData() << ").\n";

    cout << '\n';
    print_tree("\t\t", root, false, true, false);
}
//Precondition: Input binary tree node.
//Postcondition: Deletes the tree.
void deleteTree(binary_tree_node<string>*& root)
{
    cout << "\n\tF> Delete tree.\n";
    delete_tree<string>(root);
    cout << '\n';
    root = NULL;
    if (root != NULL)
    {
        cout << '\n';
        print_tree("\t\t", root, false, true, false);
    }
    cout << '\n';
}
#endif