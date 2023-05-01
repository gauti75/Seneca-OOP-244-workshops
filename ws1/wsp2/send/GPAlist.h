/*
*****************************************************************************
				  Workshop 1 (Part 2)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 20 January 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/

#ifndef SDDS_GPALIST_H
#define SDDS_GPALIST_H
#include <iostream>
#include "UI.h"
#include"File.h"
#include"GPA.h"
namespace sdds
{

	bool gpaQuery(const char* filename);
	bool checkAuthentication( char operand); /* Function to check if the user input is valid from the given data. If not then give error*/
	void displaydata(const char operand, double value);
	

}
#endif