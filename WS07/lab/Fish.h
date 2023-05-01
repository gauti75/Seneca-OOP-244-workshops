/*
*****************************************************************************
				  Workshop 7 (Part 1)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 17 March 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/

#ifndef SDDS_FISH_H
#define SDDS_FISH_H

#include <iostream>
#include "Pet.h"

namespace sdds {

	class Fish :public Pet {
		const double COST_BASE = 2.00;		// Fee: Initial purchase
		const double COST_FEED = 0.10;		// Fee: For each feeding
		const double COST_REVIVE = 0.50;		// Fee: Respawn if perished
	public:

		Fish(const char* f_name, int f_age = 0);
		void feed();
		void set_Empty();
		void reSpawn();
		void operator++ (int num);
		Fish& operator=(const Fish& fish);

	};
	std::ostream& operator<<(std::ostream& os, Fish& fish);


}

#endif