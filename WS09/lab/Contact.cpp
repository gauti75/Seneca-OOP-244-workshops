#include <iostream>
#include "Contact.h"
#include "Tools.h"

#include <string>
#include<cstring>

using namespace std;


namespace sdds {


    Contact::Contact() {};



    Contact::Contact(const Contact& copyFrom) :Person(copyFrom) {
        operator=(copyFrom);
    }
    Contact& Contact::operator=(const Contact& RightOperand) {

        if (this != &RightOperand) {
            Person::operator=(RightOperand);
            delAlloCopy(address, RightOperand.address);
            delAlloCopy(city, RightOperand.city);
            //delAlloCopy(m_middleName, RightOperand.m_middleName);
            strCpy(province, RightOperand.province);
            strCpy(postal, RightOperand.postal);

        }
        return *this;



    }


    Contact::operator bool()const {
        return address, address[0], city, city[0];
    }


    std::istream& Contact::read(std::istream& istr) {
        
        Person::operator~();
        Person::read(istr);
      

        string user_province;
        string user_postal;
       
       
        address = dynRead(istr, ',');
      
       

        city = dynRead(istr, ',');
        //m_lastName = dynRead(istr);
        //istr.getline(province, 3, ',');
        //istr.getline(postal, 7, ',');
        getline(istr, user_province, ',');
        getline(istr, user_postal);

        
        strCpy(province, user_province.c_str());
        
        strCpy(postal, user_postal.c_str());

        if (istr.fail()) {
            setEmpty();
        };

        

        return istr;
    }

    void Contact::setEmpty() {
        address = nullptr;
        city = nullptr;
        province[0] = '\0';
        postal[0] = '\0';

    }

    void Contact::operator~() {
        delete[] address;
        delete[] city;
        // delete[] m_middleName;
        address = city = nullptr;
    }


    std::ostream& Contact::write(std::ostream& ostr)const{
       
        if (*this && strlen(province) <= 2 && strlen(postal) <= 6&&address[0]!='\0'&&city!=nullptr) {
            Person::write(ostr);
            ostr << endl;
            ostr << address << endl;
            ostr << city << " " << province << endl;
            ostr << postal;
        }
        else {
            ~*this;

        }
        return ostr;

    }



    Contact::~Contact() {
        ~*this;
    }

}








