//
// Project 7        CSCE 2014       -	Dr. Streeter
// Gael Brice       5/5/22          -	Due
//
// main.cpp
// Pulls it all together
// 
// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +

#include "BinarySearchTree.h"

using namespace std;

void readFile(string filename)
{
    string name, make, type, yearS = "";
    int year = -1;

    ifstream fin;
    fin.open(filename);
    if (fin.fail())
    {
        cout << "readin failed!" << endl;
    }

    while (!fin.eof())
    {
        getline(fin, name, ',');
        getline(fin, make, ',');
        getline(fin, yearS, ',');
        getline(fin, type, '\n');

        year = stoi(yearS);

        Machine entry;
        entry.setName(name);
        entry.setMake(make);
        entry.setYear(year);
        entry.setType(type);

        entry.print();
    }
};

void readFileBST(string filename, BinarySearch &tree)
{
    string name, make, type, yearS = "";
    int year = -1;

    ifstream fin;
    fin.open(filename);
    if (fin.fail())
    {
        cout << "readin failed!" << endl;
    }

    while (!fin.eof())
    {
        getline(fin, name, ',');
        getline(fin, make, ',');
        getline(fin, yearS, ',');
        getline(fin, type, '\n');

        year = stoi(yearS);

        Machine entry;
        entry.setName(name);
        entry.setMake(make);
        entry.setYear(year);
        entry.setType(type);

        tree.Insert(entry);
    }
};

int main()
{
    BinarySearch Tree;
    bool end = 0;
    bool initialized = 0;
    while (end == 0)
    {
        cout << "---\n\n" << "AskArcadia - Search the Classics of Today and Tomorrow" << endl << endl;
        cout << "Please select from the following options:" << endl;
        cout << "1. Initialize Data" << endl;
        cout << "2. Search by Title" << endl;
        cout << "3. Insert New Game" << endl;
        cout << "4. Delete a Game" << endl;
        cout << "5. Print Database" << endl << endl;
        cout << "9. Exit" << endl << endl << "---" << endl;


        string sinput = "";
        string text;
        cin >> sinput;
        while (("5" != sinput) && ("4" != sinput) && ("3" != sinput) && ("2" != sinput) && (sinput != "1") && (sinput != "9"))
        {
            cout << "Invalid entry! Please enter the option's number: ";
            getline(cin, sinput);
        }

        // handle user input
        if ((sinput == "9"))
        {
            cout << "Goodbye ~!";
            end = 1;
        }

        else if ((sinput == "5") && (initialized == 1))
        {
            cout << "Printing Database..." << endl << endl;
            Tree.Print();
        }

        else if ((sinput == "4") && (initialized == 1))
        {
            cout << "Delete a Game:" << endl << "Please enter the title of the game you would like to remove.\nBe deliberate with your entry, as it must match exactly." << endl << endl;
            cin.ignore();
            getline(cin, text);

            if (!Tree.Delete(text))
                cout << "No matching entry found. Returning to main menu..." << endl << endl;
            else
                cout << "Delete Successful! Returning to main menu..." << endl << endl;
        }

        else if ((sinput == "3") && (initialized == 1))
        {
            string Name = "";
            string Make = "";
            string Type = "";
            int Year = -1;
            cin.ignore();
            cout << "Insert a New Game:" << endl << "Create a new entry that will be placed in the database. \nPlease enter the following information carefully, as it cannot be altered without deleting the entry." << endl << endl;
            cout << "Name: ";
            getline(cin, Name);
            cout << "Manufacturer: ";
            getline(cin, Make);
            cout << "Type of Game (Arcade/Pinball): ";
            getline(cin, Type);
            cout << "Year of Release: ";
            cin >> Year;
            cin.ignore();

            Machine entry = Machine(Name, Make, Year, Type);
            cout << "\nNew Entry:" << endl;
            entry.print();
            if (!Tree.Insert(entry))
                cout << "Insertion failed! Entry may already exist. Returning to main menu..." << endl << endl;
            else
                cout << "Insert success! Returning to main menu..." << endl << endl;
        }

        else if ((sinput == "2") && (initialized == 1))
        {
            cin.ignore();
            cout << "Search the Database:" << endl << "Please enter the title of the game you would like to find.\nBe deliberate with your entry, as it must match exactly in order to return the appropriate result." << endl << endl;
            getline(cin, text);
            if (!Tree.Search(text))
                cout << "No results found. Returning to main menu..." << endl << endl;
            else
                cout << "Search complete! Returning to main menu..." << endl << endl;
        }

        else if (sinput == "1")
        {
            text = "";
            if (initialized == 1)
            {
                cout << "The database has already been initialized. Would you like to rebuild it? (Yes/No)";
                cin >> text;
            }
            if ((text == "Yes") || (text == "yes") || (text == "y") || (text == "Y") || (initialized == 0))
            {
                cout << "Initialize Data:" << endl << "Please enter the full filename of the data file, including file extention: ";
                cin >> text;

                readFileBST(text, Tree);
                cout << "Database Initialized! Returning to main menu..." << endl << endl;
                initialized = 1;
            }
        }
        else
        {
            cout << "Your database does not exist! Please initialize data from file before attempting to read from it." << endl << endl;
        }
    }
}