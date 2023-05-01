/*
*****************************************************************************
				  Workshop 4 (Part 2)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 15 Feburary 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/




#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_



namespace sdds {


	class NameTag {

		char* name;
		int number;
		bool validity;

	public:
		void setName(const char* fullname);
		void setExtenstion(int extenstion);
		void setEmpty();
		NameTag();
		NameTag(const char* fullname);
		NameTag(const char* fullname, int extenstion);

		NameTag& read();
		void print();

		~NameTag();



	};





}

#endif