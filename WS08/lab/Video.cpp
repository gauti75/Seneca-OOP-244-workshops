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
#include "Video.h"


using namespace std;

namespace sdds {

	int Video::get()const {
		return m_length;
	}
	Video::Video() {
		m_length = 0;
	}

	Video::Video(int temp_length) {
		if (temp_length < 0) {
			m_length = 0;
		}
		else {
			m_length = temp_length;
		}
	}
	void Video::load(istream& istr) {
		char comma = ',';
		int user_length;
		istr >> user_length >> comma;
		m_length = user_length;

	}


}