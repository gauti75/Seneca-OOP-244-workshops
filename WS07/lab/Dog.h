#ifndef SDDS_DOG_H
#define SDDS_DOG_H

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
#include <iostream>
#include "Pet.h"

namespace sdds {
	class Dog :public Pet {
		const double COST_BASE = 4.00;		// Fee: Initial purchase
		const double COST_FEED = 0.25;		// Fee: For each feeding
		const double COST_REVIVE = 1.00;		// Fee: Respawn if perished

		
	public:
		int m_numWalks;
		Dog(const char* d_name, int f_age = 0);
		void operator++ (int num);
		Dog& operator=(const Dog& dog);
		void feed();
		void walk();
		void reSpawn();
		void set_Empty();
	};
	std::ostream& operator<<(std::ostream& os, Dog& dog);


}

#endif