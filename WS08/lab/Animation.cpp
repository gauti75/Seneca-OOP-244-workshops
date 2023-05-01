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
#include "Animation.h"


using namespace std;

namespace sdds {
	Animation::Animation():Video() {
		m_dimension = 0;
	}

	Animation::Animation(int length, int dimension) :Video(length) {
		if (dimension == 2 || dimension  == 3) {
			m_dimension = dimension;
		}
		else {
			m_dimension = 0;
		}
	}
	void Animation::load(istream& istr) {
		Video::load(istr);
		
		int user_dimension;
		istr >> user_dimension;
		istr.ignore(1000,'\n');
		if (user_dimension == 2 || user_dimension == 3) {
			m_dimension = user_dimension;
		}
		else {
			m_dimension = 0;
		}
	}
	ostream& Animation::play(ostream& ostr)const {
		if (m_dimension!=0&&Video::get()>0) {
			ostr << "Animation is in " << m_dimension << "-D" << endl;
			ostr << "Video Length = " << Video::get();
			

		}
		return ostr;

	}


}