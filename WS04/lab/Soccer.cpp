#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include<string.h>
#include <cstring>
#include<ostream>
#include "Soccer.h"
#include "Tournament.h"

using namespace std;

namespace sdds {

	void SoccerTeam::setTeam(const SoccerTeam& team) {
		setName(team.m_teamName);
		setFine(team.m_fines, team.m_noFouls);

	}

	// If the received name pointer is valid and not null it will copy the received name 
	// to the data member m_teamName
	void SoccerTeam::setName(const char* tname) {
		if (tname != nullptr) {
			strcpy(m_teamName, tname);
		}

	}

	void SoccerTeam::setFine(double fines, int foul) {
		if (fines >= 0 && foul >= 0) {
			m_fines = fines;
			m_noFouls = foul;


		}
		else {
			setEmpty();
		}

	}

	void SoccerTeam::setEmpty() {
		for (int i = 0; i < 41; i++) {
			m_teamName[i] = '\0';
		}
		m_noFouls = -1;
		m_fines = -1;
		m_golas = 0;


	}

	bool SoccerTeam::isEmpty() const {
		bool check = false;
		if (m_teamName[0] != '\0' && m_fines >= 0 && m_noFouls >= 0) {
			check = true;
			return check;
		}
		return check;
	}

	void SoccerTeam::calFines() {
		m_fines += 0.2 * m_fines;
	}

	int SoccerTeam::fouls() const {
		return m_noFouls;

	}

	SoccerTeam::SoccerTeam() {
		setEmpty();
	}

	SoccerTeam::SoccerTeam(const char* tname, double fines, int foul) {
		
			setName(tname);
			setFine(fines, foul);
			m_golas = 0;
		
		



	}

	std::ostream& SoccerTeam::display() const {
		if (isEmpty()) {
			cout.fill(' ');
			cout.width(30);
			cout <<left<< m_teamName;

			cout.width(6);
			cout << setprecision(2) << fixed<<right<< m_fines;

			cout.width(6);
			cout << right<<m_noFouls;
			
			if (m_golas == 0) {
				cout.width(10);
				cout << right << m_golas << ' '<<endl;


			}
			else if(m_golas>0) {
				cout.width(10);
				cout<<right<< m_golas << "w" << endl;
			}

		}
		else if(!isEmpty()) {
			cout << "Invalid Team";

		}

		return std::cout;



	}

}

