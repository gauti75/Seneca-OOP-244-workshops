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



#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H
#include <iostream>
using namespace std;


namespace sdds {
	class Media {
	public:
		virtual void load(istream& istr) = 0;
		virtual ostream& play(ostream& ostr)const = 0;
		virtual ~Media() {};
	};
	std::ostream& operator<<(std::ostream& ostr, const Media& media);
	std::istream& operator>>(std::istream& istr, Media& media);

}

#endif