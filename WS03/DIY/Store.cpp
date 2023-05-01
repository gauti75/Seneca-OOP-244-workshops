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
#include <cstring>
#include "Store.h"

#include <iomanip>


using namespace std;

namespace sdds {

	
	
	
	
	void Store::setStore(const char* sName, int no) {
		if (sName != nullptr) {
			strcpy(m_sName,sName);
		}
		else if (sName == nullptr) {
			m_sName[0] = '\0';
		}
		m_noOfToys = (no > 0 && no <= MAX_NUM_TOYS) ? no : 0;
		m_addToys = 0;
		
	}

	//This will add the toys one at a time to the m_toy array and will keep track of the number of toys added. 
	// Toys will be added until num of added toys is less than m_noOfToys
	/*
	void Store::setToys(const char* tname, int sku, double price, int age) {
		for (int i = 0; i < m_noOfToys; i++) {
			
			//strcpy(m_toy[i].m_tname, tname);
			m_toy[i].m_sku = sku;
			m_toy[i].m_price = price;
			m_toy[i].m_age = age;

		}

	}
	
	void Store::setStore(const char* sName, int no) {
		strncpy(m_sName, sName, MAX_SNAME - 1);
		m_sName[MAX_SNAME - 1] = '\0';
		m_noOfToys = (no > 0 && no <= MAX_NUM_TOYS) ? no : 0;
		m_addToys = 0;
	}
	*/

	//This will add the toys one at a time to the m_toy array and will keep track of the number
	//  of toys added. 
	// Toys will be added until num of added toys is less than m_noOfToys


	

	void Store::setToys(const char* tName, int sku, double price, int age) {

		if (m_addToys < m_noOfToys) {
			m_toy[m_addToys].setName(tName);
			m_toy[m_addToys].m_sku = sku;
			m_toy[m_addToys].m_price = price;
			m_toy[m_addToys].m_age = age;
			m_addToys++;

		}

		
			

			//strcpy(m_toy[m_noOfToys].m_tname[MAX_TNAME + 1], tName);
			
			
		
	}

	void Store::display()const {

		if (m_sName[0] != '\0') {
			cout << setfill('*') << setw(60) << "" << endl;
			cout << m_sName << endl;
			cout << setfill('*') << setw(60) << "" << endl;
			cout << "list of the toys" << endl;
			cout << setfill(' ') << setw(27) << "" << "SKU";
			cout << setfill(' ') << setw(7) << "" << "Age";
			cout << setfill(' ') << setw(6)<<setprecision(2) <<fixed<< "" << "Price";
			cout << setfill(' ') << setw(6) << "" << "Sale";
			cout << endl;
			for (int i = 1; i < m_noOfToys+1; i++) {
				cout << "Toy" << "[" << i << "]";
				m_toy[i-1].display();
				cout << "\n";
				
			}

		}
		else {
			cout << "Invalid Store" << endl;
		}
		
		


	}

	void Store::find(int sku) {
		for (int i = 0; i < m_noOfToys; i++) {
			if (sku == m_toy[i].m_sku) {
				m_toy[i].m_onSale = true;
				m_toy[i].calSale();
			}
			

		}
	}

	void Store::setEmpty() {
		m_sName[0] = '\0';
		m_noOfToys = 0;
		m_addToys = 0;
		
	}
	

}



