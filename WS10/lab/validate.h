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

#ifndef SICT_VALIDATE_H
#define SICT_VALIDATE_H

namespace sict {
    template <typename V>
    bool validate(const V& minimum, const V* test, int number, bool* boolArray) {
        bool valid = true;
        for (int i = 0; i < number; i++) {
            if (test[i] >= minimum) {
                boolArray[i] = true;
                valid &= boolArray[i];
            }
            else if (test[i] <= minimum) {
                boolArray[i] = false;
                valid &= boolArray[i];
            }
           
            
        }
        return valid;
    }
}

#endif