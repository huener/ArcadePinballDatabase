//
// Project 7        CSCE 2014       -	Dr. Streeter
// Gael Brice       5/5/22          -	Due
//
// Machine.cpp
// Elaborates on the methods in the Machine class.
// Each Machine object == all info on one arcade game. 
// 
// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +

#include "Machine.h"

Machine::Machine()
{
    Name = "-1";
    Make = "-1";
    Type = "-1";
    Year = -1;
}

Machine::Machine(const string name, const string make, const int year, const string type)
{
    Name = name;
    Make = make;
    Type = type;
    Year = year;
}

Machine::Machine(const Machine& machine)
{
    Name = machine.Name;
    Make = machine.Make;
    Type = machine.Type;
    Year = machine.Year;
}

Machine::~Machine()
{
}


// Setter Methods

void	Machine::setName(const string name)
{
    Name = name;
}

void	Machine::setMake(const string make)
{
    Make = make;
}

void	Machine::setYear(const int year)
{
    Year = year;
}

void	Machine::setType(const string type)
{
    Type = type;
}


// Getter Methods
string	Machine::getName()
{
    return Name;
}

string	Machine::getMake()
{
    return Make;
}

int	Machine::getYear()
{
    return Year;
}

string	Machine::getType()
{
    return Type;
}

void	Machine::print()
{
    cout << Name << " (" << Year << ")" << endl;
    cout << Type << " by " << Make << endl << endl;
}