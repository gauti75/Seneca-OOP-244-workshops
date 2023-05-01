/*
*****************************************************************************
Workshop 5 (Part 1)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 19 Feburary 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

* ****************************************************************************
*/




#ifndef SDDS_EGGCARTON_H_
#define SDDS_EGGCARTON_H_

#include<iostream>
using namespace std;

const int RegularEggWieght = 50;
const int JumboEggWieght = 75;


namespace sdds {

	class EggCarton {
		int m_size=6;
		int m_numeggs=0;
		bool type_jumbo=false;
		void setBroken();
		
		ostream& displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const;

	public:
		
		EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
		ostream& display(ostream& ostr) const;
		operator bool() const;
		istream& read(istream& istr);
		operator int() const;
		operator double() const;
		EggCarton& operator--();
		EggCarton& operator++();
		EggCarton operator--(int);
		EggCarton operator++(int);
		EggCarton& operator=(int value);
		/*EggCarton& operator=(EggCarton& right)
		{

			return right;
		}*/
		EggCarton& operator+=(int value);
		EggCarton& operator+=(EggCarton& right);
		bool operator==(const EggCarton& right) const;//
		////
		friend int operator+(int left, const EggCarton& right);
		friend ostream& operator<<(ostream& ostr, const EggCarton& right);//
		friend istream& operator>>(istream& istr, EggCarton& right);//
	};


	



}

#endif