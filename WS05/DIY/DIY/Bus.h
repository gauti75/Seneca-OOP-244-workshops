/*
*****************************************************************************
				  Workshop 5 (Part 2)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 22 Feburary 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/



#ifndef SDDS_BUS_H_
#define SDDS_BUS_H_

#include<iostream>

using namespace std;
#define Price_Ticket 125.34

namespace sdds {

	class Bus {
		int num_seats =20;
		int num_passengers = 0;
		void drawBus(int seats, int noOfPassengers, ostream& ostr) const;
	
	public:
		operator bool()const;
		
		Bus(int temp_seats=20, int temp_passengers=0);
		ostream& display(ostream& ostr) const;
		istream& read(istream& istr = cin);
		operator int()const;
		operator double()const;
		bool operator --();
		bool operator ++();
		bool operator++(int);
		bool operator--(int);
		Bus& operator=(int passengers);
		Bus& operator+=(int passengers);
		Bus& operator+=(Bus& right);
		bool operator==(Bus& right);
		friend int operator+(int value, const Bus& right);
		friend ostream& operator<<(ostream& ostr, const Bus& right);//
		friend istream& operator>>(istream& istr, Bus& right);//


	};
	


}

#endif