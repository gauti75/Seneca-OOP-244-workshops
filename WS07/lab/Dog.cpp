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
#include "Dog.h"


using namespace std;

namespace sdds {

	void Dog::set_Empty(){
		Pet();
		m_numWalks = 0;
	}

	Dog::Dog(const char* d_name, int d_age) :Pet(d_name, d_age, COST_BASE) {
		m_numWalks = 0;

	}

	void Dog::operator++ (int num) {
		double healthDelta = 0;
		if (isAlive()) {
			healthDelta += 0.15 * (getHugs() - 1);
			healthDelta += 0.10 * (getFeeds() - 2);   
			healthDelta += 0.10 * (getGrooms() - 1);
			healthDelta += 0.20 * (m_numWalks - 2);
			applyHealthDelta(healthDelta);
			Pet::operator++(num);
		}
		set_Empty();
		
		
	}


	Dog& Dog::operator=(const Dog& U_dog) {
		//set_Empty();
		Pet::operator=(U_dog);
		
		addCharge((2 * COST_BASE));

		m_numWalks = U_dog.m_numWalks;
		
		
		
			
		
		
		return *this;
	}

	ostream& operator<<(ostream& os, Dog& dog) {
		
		os << "** Generic Dog **" << endl;
		os << "   Walks: " << dog.m_numWalks<<endl;
		
		return dog.outputData(os);
	}

	void Dog::feed() {
		Pet::feed();
		if (isAlive()) {
			addCharge(COST_FEED);
		}

	}

	void Dog::walk() {
		if (isAlive()) {
			m_numWalks++;
		}
	}

	void Dog::reSpawn() {
		Pet::reSpawn();
		addCharge(COST_REVIVE);
		m_numWalks = 0;
		
	}



}
