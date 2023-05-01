/*
*****************************************************************************
				  Workshop 2 (Part 1)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 25 January 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/


#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

namespace sdds {
	int openFile_r(const char filename[]); // Provided
	void closefile(); // Provided
	int noOfTraces(); // Provided

	// ADD: Declare read prototypes (4 prototypes)

	int read(char package_name[]);

	int read(int& int_value);

	int read(double& timeinhours);

	int read(char& dayofweek);





	void strCpy(char* des, const char* src); // Provided
	int strLen(const char* s); // Provided
}
#endif 
