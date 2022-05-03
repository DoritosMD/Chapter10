// Name: Matthew Batres 
// Group 2: Matthew Batres, Julian Espinoza, Eduardo Ortiz, Wesley Goo, Arturo Mejia, and Hamza Patel
// Date: 05/03/2022
// Description: Chapter 10 Assignment - Trees 

#include <iostream>
#include <string>
#include "firstChoice.h"
#include "secondChoice.h"
#include "thirdChoice.h"
#include "input.h"
#include "bTree.h"
#include "binary_tree_node.h"

using namespace std;

//Prototypes
void displayMainMenu(void);
void mainMenu(void);
void programOne(void);
void programTwo(void);
void programThree(void);
void displayOptionTwoMenu(void);
void displayOptionThreeMenu(void);

int main(void)
{
    mainMenu();
    return 0;
}
//Precondition: N/A
//Postcondition: Switches user to menus based on input.
void mainMenu(void)
{
    do
    {
        clearScreen();
        displayMainMenu();

        int userInput = inputInteger("\t\tOption: ", 0, 3);
        switch (userInput)
        {
        case 0: return;
        case 1: programOne(); break;
        case 2: programTwo(); break;
        case 3: programThree(); break;
        default: cout << "\t\tERROR: Invalid input! Must be from 0..3." << endl;
        }

    } while (true);
}
//Precondition: N/A
//Postcondition: Displays contents for option 1.
void programOne(void)
{
    clearScreen();
    cout << "\t1> Tree of strings" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    binary_tree_node<string>* root = new binary_tree_node<string>;
    createdRoot(root);
    createdBranches(root);
    createdLeaves(root);
    deleteTree(root);
    pause("\n\t\t\Press Enter to continue . . .");
}
//Precondition: N/A
//Postcondition: Displays contents for second choice.
void programTwo(void)
{
    bTree<int> intTree = bTree<int>();
    do
    {
        clearScreen();
        cout << "\t2> bTree container" << endl;
        cout << "\t" + string(100, char(205)) << endl;
        displayOptionTwoMenu();

        char userInput = inputChar("\t\tOption: ");
        switch (userInput)
        {
        case '0': return;
        case 'a': case 'A': intTree.push(inputInteger("\n\t\tEnter an integer: ")); break;
        case 'b': case 'B': cout << "\n\t\tCount of Nodes = " << intTree.countNodes(); pause("\n\n\t\t\Press any key to continue . . .");  break;
        case 'c': case 'C':
            try
            {
                int input = inputInteger("\n\t\tEnter an integer key to search: ");
                if (intTree.searchNode(input)) cout << "\n\t\t" << input << " is found." << endl;
                else cout << "\n\t\t" << input << " cannot be found." << endl;
            }
            catch (const invalid_argument& e) 
            {
                cout << "\n\t\t" << e.what() << endl; 
            }
            pause("\n\t\t\Press any key to continue . . .");
            break;
        case 'd': case 'D':
            try
            { 
                cout << "\n\t\tPre-order traversal of bTree with " << intTree.countNodes() << " node(s):" << endl; intTree.printPreOrder();
            }
            catch (const invalid_argument& e)
            { 
                cout << "\n\t\t" << e.what() << endl;
            }
            pause("\n\t\t\Press any key to continue . . .");
            break;
        case 'e': case 'E':
            try
            { 
                cout << "\n\t\tIn-order traversal of bTree with " << intTree.countNodes() << " node(s):" << endl; intTree.printInOrder();
            }
            catch (const invalid_argument& e)
            {
                cout << "\n\t\t" << e.what() << endl;
            }
            pause("\n\t\t\Press any key to continue . . .");
            break;
        case 'f': case 'F':
            try
            { 
                cout << "\n\t\tPost-order traversal of bTree with " << intTree.countNodes() << " node(s):" << endl; intTree.printPostOrder();
            }
            catch (const invalid_argument& e)
            {
                cout << "\n\t\t" << e.what() << endl;
            }
            pause("\n\t\t\Press any key to continue . . .");
            break;
        case 'g': case 'G':
            if (intTree.countNodes() != 0)
            {
                int nodeCount = intTree.countNodes();
                intTree.deleteTree();
                if (nodeCount == 1)
                    cout << "\n\t\t" << nodeCount << " node/leaf has been destroyed." << endl;
                else
                    cout << "\n\t\tAll " << nodeCount << " nodes/leaves have been destroyed." << endl;
            }
            else
            { 
                cout << "\n\t\t\ERROR: bTree is empty." << endl;
            }
            pause("\n\t\t\Press any key to continue . . .");
            break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D','E','F', or 'G'" << endl; pause("");
        }

    } while (true);

}
//Precondition: N/A
//Postcondition: Dispplays contents for third choice.
void programThree(void)
{
    binary_tree_node<string>* taxonomy_root_ptr;
    string fileName = "animals.txt";
    ifstream infile;
    ofstream outfile;

    infile.open(fileName);
    if (infile.is_open())
    {
        readTreeFromFile(taxonomy_root_ptr, infile);
    }
    else
    {
        taxonomy_root_ptr = default_tree();
    }
    infile.close();
    do
    {
        clearScreen();
        cout << "\t3> Animal Guessing Game" << endl;
        cout << "\t" + string(100, char(205)) << endl;
        displayOptionThreeMenu();

        char userInput = inputChar("\t\tOption: ");
        switch (userInput)
        {
        case '0': return;
        case 'a': case 'A':
            play(taxonomy_root_ptr);
            system("pause");
            break;
        case 'b': case 'B':
            outfile.open(fileName);
            if (outfile.is_open())
            {
                writeTreeToFile(taxonomy_root_ptr, outfile);
            }
            outfile.close();

            cout << "\n\tCurrent taxonomy tree saved to file " << fileName << "\n";
            system("pause");
            break;
        default:
            cout << "\t\tERROR: Invalid input. Must be '0','A','B'" << endl;
            pause("");
        }
    } while (true);
    delete_tree<string>(taxonomy_root_ptr);
}
//Precondition: N/A
//Postcondition: Displays main menu.
void displayMainMenu(void)
{
    cout << "\n\tCMPR131 Chapter 10: Trees by Matthew, Julian, Eduardo, Wesley, Arturo, and Hamza" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\t1> Tree of strings" << endl;
    cout << "\t\t2> Tree container of integers" << endl;
    cout << "\t\t3> Animal Guessing Game" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}
//Precondition: N/A
//Postcondition: Displays second choice menu not done in header file.
void displayOptionTwoMenu(void)
{
    cout << "\t\tA> Insert a node/leaf" << endl;
    cout << "\t\tB> Count of Nodes/leaves" << endl;
    cout << "\t\tC> Search a node/leaf" << endl;
    cout << "\t\tD> Pre-order traversal" << endl;
    cout << "\t\tE> In-order traversal" << endl;
    cout << "\t\tF> Post-order traveral" << endl;
    cout << "\t\tG> Delete the entire tree" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}
//Precondition: N/A
//Postcondition: Displays third choice menu.
void displayOptionThreeMenu(void)
{
    cout << "\n\tA game tree for a simple game of ""animal"" twenty questions would look like:" << endl;
    cout << "\t                                 [ Is it a mammal? ]" << endl;
    cout << "\t                                     /         \\" << endl;
    cout << "\t                                    /           \\" << endl;
    cout << "\t                [ Does it have stripes? ]     [ Is it a bird? ]" << endl;
    cout << "\t                      /       \\                  /       \\" << endl;
    cout << "\t                     /         \\                /         \\" << endl;
    cout << "\t                ( Zebra )    ( Lion )   [ Does it fly? ]  ( Gila monster )" << endl;
    cout << "\t                                           /       \\" << endl;
    cout << "\t                                          /         \\" << endl;
    cout << "\t                                    ( Eagle )     ( Penguin )" << endl;
    cout << "\tA learning version of twenty questions: one that not only plays the game, but learns new" << endl;
    cout << "\tobjects when it loses." << endl;
    cout << "\n\tWelcome to Animal Guessing Game" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\tA> Play the game" << endl;
    cout << "\t\tB> Save the game file" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}