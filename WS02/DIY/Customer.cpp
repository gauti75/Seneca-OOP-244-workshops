/*
*****************************************************************************
                  Workshop 2 (Part 2)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 28 January 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

    // complete
    Customers c_rec;

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }

    
    // complete
    
    // Making EmptyRecord overload function to intialize all the data members to zero of all the strcutre Customers and CustomersRecord
    void EmptyRecord(Customers& records) {
        // using for loop to set the user_name to zero using by setting its first chacter to zero.
        for (int i = 0; i < 21; i++) {
            records.user_name[i] = '\0';
        }
        // we could also use above the memset function i.e. memset(records.user_name, 0, sizeof(records_user_name));
        records.retweets_count = 0;
        records.likes_count = 0;
        records.replies_count = 0;
        records.share_videos = '\0';
    }

    void EmptyRecord(CustomersRecord& d_records) {
        d_records.ptr_rec = nullptr;
        d_records.noOfRecords = 0;
    }

    // read funcion which would return true or false value if the user name is entered correctly or not respectively.
    // If its enetered then it will prompt the user to ask the other details of the data members from the Customer strcuture

    bool read(Customers& rec) {
        bool check = false;
        cout << " Enter User name: ";
        read(rec.user_name, 21);
        if (rec.user_name[0] == '\0') {
            check = false;
        }
        else {


            cout << " Enter likes_count: ";
            cin >> rec.likes_count;
            cout << " Enter retweets_count: ";
            cin >> rec.retweets_count;
            cout << " Enter replies_count: ";
            cin >> rec.replies_count;
            cout << " Enter share videos (y/n): ";
            cin >> rec.share_videos;
            
            check = true;
        }
        return check;
    }

    

    /*
    int loadData(Customers& user) {
        bool check = false;
        if(read(user)) {
            check = true;
        }
        return check;

    }
    
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {


        t_rec.ptr_rec = new Customers[t_rec.noOfRecords + 1];

        int i = 0;
        for (i = 0; i < t_rec.noOfRecords; i++) {

            loadData(t_rec.ptr_rec[i]);
        }
        t_rec.noOfRecords++;

    }
    */



    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {


        Customers* temp_record = new Customers[t_rec.noOfRecords + 1];

        int j = 0;
        for (j = 0; j < t_rec.noOfRecords; j++) {
            temp_record[j] = t_rec.ptr_rec[j];
        }
        temp_record[t_rec.noOfRecords] = c_rec;


        delete[] t_rec.ptr_rec;

        t_rec.noOfRecords++;
        t_rec.ptr_rec = temp_record;

    }
   
    // Display overload functions to display the data.

    void display(const Customers& c_rec) {
        cout << c_rec.user_name << ", " << c_rec.likes_count << ", " << c_rec.retweets_count << ", " << c_rec.replies_count << ", " << c_rec.share_videos << endl;
        cout << endl;
    }

    void display(const CustomersRecord& t_rec) {
        for (int i = 1; i < t_rec.noOfRecords+1; i++) {
            cout << i << ". ";
            display(t_rec.ptr_rec[i-1]);
        }
    }

  }

