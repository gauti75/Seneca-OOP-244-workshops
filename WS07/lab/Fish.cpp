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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Fish.h"

using namespace std;

namespace sdds {


	void Fish::set_Empty() {
		Pet();
	}

	Fish::Fish(const char* f_name, int f_age) :Pet(f_name, f_age, COST_BASE) {

	}

	void Fish::feed() {
		Pet::feed();
		if (isAlive()) {
			addCharge(COST_FEED);
		}
	}


	void Fish::reSpawn() {
		Pet::reSpawn();
		addCharge(COST_REVIVE);
	}
	 


	void Fish::operator++(int num) {
		double healthDelta = 0;
		if (isAlive()) {
			
			healthDelta += 0.20 * (getFeeds() - 1);
			applyHealthDelta(healthDelta);
			Pet::operator++(num);
		}
		set_Empty();
		
	}

	Fish& Fish::operator=(const Fish& U_fish) {
		Pet::operator=(U_fish);
		addCharge(COST_BASE + (2 * COST_BASE));
		
		
		return *this;
	}

	ostream& operator<<(ostream& os, Fish& fish) {
		os << "** Generic Fish **" << endl;
		return fish.outputData(os);
	}

}