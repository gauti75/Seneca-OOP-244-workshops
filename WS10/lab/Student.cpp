/*
*****************************************************************************
                  Workshop 10 (Part 1)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 5 April 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/
/***********************************************************************
// OOP244 Workshop 10:
// File	Student.cpp
// Version 1.0
// Date	Winter of 2023
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Data            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Student.h"
namespace sict{
  void Student::set(int stno, const char* name){
    _stno = stno;
    std::strcpy(_name, name);
  }
  Student::Student(int stno, const char* name){
    set(stno, name);
  }
  std::ostream& Student::display(std::ostream& os)const{
    return os << _stno << " " << _name;
  }
  bool Student::operator<=(const Student& S)const{
    return _stno <= S._stno;
  }
  bool Student::operator>=(const Student& S)const{
    return _stno >= S._stno;
  }
  Student::operator const char*()const{
    return _name;
  }

}
