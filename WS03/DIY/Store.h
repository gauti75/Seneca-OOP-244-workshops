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

#ifndef SDDS_STORE_H_
#define SDDS_STORE_H_
#include "Toys.h"

#define MAX_NUM_TOYS 10
#define MAX_SNAME 31

namespace sdds {


	class Store {
	public:
		char m_sName[MAX_SNAME+1];// Store name, up to MAX_SNAME size
		int m_noOfToys;//No of toys;
		int m_addToys;//no of toys added

		Toys m_toy[MAX_NUM_TOYS] = {};// statically array of toys with size MAX_NUM_TOYS

		void setStore(const char* sName, int no);
		void setToys(const char* tname, int sku, double price, int age);
		void display()const;
		void find(int sku);
		
		void setEmpty();

	};





}
#endif