/*
*****************************************************************************
				  Workshop 3 (Part 2)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 05 Feburary 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/


/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File main.cpp
// Version 1.0
// Date	2022/10/28
// Author Nargis Khan
// Description
// Tests Store module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include<iostream>
#include<cstring>
#include"Store.h"
using namespace std;
using namespace sdds;

int main() {

	Store s;
	cout << "Printing invalid list of Toys" << endl;
	s.setStore("****Children`s Dream store****", 2);
	s.setToys(nullptr, 20304576,12.50,2); //SKU should be 8 digit, price and age
	s.setToys("Car",203045,11.50,12);
	s.display();
	

	cout << endl << "Printing valid list of Toys" << endl;
	s.setStore("****Children`s Dream store****", 6);
	s.setToys("Racing Car",11223344, 40.99, 8);
	s.setToys("Teddy Bear", 33772346,25.99, 6); //onsale
	s.setToys("Airplane", 44453466,60.99,16);
	s.setToys("Doll", 55887896,45.99, 5);
	s.setToys("Drone", 99221388, 90.99, 18);//onsale
	s.setToys("Lego", 88224596, 65.99, 10);//onsale
	s.display();

	cout << endl << "Searching for toys and printing the list with sale price" << endl;
	s.find(33772346);//Teddy Bear
	s.find(99221388);//drone
	s.find(88224596); //lego
	s.display();
	
}


/*
Printing invalid list of Toys
************************************************************
****Children`s Dream store****
************************************************************
list of the toys
						   SKU       Age      Price      Sale
Toy[1] :Invalid Toy
Toy[2] :Invalid Toy

Printing valid list of Toys
************************************************************
****Children`s Dream store****
************************************************************
list of the toys
						   SKU       Age      Price      Sale
Toy[1] :Racing Car       11223344     8       40.99
Toy[2] :Teddy Bear       33772346     6       25.99
Toy[3] :Airplane         44453466    16       60.99
Toy[4] :Doll             55887896     5       45.99
Toy[5] :Drone            99221388    18       90.99
Toy[6] :Lego             88224596    10       65.99

Searching for toys and printing the list with sale price
************************************************************
****Children`s Dream store****
************************************************************
list of the toys
						   SKU       Age      Price      Sale
Toy[1] :Racing Car       11223344     8       40.99
Toy[2] :Teddy Bear       33772346     6       20.79   On Sale
Toy[3] :Airplane         44453466    16       60.99
Toy[4] :Doll             55887896     5       45.99
Toy[5] :Drone            99221388    18       72.79   On Sale
Toy[6] :Lego             88224596    10       52.79   On Sale

*/