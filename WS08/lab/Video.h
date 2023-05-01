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



#ifndef SDDS_VIDEO_H
#define SDDS_VIDEO_H
#include <iostream>
#include "Media.h"


namespace sdds {
	class Video :public Media {
	private:
		int m_length = 0;
	public:

		virtual void load(istream& istr);
		Video();
		Video(int temp_length);
		Video(const Video&) = delete;
		Video& operator=(const Video&) = delete;
		virtual ostream& play(ostream& ostr)const = 0;

	protected:
		int get()const;

	};


}

#endif