/*
*****************************************************************************
                  Workshop 6 (Part 1)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 08 March 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>


namespace sdds {
   class Numbers {
       double* collection=nullptr;
       char filename[256];
       int collection_size=0;
       bool original_flag = false;
       bool added_flag = false;;
       
      unsigned int countLines(const char* filename);
      
      bool load();
      void save();
      double max() const;
      double min() const;
      double average() const;
      
     
   public:
       Numbers(const char* user_file);
       Numbers();
       Numbers(const Numbers& source);
       void setEmpty();
       Numbers& operator=(const Numbers& source);
       operator bool()const;
       void sort();
       Numbers& operator+=(double value);
       std::ostream& display(std::ostream& ostr) const;
       
       
       
       ~Numbers();
   };
   std::istream& operator>>(std::istream& istr, Numbers& N);
   std::ostream& operator<<(std::ostream& os, const Numbers& N);


}
#endif // !SDDS_NUMBERS_H_





