#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include<string.h>
#include <cstring>
#include<ostream>
#include "Tournament.h"



using namespace std;

namespace sdds {

	void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
		if (name != nullptr && noOfteam > 0 && strlen(name) > 0) {
			m_num = noOfteam;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_soccer = new SoccerTeam[m_num + 1];
			for (int i = 0; i < m_num; i++) {
				m_soccer[i] = soccer[i];
			}
		}
		else {
			setEmpty();
		}





	}

	void Tournament::setEmpty() {
		m_name = nullptr;
		m_soccer = nullptr;
		m_num = 0;

	}

	bool Tournament::isEmpty() const {
		bool check = false;
		if (m_name != nullptr && m_soccer != nullptr && m_num >= 0) {
			check = true;
			return check;

		}
		return check;
	}

	Tournament& Tournament::match(const SoccerTeam* ls) {
		
		for (int i = 0; i < m_num; i++) {
			
			if (m_soccer[i].m_noFouls < m_soccer[i + 1].m_noFouls) {
				m_soccer[i + 1].m_noFouls *= 2;
				m_soccer[i + 1].calFines();
				m_soccer[i].m_golas += 1;

			}
			if (m_soccer[i + 1].m_noFouls > MAX_FOUL) {
				m_soccer[i + 1].m_noFouls = -1;

			}
			

		}
		return *this;

	}

	std::ostream& Tournament::display() const {
		if (isEmpty() == true) {
			cout << "Tournament name: " << m_name << endl;
			cout << "list of the teams" << endl;


			cout.fill(' ');
			cout.width(45);
			cout << right << "Fines";

			cout.fill(' ');
			cout.width(10);
			cout << "Fouls";
			cout.fill(' ');
			cout.width(10);
			cout << "Goals";
			cout << endl;
			for (int i = 0; i < m_num; i++) {
				cout << "Team[" << i + 1 << "] :";
				m_soccer[i].display();

			}





		}
		else {
			cout << "Invalid Tournament";

		}
		return std::cout;

	}

	Tournament::Tournament() {
		setEmpty();

	}

	Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
		setTournament(name, noOfteam, soccer);

	}

	Tournament::~Tournament() {

		
		delete[] m_soccer;
		m_soccer = nullptr;


		delete[] m_name;
		m_name = nullptr;

	}

}
