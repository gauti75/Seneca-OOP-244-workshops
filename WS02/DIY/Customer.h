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


#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_

namespace sdds {

    struct Customers {
        char user_name[21];
        int retweets_count;;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets' report.
        int noOfRecords;
    };
    
       
    void read(char* str, int len);
   
    // to be completed

    
    void EmptyRecord(Customers& records );

    void EmptyRecord(CustomersRecord& d_records);

    bool read(Customers& rec);

   

  

    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec);

    void display(const Customers& c_rec);

    void display(const CustomersRecord& t_rec);

    





              
}

#endif 
