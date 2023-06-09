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





/***********************************************************************
// OOP244 Workshop 4 Part2: Constructor, Destructor and the current object
// File main.cpp
// Version 1.0
// Date	2023/01
// Author Fardad Soleimanloo
// Description
// Tests NameTag module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
using namespace std;
#include "NameTag.h"
using namespace sdds;
int main() {
   NameTag nt[6] = {  
      "A very very very long name to be cut short!!!", // one argument constructor
      {"Fred Soley", 12345} ,       // two argument constructor with good data
      {nullptr, 23456},    // two argument constructor with bad name
      {"Bad number", 1234},  // two argument constructor with bad number
      {"Bad number", 123456}  // two argument constructor with bad number
                             // default constructor (sixth element)
   };
   int i;
   for (i = 0; i < 6; i++) {
      nt[i].print();
      cout << endl;
   }
   nt[1].read().print();
   nt[3].read().print();
   nt[5].read().print();
   return 0;
}


/*

+------------------------------------------+
|                                          |
| A very very very long name to be cut sho |
|                                          |
| Extension: N/A                           |
|                                          |
+------------------------------------------+

+----------------------+
|                      |
| Fred Soley           |
|                      |
| Extension: 12345     |
|                      |
+----------------------+

EMPTY NAMETAG!

EMPTY NAMETAG!

EMPTY NAMETAG!

EMPTY NAMETAG!

Please enter the name: Hubert Blaine Wolfeschlegelsteinhausenbergerdorff
Would you like to enter an extension? (Y)es/(N)o: x
Only (Y) or (N) are acceptable, try agin: n
+------------------------------------------+
|                                          |
| Hubert Blaine Wolfeschlegelsteinhausenbe |
|                                          |
| Extension: N/A                           |
|                                          |
+------------------------------------------+
Please enter the name: Lisa Simpson
Would you like to enter an extension? (Y)es/(N)o: Y
Please enter a 5 digit phone extension: five
Bad integer value, try again: 9999
Invalid value [10000<=value<=99999]: 100000
Invalid value [10000<=value<=99999]: 12345
+----------------------+
|                      |
| Lisa Simpson         |
|                      |
| Extension: 12345     |
|                      |
+----------------------+
Please enter the name: Bart Simpson
Would you like to enter an extension? (Y)es/(N)o: y
Please enter a 5 digit phone extension: 11111
+----------------------+
|                      |
| Bart Simpson         |
|                      |
| Extension: 11111     |
|                      |
+----------------------+









*/