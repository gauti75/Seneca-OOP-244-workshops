/*
*****************************************************************************
				  Workshop 5 (Part 1)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 19 Feburary 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/



#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <string>
#include "EggCarton.h"


using namespace std;

namespace sdds {


	
	EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize) {

		if (size % 6 != 0 || size < 6 || size > 36 || noOfEggs < 0 || noOfEggs > size) {
			setBroken();
		}
		else {
			this->m_size = size;
			this->m_numeggs = noOfEggs;
			this->type_jumbo = jumboSize;
		}
	}
	


	void EggCarton::setBroken() {

		m_size = -1;
		m_numeggs = -1;
	}
	ostream& EggCarton::display(ostream& ostr = cout) const {
		if (*this) {
			displayCarton(m_size, m_numeggs, type_jumbo, ostr);
		}
		else {
			ostr << "Broken Egg Carton!" << endl;
		}
		return ostr;

	}

	ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const {
		int cartonWidth = size == 6 ? 3 : 6;
		for (int i = 0; i < size; i++) {
			ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
			((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
		}
		return ostr;
	}

	
	EggCarton::operator bool() const {
		if (m_size > 0) {
			return true;
		}
		else {
			return false;
		}

	}
	
	istream& EggCarton::read(istream& istr = cin) {
		char jumbo_size;
		int carton_size, n_egg;
		
		
		istr >> jumbo_size;
		istr.ignore(1, ',');

		if (jumbo_size == 'j') {
			type_jumbo = true;
			
		}
		else {
			type_jumbo = false;
		}
		
		
		

		istr >> carton_size;
		
		istr.ignore(1, ',');

		istr >> n_egg;
		
		

		if (carton_size % 6 != 0 || carton_size < 6 || carton_size > 36 || n_egg < 0 || n_egg > carton_size) {
			setBroken();
		}
		else {
			m_size = carton_size;
			m_numeggs = n_egg;
		
		}
		return istr;


	}

	EggCarton::operator int() const{

		if (!(*this)) {
			return -1;

		}
		else {
			return m_numeggs;
		}
		

	}

	EggCarton::operator double() const {
		double total_weight = 0;

		if (!(*this)) {
			return -1;
		}
		
		else if (*this) {
			double eggWeight = type_jumbo ? JumboEggWieght : RegularEggWieght;
			total_weight += (m_numeggs * eggWeight) / 1000;


		}
		

		
		/*
		else if (*this) {


			if (type_jumbo) {
				total_weight += (JumboEggWieght * m_numeggs) / 1000;


			}
			else{
				total_weight += (RegularEggWieght * m_numeggs) / 1000;
			}
		}
		
		*/

		
		return total_weight;
	}
	EggCarton& EggCarton:: operator--() {
		if (*this&&m_numeggs>0) {
			m_numeggs--;
		}
		return *this;

	}

	EggCarton& EggCarton:: operator++() {
		if (*this) {
			m_numeggs += 1;
		}
		if (m_numeggs > m_size) {
			setBroken();
		}
		return *this;
	}

	EggCarton EggCarton:: operator--(int) {
		EggCarton temp_carton=*this;
		
		--* this;
		return temp_carton;
	}

	EggCarton EggCarton:: operator++(int) {
		EggCarton temp_carton=*this;
		++* this;
		
		return temp_carton;
	}
	EggCarton& EggCarton::operator=(int value) {
		m_numeggs = value;
		if (m_numeggs > m_size) {
			setBroken();
		}
		return *this;
	}
	EggCarton& EggCarton::operator+=(int value) {
		if (*this) {
			m_numeggs += value;
		}
		if (m_numeggs > m_size) {
			setBroken();
		}
		return *this;

	}
	
	EggCarton& EggCarton::operator+=(EggCarton& right) {
		int empty_spot = m_size - m_numeggs;

		//cout << empty_spot <<"das" << endl;
		if (*this) {
			if (empty_spot != 0) {

				right.m_numeggs = right.m_numeggs - empty_spot;
				m_numeggs = m_numeggs + empty_spot;
			}


		}
			

		return *this;
	}
	

	bool EggCarton::operator==(const EggCarton& right) const {
		double difference = double(*this) - double(right);
		if (difference > -0.001 && difference < 0.001) {
			return true;
		}
		else {
			return false;
		}

	}
	int operator+(int left, const EggCarton& right) {
		if (right.m_size > 0) {
			return left + right.m_numeggs;
		}
		else {
			return left;
		}

	}
	ostream& operator<<(ostream& ostr, const EggCarton& right) {
		right.display();
		return ostr;

	}
	istream& operator>>(istream& istr, EggCarton& right) {
		right.read();
		return istr;
	}
}

