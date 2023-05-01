/*
*****************************************************************************
				  Workshop 3 (Part 2)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 05 Feburary 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include<string.h>
#include "Store.h"
using namespace std;

namespace sdds {
	
	/*
	After checking the validity, this method will set the received values to the appropriate 
	data members. 
	Otherwise will be set to an empty state.
	*/
	
	void Toys::addToys(const char* tname, int sku, double price, int age) {
		if (tname == nullptr) {
			m_tname[0] = '\0';
			m_sku = 0;
			m_price = 0;
			m_age = 0;

		}
		else {
			strcpy(m_tname, tname);
			m_sku = sku;
			m_price = price;
			m_age = age;
		}

	}



	void Toys::isSale(bool sale) {
		sale = m_onSale;

	}


	void Toys::calSale() {
		double decreased_price = (20 * m_price) / 100;
		m_price = m_price - decreased_price;

	}

	void Toys::setName(const char* name) {
		if (name != nullptr) {
			strcpy(m_tname, name);
		}
		else if (name == nullptr) {
			m_tname[0] = '\0';
		}
		
	}

	void Toys::display()const {
		
		
		
		
		if (strlen(m_tname)!=0 && (m_sku > 9999999 && m_sku < 100000000)) {
			cout << left << " :" << setfill(' ') << setw(17) << m_tname << setw(12) << m_sku;
			cout  << right <<setw(2)<<m_age << setw(12) << m_price;

			
			if (m_onSale == true) {
				cout << setw(11) << "On Sale ";
			}
			else {
				cout << setfill(' ') << setw(8) << "";
			}
			
		}
		else {
			cout << " :Invalid Toy";
		}


		
		
		

		


		
			
			

		
		
		
	}




}




