#pragma once
// Name: prof Q
// Date: 11-3-2021
// Description: binary tree node for growing a tree

#include <iostream>
#include <string>
using namespace std;

template <class Item>
class binary_tree_node
{
private:
    Item data;
    binary_tree_node* left;
    binary_tree_node* right;

public:

    //constructor
    binary_tree_node(const Item& init_data = Item(), binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL)
    {
        data = init_data;
        left = init_left;
        right = init_right;
    }
    //Precondition: N/A
    //Postcondition: Returns value of node.    
    Item& getData()
    {
        return data;
    }
    //Precondition: N/A
    //Postcondition: Return left node.
    binary_tree_node*& getLeft()
    {
        return left;
    }
    //Precondition: N/A
    //Postcondition: Returns right node.
    binary_tree_node*& getRight()
    {
        return right;
    }
    //Precondition: N/A
    //Postcondition: Sets data for node.
    void setData(const Item& new_data)
    {
        data = new_data;
    }
    //Precondition: N/A
    //Postcondition: Sets left node.
    void setLeft(binary_tree_node* new_left)
    {
        left = new_left;
    }
    //Precondition: N/A
    //Postcondition: Sets right node.
    void setRight(binary_tree_node* new_right)
    {
        right = new_right;
    }
    //Precondition: N/A
    //Postcondition: Returns value of node.
    const Item& getData() const
    {
        return data;
    }
    //Precondition: N/A
    //Postcondition: Returns left node.
    const binary_tree_node* getLeft() const
    {
        return left;
    }
    //Precondition: N/A
    //Postcondition: Return right node.
    const binary_tree_node* getRight() const
    {
        return right;
    }
    //Precondition: N/A
    //Postcondition: Return true if node is leaf; otherwise, false.
    bool isLeaf() const
    {
        return (left == NULL && right == NULL);
    }

};
//Precondition: Input binary tree node.
//Postcondition: Deletes tree with recursion.
template<class Item>
void delete_tree(binary_tree_node<Item>* leaf) 
{
    if (leaf == NULL)
        return;

    delete_tree(leaf->getLeft());
    delete_tree(leaf->getRight());
    
    cout << "\n\t\tDeleting: " << leaf->getData();
    delete leaf;
}
//Precondition: Input string.
//Postcondition: Displays tree.
template<class Item>
void print_tree(const string& prefix, const binary_tree_node<Item>* node, bool isLeft, bool root, bool last)
{
    if (node != NULL)
    {
        cout << prefix;
        if (!root)
        {
            if (isLeft)
            {
                if (node->getLeft() == NULL && node->getRight() == NULL)
                    cout << char(192) << string(3, char(196));
                else
                    cout << char(195) << string(3, char(196));
            }
            else
            {
                if (last)
                    cout << char(192) << string(3, char(196));
                else
                    cout << char(195) << string(3, char(196));
            }
            cout << " " << node->getData() << '\n';
        }
        else
            cout << "    " << node->getData() << '\n';
        string s = "    ";
        s[0] = char(179);
        print_tree(prefix + (isLeft ? s : "    "), node->getLeft(), true, false, false);
        print_tree(prefix + (isLeft ? s : "    "), node->getRight(), false, false, true);
    }
}