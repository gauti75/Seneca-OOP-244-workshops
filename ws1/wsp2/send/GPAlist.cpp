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



#include "GPAlist.h"
#include <cmath>
#include<stdlib.h>
#include <string>
#include<iomanip>
using namespace std;
namespace sdds
{
	
	GPA finalgpa[100]; // declaring an array of structures to store the data which we get from the sortarray function.
	int length = 0;
	bool gpaQuery(const char* filename)
	{
		
		
		if (loadData(filename, finalgpa , length)) // function to validate if data is loaded properly

		{
			cout << "Enter GPA query..." << endl;
		
			char operand[10]{'\0'};
			while (operand[0] != '!') // using a while loop to iterate through the user input to display the filtered result.
			{
				cout << "? ";
				cin >> operand;
				if (!checkAuthentication(operand[0])) // this describes that if the value is not form the given data then it will throw out an error
				{
					cout << "Syntax error: ? [Op][value]<ENTER>\nOp: [>,<,~,!]\nvalue: GPA value\n\n";
					fflush(stdin); // flushing the standard input to not get error.
				}
				else
				{
					if (operand[0] == '!') // if statement to end the query which will promot the user to if they want to end the query or not
					{
						char a;
						cout << "Exit the program? (Y)es/(N)o: ";
						cin >> a;
						if (a == 'y' || a == 'Y')
						{
							break;

						}
				
					}
					string finalstring = "";
					for (int i = 1; i < 9; i++) 
					{
						finalstring = finalstring + operand[i];
					}
					double checked = stof(finalstring);
					checked = round(checked * 100) / 100;;
					displaydata(operand[0],checked); // this is the function which would print the whole filtered data and it takes two parameters. One is the user operand and the other is the value.
					
				}
			}
			
			return true;
		}
		return false;
	}
	bool checkAuthentication(char operand)
	{
 
		char authenticator[5] = { '>' ,'<','~','!' };

		for (int i =0; i< 5;i++)
		{
			if (operand == authenticator[i])
			{
				return true;
			}
		}
		return false;
	}
	void displaydata(const char selected, double check)
	{
		int count = 1;
		sortArray(finalgpa, length); // sorting the array of structures finalgpa
		
		switch (selected) // using switch statment to iterate through number of cases.
		{
		case '>':

			for (int x = 0; x < length; x++)
			{
				if (check < (finalgpa[x].gpa)  && finalgpa[x].gpa > 0)
				{
					cout << "[" << count << "] " << finalgpa[x].stno << ": " << setprecision(1) << fixed << finalgpa[x].gpa << " " << "\(" << finalgpa[x].name << ")" << endl;
					count++;
				}
				
			}
			break;
		case '<':
			for (int x = 0; x < length; x++)
			{
				if (check >(finalgpa[x].gpa) && finalgpa[x].gpa > 0)
				{
					cout << "[" << count << "] " << finalgpa[x].stno << ": " << setprecision(1)<<fixed << finalgpa[x].gpa << " " << "\(" << finalgpa[x].name << ")" << endl;
					count++;
				}

			}
			break;
		case '~':
			for (int x = 0; x< length; x++)
			{
			

				if ((finalgpa[x].gpa) == check && finalgpa[x].gpa > 0)
				{
					cout << "[" << count << "] " << finalgpa[x].stno << ": " << setprecision(1) << fixed << finalgpa[x].gpa << " " << "\(" << finalgpa[x].name << ")" << endl;

					count++;
				}

			}
			break;
		default:
			break;
		}
	}

	
	
} 
