//
// Project 7        CSCE 2014       -	Dr. Streeter
// Gael Brice       5/5/22          -	Due
//
// Machine.h
// Defines the methods included in the Binary Search Tree.
// 
// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +

#include "BinarySearchTree.h"

using namespace std;

BinarySearch::BinarySearch() 
{
    Root = NULL;
}

BinarySearch::BinarySearch(const BinarySearch& orig) 
{
    Root = orig.Root;
}

BinarySearch::~BinarySearch() 
{
}

// Public
    bool BinarySearch::Search(string term)
    {

        if (SearchHelp(term, Root).getName() == "-1")
            return false;
        else
        {
            cout << "Result located:" << endl;
            SearchHelp(term, Root).print();
            return true;
        }
    }

    bool BinarySearch::Insert(Machine newMachine)
    {
        return (InsertHelp(newMachine, Root));
    }

    bool BinarySearch::Delete(string term)
    {
    // simple search for term
        Machine* foundEntry = &SearchHelp(term, Root);

        // Data value not found
        if (foundEntry->getMake() == "-1")
            return false;

        // Data value found 
        if (foundEntry->getName() == term)
        {
            cout << "Located entry for deletion:" << endl;
            foundEntry->print();
            return (DeleteHelp(foundEntry, Root));
        }
        else
            return false;
    }

    void BinarySearch::Print()
    {
        PrintHelp(Root);
        std::cout << endl;
    }


// Private helper methods to make calls easier to make by user: no node access.
    Machine& BinarySearch::SearchHelp(const string &Value, Node* Tree)
    {
        
        // Data value not found 
        if (Tree == NULL)
        {
            Machine* Null = new Machine();
            return (*Null);
        }

        

        // Data value found 
        else if (Tree->Game.getName() == Value)
        {
            return (Tree->Game);
        }

        else
        {
            // Determine how many of this Node's characters match the search term value
            string nodeName = Tree->Game.getName();
            int count = 0;
            int valueLength = Value.length();

            while ((count + 1 <= valueLength) && (nodeName[count] == Value[count]))
            {
                count++; 
            }

            // count == number of characters that match and count-1 should be the final matching character index
            // are either children a better match than this node?
            char nodeChar = nodeName[count];
            char gameChar = Value[count];

            // Recursively search further for insertion position
            if (gameChar < nodeChar)
                return (SearchHelp(Value, Tree->leftChild));
            else if (gameChar > nodeChar)
                return (SearchHelp(Value, Tree->rightChild));
        }
        return (Tree->Game);
    }

    bool BinarySearch::InsertHelp(Machine newMachine, Node*& Tree)
    {
        // Insert data into the tree
        if (Tree == NULL)
        {
            Tree = new Node;
            Tree->Game = newMachine;
            Tree->leftChild = NULL;
            Tree->rightChild = NULL;
            return true;
        }

        // Data value already inserted
        else if (Tree->Game.getName() == newMachine.getName())
            return false;

        // Determine which side of the tree to enter based on unmatching char ASCII
            string nodeName = Tree->Game.getName();
            int count = 0;
            int newNameLength = newMachine.getName().length();

            while ((count <= newNameLength - 1) && (nodeName[count] == newMachine.getName()[count]))
            {
                count++; 
            }
            // count == number of characters that match and count-1 should be the final matching character index

            char nodeChar = nodeName[count];
            char gameChar = newMachine.getName()[count];

            // Recursively search further for insertion position
            if (gameChar < nodeChar)
                return (InsertHelp(newMachine, Tree->leftChild));
            else if (gameChar > nodeChar)
                return (InsertHelp(newMachine, Tree->rightChild));
            else 
                return false;

        
    }

    bool BinarySearch::DeleteNode(Node* &Tree)
    {
        // zero children:
        if ((Tree->leftChild == NULL) && (Tree->rightChild == NULL))
        {
            delete Tree;
            Tree = NULL;
            return true;
        }

        // one child: right
        else if ((Tree->leftChild == NULL) && (Tree->rightChild != NULL))
        {
            Node* temp = Tree;
            Tree = Tree->rightChild;
            delete temp;
            return true;
        }

        // one child: left
        else if ((Tree->leftChild != NULL) && (Tree->rightChild == NULL))
        {
            Node* temp = Tree;
            Tree = Tree->leftChild;
            delete temp;
            return true;
        }

        // two children
        else if ((Tree->leftChild != NULL) && (Tree->rightChild != NULL))
        {
            Node* parent = Tree;
            Node* child = parent->rightChild;
            while (child->leftChild != NULL)
            {
                parent = child;
                child = child->leftChild;
            }

            // fix pointers
            if (parent != Tree)
                parent->leftChild = child->rightChild;
            else
                Tree->rightChild = child->rightChild;

            // delete node
            Tree->Game = child->Game;
            delete child;
            return true;
        }
        else
            return false;
    }

    bool BinarySearch::DeleteHelp(Machine* &deleteGame, Node*& Tree)
    {
        // Handle Terminating Conditions:
        if (Tree == NULL)
            return false;
        else if (Tree->Game.getName() == deleteGame->getName())
            return (DeleteNode(Tree));
        else
        {
            // Determine how many of this Node's characters match the search term value
            string nodeName = Tree->Game.getName();
            int count = 0;
            string Value = deleteGame->getName();
            int valueLength = Value.length();

            while ((count + 1 <= valueLength) && (nodeName[count] == Value[count]))
            {
                count++;
            }
            // count == number of characters that match and count-1 should be the final matching character index
            // which child node will be traversed?
            char nodeChar = nodeName[count];
            char gameChar = Value[count];

            if (gameChar < nodeChar)
                return (DeleteHelp(deleteGame, Tree->leftChild));
            else if (gameChar > nodeChar)
                return (DeleteHelp(deleteGame, Tree->rightChild));
            else
                return false;
        }
    }

    void BinarySearch::PrintHelp(Node* Tree)
    {
        // Check terminating condition
        if (Tree != NULL)
        {
            // Print left subtree
            if (Tree->leftChild != NULL)
                PrintHelp(Tree->leftChild);

            // Print node value
            Tree->Game.print();
            cout << endl;

            // Print right subtree
            if (Tree->rightChild != NULL)
                PrintHelp(Tree->rightChild);
        }
    }
