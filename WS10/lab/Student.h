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
// File	Student.h
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
#ifndef SICT_STUDENT_H_
#define SICT_STUDENT_H_
#include "Displayable.h"
namespace sict{

  class Student :public Displayable{
    int _stno;
    char _name[41];
    void set(int stno, const char* name);
  public:
    Student(int stno, const char* name = "no name");
    Student(const Student& S) = delete;
    Student& operator=(const Student& S) = delete;
    std::ostream& display(std::ostream& os)const;
    bool operator<=(const Student& S)const;
    bool operator>=(const Student& S)const;
    operator const char*()const;
  };
}
#endif 