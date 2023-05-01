/*
*****************************************************************************
				  Workshop 3 (Part 1)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 01 Feburary 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/



/***********************************************************************
// OOP244 Workshop 3 # p1: tester program
//
// File	main.cpp
// Version 1.0
// Date		October 7, 2022
// Author	Mohammad Shamas
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Department.h"
using namespace std;
using namespace sdds;

int main() {

	Project testProject = { "Base",551.55 };

	Project myprojects[5] = { {"Synergy", 5041.55},
							  {"Mecha", 2925.99},
							  {"Chroma", 3995.45},
							  {"Force", 6988.45},
							  {"Oculus", 7441.22}
	};

	Department SDDS{};

	//Test1
	cout << "**********Create Department TEST START**********" << endl;
	SDDS.createDepartment("School of Software development", testProject, 1);
	display(SDDS);
	cout << "**********Create Department TEST END**********" << endl;

	//Test2
	cout << endl << "**********Update Name TEST Start**********" << endl;
	SDDS.updateName("School of Software development and design");
	display(SDDS);
	cout << "**********Update Name TEST END**********" << endl;

	//Test3
	cout << endl << "**********Update Budget TEST Start**********" << endl;
	SDDS.updateBudget(5555.99);
	display(SDDS);
	cout << "**********Update Budget TEST END**********" << endl;

	//Test4
	cout << endl << "**********Expenses and Remaining Budget TEST Start**********" << endl;
	cout << "Our current total Expenses are: " << SDDS.totalexpenses() << endl;
	cout << "Our remaining budget is: " << SDDS.remainingBudget() << endl;
	cout << "**********Expenses and Remaining Budget TEST END**********" << endl;

	//Test5
	cout << endl << "**********Add Project TEST START**********" << endl;
	for (int i = 0; i < 5 && SDDS.addProject(myprojects[i]); i++);
	display(SDDS);
	cout << "**********Add Project TEST END**********" << endl;
	
	SDDS.clearDepartment();
	return 0;
}

/*

**********Create Department TEST START**********

Department School of Software development details:

Budget: 15347 and the number of projects in progress is: 1

Below are the details of the projects we are currently working on:

Project Base will cost a total of 551.55 C$.

**********Create Department TEST END**********



**********Update Name TEST Start**********

Department School of Software development and design details:

Budget: 15347 and the number of projects in progress is: 1

Below are the details of the projects we are currently working on:

Project Base will cost a total of 551.55 C$.

**********Update Name TEST END**********



**********Update Budget TEST Start**********

Department School of Software development and design details:

Budget: 20903 and the number of projects in progress is: 1

Below are the details of the projects we are currently working on:

Project Base will cost a total of 551.55 C$.

**********Update Budget TEST END**********



**********Expenses and Remaining Budget TEST Start**********

Our current total Expenses are: 551.55

Our remaining budget is: 20351.4

**********Expenses and Remaining Budget TEST END**********



**********Add Project TEST START**********

Department School of Software development and design details:

Budget: 20903 and the number of projects in progress is: 5

Below are the details of the projects we are currently working on:

Project Base will cost a total of 551.55 C$.

Project Synergy will cost a total of 5041.55 C$.

Project Mecha will cost a total of 2925.99 C$.

Project Chroma will cost a total of 3995.45 C$.

Project Force will cost a total of 6988.45 C$.

**********Add Project TEST END**********
*/