/*
*****************************************************************************
				  Workshop 4 (Part 2)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 15 Feburary 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/




#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<string.h>
#include<iomanip>
#include "NameTag.h"

using namespace std;


namespace sdds {
	


	void NameTag::setEmpty() {
		
		name = nullptr;
		number = -1;
		validity = false;
	}

	void NameTag::setName(const char* fullname) {
		if (fullname != nullptr) {
			name = new char[strlen(fullname) + 1];
			strcpy(name, fullname);
			validity = true;

		}
		else {
			name = nullptr;
			validity = false;
			
		}
		
		
	}

	void NameTag::setExtenstion(int extenstion) {
		if (extenstion >= 10000 && extenstion <= 99999) {
			number = extenstion;
		}
		else {
			number = -1;
			validity = false;
		}
		
	}


	
	

	NameTag::NameTag() {
		setEmpty();

	}

	NameTag::NameTag(const char* fullname) {
		//name = new char[strlen(fullname)+1];
		//strcpy(name,fullname);
		setName(fullname);
		number = 0;


	}

	NameTag::NameTag(const char* fullname, int extenstion) {
		//name = new char[strlen(fullname) + 1];
		//strcpy(name, fullname);
		setName(fullname);
		setExtenstion(extenstion);



	}


	/*
	NameTag& sdds::NameTag::read()
	{
		cout << "Please enter the name: ";
		char tmp[1024];
		cin.getline(tmp, 1024, '\n');

		if (name != nullptr) {
			delete[] name;
		}
		name = new char[strlen(tmp) + 1];
		strcpy(name, tmp);

		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
	x:
		cin.getline(tmp, 1024, '\n');
		if (strcmp(tmp, "Y") == 0 || strcmp(tmp, "y") == 0)
		{
			cout << "Please enter a 5 digit phone extension: ";
		y:
			cin.getline(tmp, 1024, '\n');

			number = atoi(tmp);
			if (number == 0)
			{
				cout << "Bad integer value, try again: ";
				goto y;
			}
			if (number < 10000 || number>99999) {
				cout << "Invalid value [10000<=value<=99999]: ";
				goto y;
			}
			validity = true;
		}
		else if (strcmp(tmp, "N") == 0 || strcmp(tmp, "n") == 0)
		{
			number = 0;
			validity = true;
			return *this;
		}
		else {
			cout << "Only (Y) or (N) are acceptable, try agin: ";
			goto x;
		}

		return *this;
	}
	*/
	
	NameTag& NameTag::read() {
		
		cout << "Please enter the name: ";

		char temp[2000];
		
		cin.getline(temp,2000,'\n');
	

		if (name != nullptr) {
			delete[] name;
		}
		name = new char[strlen(temp) + 1];
		strcpy(name, temp);

		

		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
	first:

		cin.getline(temp, 2000, '\n');
		
		if (strcmp(temp, "Y") == 0 || strcmp(temp, "y") == 0){

			cout << "Please enter a 5 digit phone extension: ";
		second:

			cin.getline(temp, 1024, '\n');

			number = atoi(temp);
			// cout << "Please enter a 5 digit phone extension: ";
			int flag = 0;
			if (number == 0 && flag == 0) {
				cout << "Bad integer value, try again: ";
				goto second;
			}
			else if (number == 1) {
				flag = 1;
			}
			flag = 0;
			if ((number < 10000 || number>99999) && flag == 0) {
				cout << "Invalid value [10000<=value<=99999]: ";
				goto second;
			}
			else if (number >= 10000 && number <= 99999) {
				flag = 1;
			}
			validity = true;

		}

		else if (strcmp(temp, "N") == 0 || strcmp(temp, "n") == 0) {
			number = 0;
			validity = true;

			return *this;
		}
		else {
			cout << "Only (Y) or (N) are acceptable, try agin: ";
			goto first;
		}

	
		return *this;

	}
	
	
	

	
	void NameTag::print()
	{
		if (!validity) {
			cout << "EMPTY NAMETAG!\n";
			return;
		}
		if (strlen(name) < 20) {
			cout.width(20);
			cout.setf(ios::left);
			cout << "+----------------------+";
			cout << "\n|                      |";
			char tmp[21];
			strcpy(tmp, name);
			
				
			

			cout << "\n| " << setw(20) << tmp << " |";
			cout << "\n|                      |";
			if (number != 0)
				cout << "\n| " << "Extension: " << setw(9) << number;
			else
				cout << "\n| " << setw(20) << "Extension: N/A";
			cout << std::setw(0) << " |";
			cout << "\n|                      |";
			cout << "\n+----------------------+\n";
		}
		else {
			cout.width(40);
			cout.setf(ios::left);
			cout << "+------------------------------------------+";
			cout << "\n|                                          |";
			char tmp[41];
			strncpy(tmp, name, 40);
			tmp[40] = '\0';
			

			cout << "\n| " << setw(40) << tmp << " |";
			cout << "\n|                                          |";
			if (number != 0)
				cout << "\n| " << "Extension: " << setw(29) << number;
			else
				cout << "\n| " << setw(40) << "Extension: N/A";
			cout << setw(0) << " |";
			cout << "\n|                                          |";
			cout << "\n+------------------------------------------+\n";
		}
	}


	NameTag::~NameTag() {

		delete[] name;
		name=nullptr;

	}




}