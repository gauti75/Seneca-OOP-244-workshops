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


#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include <fstream>
#include "GPA.h"
namespace sdds
{
bool loadData(const char* filename, GPA Data[], int& no); // function to load the data
}
#endif