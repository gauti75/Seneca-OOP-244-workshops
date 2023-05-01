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


#ifndef SDDS_VRVIDEO_H
#define SDDS_VRVIDEO_H
#include <iostream>
#include "Video.h"


namespace sdds {

	class VRVideo :public Video {
	private:
		char* m_equipment = nullptr;
	public:
		VRVideo();
		VRVideo(int length, const char* equipment);
		virtual void load(istream& istr);
		virtual ostream& play(ostream& ostr)const;
		~VRVideo();

	};


}

#endif