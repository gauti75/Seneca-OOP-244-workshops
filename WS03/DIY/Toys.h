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

#ifndef SDDS_TOYS_H_
#define SDDS_TOYS_H_

#define MAX_TNAME 31

namespace sdds {

	
	class Toys {
	public:
		char m_tname[MAX_TNAME+1];// toy name, up to MAX_TNAME size
		int m_sku; //SKU number, maximum 8 digits long
		double m_price;//toy price
		int m_age;//toy according to age group
		bool m_onSale;// keep track, if toys are on sale or not
		void setName(const char* name);

		void addToys(const char* tname, int sku, double price, int age);
		void isSale(bool sale);
		void calSale();
		void display()const;
		
	};

	


}
#endif