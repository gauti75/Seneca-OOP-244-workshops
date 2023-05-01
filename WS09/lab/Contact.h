#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H

#include <iostream>
#include "Person.h"

namespace sdds {

	class Contact:public Person {
	public:
		char* address{};
		char* city{};
		char province[2];
		char postal[6];
	//public:
		void setEmpty();
		Contact();
		Contact(const Contact& copyFrom);
		Contact& operator=(const Contact& RightOperand);
		virtual std::istream& read(std::istream& istr);

		virtual void operator~();
		virtual operator bool()const;
		virtual std::ostream& write(std::ostream& ostr)const;

		virtual ~Contact();
	
	};

}

#endif