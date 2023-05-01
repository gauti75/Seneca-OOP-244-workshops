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
// File	Displayable.cpp
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
#include "Displayable.h"
namespace sict{
  std::ostream& operator<<(std::ostream& os, const Displayable& D){
    return D.display(os);
  }
}