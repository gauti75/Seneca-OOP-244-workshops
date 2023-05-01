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


#include "UI.h"
namespace sdds
{

	/*
	Here I created a sort function to sort the structure to get the filtered data with 
	the help of user_input
	*/
	void sortArray(struct GPA* arr, int j) {
		
		for (int i = 0; i < j - 1; i++) {
			for (int m = 0; m < j - i - 1; m++) {
				if (arr[m].name > arr[m + 1].name) {
					GPA temp = arr[m];
					arr[m] = arr[m + 1];
					arr[m+ 1] = temp;
				}
			}
		}
		for (int i = 0; i < j - 1; i++) {
			for (int m = 0; m < j - i - 1; m++) {
				if (arr[m].gpa > arr[m + 1].gpa) {
					GPA temp = arr[m];
					arr[m] = arr[m + 1];
					arr[m + 1] = temp;
				}
			}
		}
	}
	
}