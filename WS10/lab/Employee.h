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
// File	Employee.h
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
#ifndef SICT_EMPLOYEE_H_
#define SICT_EMPLOYEE_H_
#include "Displayable.h"
namespace sict{
  class Employee :public Displayable{
    int _empno;
    char _name[41];
    double _salary;
    void set(int stno, const char* name, double salary);
  public:
    Employee(int stno, const char* name = "no name", double salary = 0.0);
    std::ostream& display(std::ostream& os)const;
    bool operator<=(const Employee& E)const;
    bool operator>=(const Employee& E)const;
    operator const char*()const;
  };



}
#endif 