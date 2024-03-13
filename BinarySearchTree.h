//
// Project 7        CSCE 2014       -	Dr. Streeter
// Gael Brice       5/5/22          -	Due
//
// BinarySearchTree.h
// Defines the methods included in the Binary Search Tree class.
// 
// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +

#include "Machine.h"

// Data node definition
class Node
{
    public:
        Machine Game;
        Node* leftChild;
        Node* rightChild;
};

// BinarySearch class definition
class BinarySearch {
public:
    BinarySearch();
    BinarySearch(const BinarySearch& orig);
    ~BinarySearch();

    bool Search(string term);
    bool Insert(Machine newMachine);
    bool Delete(string term);
    void Print();

private:
    Machine& SearchHelp(const string &Value, Node* Tree);
    bool InsertHelp(Machine newMachine, Node* &Tree);
    bool DeleteNode(Node* &Tree);
    bool DeleteHelp(Machine* &deleteGame, Node* &Tree);
    void PrintHelp(Node* Tree);

    Node* Root;
};

