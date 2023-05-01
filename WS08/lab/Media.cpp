/*
*****************************************************************************
				  Workshop 8 (Part 1)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 22 March 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Media.h"


using namespace std;

namespace sdds {

	ostream& operator<<(ostream& ostr, const Media& media) {
		return media.play(ostr);

	}

	istream& operator>>(istream& istr, Media& media) {
		media.load(istr);
		return istr;
	}



}