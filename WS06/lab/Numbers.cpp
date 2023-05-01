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
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Numbers.h"
#include<cstring>
#include<string.h>
#include <iomanip>
using namespace std;
namespace sdds {
    

    unsigned int Numbers::countLines(const char* filename) { /**/
        unsigned int lines = 0u;
        ifstream nums(filename);
        while (nums) {
            lines += (nums.get() == '\n');
        }
        return lines;
    }

    Numbers::Numbers(const char* user_file) {
        collection = nullptr;
        strcpy(filename, user_file);
        collection_size = countLines(user_file);
        load();
    }

    Numbers::Numbers() {
        setEmpty();
    }

    void Numbers::setEmpty() {
        collection_size = 0;
        original_flag = false;
        added_flag = false;
        for (int i = 0; i < 256; i++) {
            filename[i] = '\0';
        }
        collection = nullptr;

    }


    
    bool Numbers::load() {
       
        int num_reads = 0;
       
       
        //unsigned int num_lines = countLines(filename);
        if (collection_size > 0) {
            collection = new double[collection_size];
            ifstream temp_file(filename);
            int i = 0;
            while (i<collection_size && temp_file >> collection[i]) {
                i++;
                num_reads++;
            }
            original_flag = true;
           
                
            
           
        }
        
        
        else {
            delete[] collection;
            collection = nullptr;
        }

        bool loaded = (num_reads == collection_size);
        if (!loaded) {
            delete[] collection;
            collection=nullptr;
        }

           
           

        return loaded;

    }
 

    void Numbers::save() {
        if (original_flag && added_flag) {
            ofstream temp_file(filename);
            
            for (int i = 0; i < collection_size; i++) {
                temp_file << fixed<<setprecision(2)<<collection[i] << endl;
            }
        }
    }

    

    Numbers::operator bool() const {
        if (collection == nullptr) {
            return false;
        }
        else {
            return true;
        }
    }

    Numbers::Numbers(const Numbers& source) {
        collection = nullptr;
        setEmpty();
        *this = source;
    }

    Numbers& Numbers::operator=(const Numbers& source) {
        
        if (collection != nullptr) {
            delete[] collection;
            collection = nullptr;
        }

        if (this != &source) {
            save();
            
            setEmpty();
            if (source) {
                original_flag = false;
                collection = new double[source.collection_size];
                

                for (int i = 0; i < source.collection_size; i++) {
                    collection[i] = source.collection[i];
                }
                collection_size = source.collection_size;
            }
        }
        return *this;
    }


    double Numbers::max() const{
        double max_num = 0;
        max_num = collection[0];
            for (int i = 1; i < collection_size; i++) {
                
                if (collection[i] > max_num) {
                    max_num = collection[i];
                }
            }
        
        
        return max_num;

    }

    double Numbers::min() const{
        double min_num = 0;
        min_num = collection[0];
        for (int i = 1; i < collection_size; i++) {

            if (collection[i] < min_num) {
                min_num = collection[i];
            }
        }
        return min_num;
    }

    double Numbers::average() const{
        double avg_sum = 0;
        for (int i = 0; i < collection_size; i++) {
            avg_sum = avg_sum+collection[i];
        }
        return avg_sum / collection_size;
    }

    void Numbers::sort() {
        int i, j;
        double temp;
        for (i = collection_size - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (collection[j] > collection[j + 1]) {
                    temp = collection[j];
                    collection[j] = collection[j + 1];
                    collection[j + 1] = temp;
                }
            }
        }
    }

    Numbers& Numbers::operator+=(double value) {
        if (*this) {
            double* temp=nullptr;
            
            temp = new double[collection_size+1];
            for (int i = 0; i < collection_size; i++) {
                temp[i] = collection[i];
            }
            temp[collection_size] = value;
            added_flag = true;
            if (collection != nullptr) {
                delete[] collection;
                collection = nullptr;

            }
            
            collection = temp;
            collection_size++;

        }
        return *this;
    }

  
    
    std::ostream& Numbers::display(std::ostream& ostr = std::cout) const {
        if (!(*this)) {
            ostr << "Empty list";

        }
        else if (*this) {
            ostr << fixed << setprecision(2);
            if (!original_flag) {
                ostr << "Copy of numbers.txt" << endl;
                
                for (int i = 0; i < collection_size; i++) {
                    if (i == collection_size - 1) {
                        ostr << collection[i];
                    }
                    else {
                        ostr << collection[i] << ", ";
                    }
                    
                }
                ostr << endl;
                ostr << setfill('-') << setw(76) << "" << endl;
                //Total of 99 number(s), Largest: 99.99, Smallest: 99.99, Average: 99.99
                ostr << "Total of " << collection_size << " number(s), " << "Largest: " << max() << ", " << "Smallest: " << min() << ", " << "Average: " << average() << endl;
                ostr << setfill('=') << setw(76) << "";
            }
            else if (original_flag) {
                ostr << filename << endl;
                for (int i = 0; i < collection_size; i++) {
                    if (i == collection_size - 1) {
                        ostr << collection[i];
                    }
                    else {
                        ostr << collection[i] << ", ";
                    }
                }
                ostr << endl;
                ostr << setfill('-') << setw(76) << "" << endl;
                //Total of 99 number(s), Largest: 99.99, Smallest: 99.99, Average: 99.99
                ostr << "Total of " << collection_size << " number(s), " << "Largest: " << max() << ", " << "Smallest: " << min() << ", " << "Average: " << average() << endl;
                ostr << setfill('=') << setw(76) << "";

            }
        }
        return ostr;
    }
    
    ostream& operator<<(ostream& ostr, const Numbers& right) {
       return right.display(ostr);
      
        
     

    }

    istream& operator>>(istream& istr, Numbers& right) {
        

        double temp_value;
        istr >> temp_value;
        if (istr.fail()) {
            right.setEmpty();
        }
        else {
            right += temp_value;
        }
        return istr;
    }

    Numbers::~Numbers() {
        save();
        if (collection != nullptr) {
            delete[] collection;
            collection = nullptr;
        }
        
    }



}

