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



#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <string>
#include <iomanip>
#include "Bus.h"

using namespace std;

namespace sdds {

	Bus::Bus(int temp_seats, int temp_passengers) {
		if (temp_seats % 2 != 0 || temp_seats < 10 || temp_seats>40 || temp_passengers<0 || temp_passengers>temp_seats) {
			num_seats = -1;
			num_passengers = -1;
		}
		else {
			this->num_seats=temp_seats;
			this->num_passengers= temp_passengers;
			
		}

	}
	

	Bus::operator bool()const {
		return num_seats > 0 &&num_seats%2==0;


	}
	
	void Bus::drawBus(int seats, int noOfPassengers, ostream& ostr) const {
		int i, p;
		ostr.fill('_');
		ostr.width((seats / 2) * 3 + 4);
		ostr << "_";
		ostr << endl << "| ";
		for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
		ostr << "|_\\_" << endl;
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(((seats / 2) * 3 - 14) / 2);
		ostr << " " << "Seneca College";
		ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
		ostr << " " << "    )" << endl;
		ostr << "`---OO";
		ostr.fill('-');
		ostr.width((seats / 2) * 3 - 5);
		ostr << "-" << "O---'" << endl;
	}

	ostream& Bus::display(ostream& ostr = cout) const {
		
		if (*this) {
			drawBus(num_seats,num_passengers,ostr);
			ostr << "Total Fare Price: " << setprecision(2) << fixed << num_passengers * Price_Ticket << endl;
		}
		else {
			ostr <<"Out of service!"<< endl;
		}
		return ostr;

	}
	
	istream& Bus::read(istream& istr) {
		int t_seats;
		int t_pass;

		istr >> t_seats;
		istr.ignore(1, ' ');

		istr >> t_pass;

		if (t_seats % 2 != 0 || t_seats < 10 || t_seats>40 || t_pass<0 || t_pass>t_seats) {
			num_seats = -1;
			num_passengers = -1;
		}

		else {
			num_seats = t_seats;
			num_passengers = t_pass;
			
		}

		return istr;
	}

	Bus::operator int()const {
		if (!*this) {
			return -1;
		}
		else {
			return num_passengers;
		}
	}

	Bus::operator double()const {
		

		if (!(*this)) {
			return -1;
		}
		return num_passengers * Price_Ticket;


	}

	bool Bus::operator++() {
		if (!( * this) || num_passengers == 40 ||num_passengers ==10) {
			return false;
		}
		else {

			num_passengers+=1;
			return true;
		}
		
	}

	bool Bus::operator--() {
		if (!( * this) || num_passengers == 0) {
			return false;
		}
		else {

			num_passengers-=1;
			return true;
		}

	}

	bool Bus::operator--(int) {
		return operator--();
	}

	bool Bus::operator++(int) {
		return operator++();
	}

	Bus& Bus::operator=(int passengers) {
		if (passengers > num_seats) {
			num_passengers = -1;
			num_seats = -1;

		}
		else {
			num_passengers = passengers;
			
		}
		return *this;

	}

	Bus& Bus::operator+=(int passengers) {
		if (*this) {
			num_passengers += passengers;

		}
		else if(num_passengers>num_seats) {
			num_passengers = -1;
			num_seats = -1;
			

		}
		return *this;

	}

	
	Bus& Bus::operator+=(Bus& right) {
		int empty_seats = this->num_seats - this->num_passengers;
		if (*this) {
			if (empty_seats != 0 && empty_seats <= right.num_passengers) {
				this->num_passengers = this->num_passengers + empty_seats;
				right.num_passengers = right.num_passengers - empty_seats;
			}
			else {
				this->num_passengers = this->num_passengers;
			}
			

		}
		return *this;
		
	}
	


	bool Bus::operator==(Bus& right) {
		if (*this && (this->num_passengers == right.num_passengers)) {
			return true;
		}
		else {
			return false;
		}

	}

	int operator+(int value, const Bus& right) {
		if (right.num_seats % 2 != 0 || right.num_seats < 10 || right.num_seats>40 || right.num_passengers<0 || right.num_passengers>right.num_seats) {
			return value;
			
		}
		else {
			
			return value + right.num_passengers;

		}


	}

	ostream& operator<<(ostream& ostr, const Bus& right) {
		right.display();
		return ostr;

	}

	istream& operator>>(istream& istr, Bus& right) {
		right.read();
		return istr;

	}





		




	

}

