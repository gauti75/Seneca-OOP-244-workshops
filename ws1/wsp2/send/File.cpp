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


#include "File.h"
#include <iostream>
using namespace std;

namespace sdds
{
	bool loadData(const char* filename , GPA Data[], int& no)
	{
		std::ifstream in(filename);
		if (in.is_open() == false)
		{
			return false;
		}

		while (!in.eof()) { // using while loop the read data from the file until the end of the file which can be later loaded into the array of structurs.
			in.get(Data[no].name, 115, ',');
			in.ignore();
			in >> Data[no].stno;
			
			in.ignore();
			in >> Data[no].gpa;
			in.ignore();
			no++;

		}
		return true;
	}
}