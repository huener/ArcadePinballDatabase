//
// Project 7        CSCE 2014       -	Dr. Streeter
// Gael Brice       5/5/22          -	Due
//
// Machine.h
// Defines the methods included in the Machine class.
// 
// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +
#pragma once

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Machine
{
	public:
		Machine();																				// Constructor I
		Machine(const string name, const string make, const int year, const string type);		// Constructor II			
		Machine(const Machine& machine);														// Copy Constructor
		~Machine();																				// Destructor

		// Setter Methods
		void	setName(const string name);
		void	setMake(const string make);
		void	setYear(const int year);
		void	setType(const string type);


		// Getter Methods
		string	getName();
		string	getMake();
		int		getYear();
		string	getType();


		// Supplemental Methods
		void	print();									// prints the object's information

	private:
		string	Name;										// Name / Title of machine
		string	Make;										// Manufacturer
		string	Type;										// Pinball / Arcade
		int		Year;										// Production Year
}

;