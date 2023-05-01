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
#include<string.h>
#include "VRVideo.h"


using namespace std;

namespace sdds {
	VRVideo::VRVideo() :Video() {
		m_equipment = nullptr;
	}

	VRVideo::VRVideo(int length,const char* equipment) :Video(length) {
		if (length < 0||equipment==nullptr) {
			m_equipment = nullptr;
		}
		else {
			m_equipment = new char[strlen(equipment)+1];
			strcpy(m_equipment, equipment);
		}
	}

	VRVideo::~VRVideo() {
		if (m_equipment != nullptr) {
			delete[] m_equipment;
			m_equipment = nullptr;
		}
	}

	void VRVideo::load(istream& istr) {
		Video::load(istr);
		char user_input[1000];
		istr.getline(user_input, 1000, '\n');
		//istr.ignore();
		if (m_equipment != nullptr) {
			delete[] m_equipment;

			//m_equipment = nullptr;
			if (Video::get() < 0 || user_input == nullptr) {
				m_equipment = nullptr;
			}
			else if (Video::get() >= 0 || user_input != nullptr) {
				m_equipment = new char[strlen(user_input) + 1];
				strcpy(m_equipment, user_input);
			}
		}
			
		
		
	}

	ostream& VRVideo::play(ostream& ostr)const {
		if (m_equipment != nullptr) {
			ostr << "VRVideo requires ";
			ostr << m_equipment << endl;
			ostr << "Video Length = ";
			ostr << Video::get();
			
		}
		return ostr;
		
	}


}